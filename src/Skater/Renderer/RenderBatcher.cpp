//
// Created by connor on 12/30/25.
//

#include "Skater/Renderer/RenderBatcher.h"

#include <algorithm>

#include "glad/glad.h"
#include "Skater/Renderer/RenderCommand.h"

namespace Skater {
    RenderBatcher::RenderBatcher() {
        _batchItems = std::vector<RenderBatchItem>();
        _vao = VertexArray::Create();

        _vao->SetVertexBuffer(VertexBuffer::Create());
        _vao->SetIndexBuffer(IndexBuffer::Create());

        // Initial starting size of 256 batch items
        SetSize(256);
    }

    RenderBatcher::~RenderBatcher() {
        _batchItems.clear();
        delete _vao;
    }

    RenderBatchItem* RenderBatcher::GetNextBatchItem() {
        if (_batchItemIndex >= _batchItems.capacity()) {
            IncreaseSize();
        }

        // Once we've given away a batch item, we have to
        // assume it's queued to be drawn.
        return &_batchItems[_batchItemIndex++];
    }

    void RenderBatcher::DrawBatch() {
        // Start by sorting the elements we'll be drawing
        std::sort(_batchItems.begin(), _batchItems.begin() + _batchItemIndex, CompareItems);

        const auto itemsToDraw = _batchItemIndex;

        uint32_t batchSize = 0;
        const Texture* lastTexture = nullptr;

        // Iterate until we've drawn everything
        for (uint32_t itemIndex = 0; itemIndex < itemsToDraw; itemIndex++) {
            const auto item = _batchItems[itemIndex];

            // Mid-work flush if we hit max size or the texture changed
            if (item.ItemTexture != lastTexture || batchSize == MAX_BATCH_SIZE) {
                FlushVertexArray(0, batchSize * 4, lastTexture);

                lastTexture = item.ItemTexture;

                batchSize = 0;
            }

            _verts[batchSize * 4] = item.VertexTL;
            _verts[batchSize * 4 + 1] = item.VertexTR;
            _verts[batchSize * 4 + 2] = item.VertexBL;
            _verts[batchSize * 4 + 3] = item.VertexBR;
            batchSize += 1;
        }

        // Flush out anything remaining
        FlushVertexArray(0, batchSize * 4, lastTexture);

        // Reset batch item index, we've drawn this batch (effectively return everything to the pool)
        _batchItemIndex = 0;
    }

    void RenderBatcher::FlushVertexArray(const uint32_t start, const uint32_t end, const Texture* texture) const {
        if (start == end) {
            return;
        }
        const auto vertexCount = end - start;

        _vao->GetVertexBuffer()->SetData(_verts, sizeof(VertexPositionColorTexture) * vertexCount);

        glActiveTexture(GL_TEXTURE0);
        texture->Bind();

        // Each quad is 4 verts but 6 indices
        RenderCommand::DrawIndexed(_vao, vertexCount / 4 * 6);
    }

    void RenderBatcher::SetSize(const uint32_t numItems) {
        // Resize batch items vec to contain new batch items
        _batchItems.resize(numItems);

        // Buffer arrays either need to contain enough for all items, or as much as we'll put in the largest batch.
        const auto maxBatchItems = std::min(numItems, MAX_BATCH_SIZE);

        // Create new index array
        uint32_t indices[maxBatchItems * 6];
        for (auto i = 0; i < maxBatchItems; i++) {
            // Base offset in index array for this element
            const auto base = i * 6;
            // Triangle 1
            indices[base + 0] = i * 4;
            indices[base + 1] = i * 4 + 1;
            indices[base + 2] = i * 4 + 2;
            //  Triangle 2
            indices[base + 3] = i * 4 + 1;
            indices[base + 4] = i * 4 + 3;
            indices[base + 5] = i * 4 + 2;
        }
        // Upload new index buffer
        _vao->GetIndexBuffer()->SetData(indices, maxBatchItems * 6);

        delete _verts;
        _verts = new VertexPositionColorTexture[maxBatchItems * 4];
    }

    void RenderBatcher::IncreaseSize() {
        // We need to increase our capacity by 1.5x, to the nearest 64
        const uint32_t oldSize = _batchItems.capacity();
        uint32_t newSize = oldSize + oldSize / 2;
        newSize = newSize + 63 & ~63;  // ensure chunk of 64
        SetSize(newSize);
    }

    bool RenderBatcher::CompareItems(const RenderBatchItem &a, const RenderBatchItem &b) {
        if (a.SortKey < b.SortKey) {
            return true;
        }
        if (a.SortKey > b.SortKey) {
            return false;
        }
        return a.ItemTexture->GetId() < b.ItemTexture->GetId();
    }

    void RenderBatchItem::Set(const float x, const float y, const float w, const float h, const Color color, const Vector2 texCoordTL, const Vector2 texCoordBR, const uint32_t depth) {
        VertexTL.Position.X = x;
        VertexTL.Position.Y = y;
        VertexTL.Col = color;
        VertexTL.TextureCoordinate.X = texCoordTL.X;
        VertexTL.TextureCoordinate.Y = texCoordTL.Y;

        VertexTR.Position.X = x + w;
        VertexTR.Position.Y = y;
        VertexTR.Col = color;
        VertexTR.TextureCoordinate.X = texCoordBR.X;
        VertexTR.TextureCoordinate.Y = texCoordTL.Y;

        VertexBL.Position.X = x;
        VertexBL.Position.Y = y + h;
        VertexBL.Col = color;
        VertexBL.TextureCoordinate.X = texCoordTL.X;
        VertexBL.TextureCoordinate.Y = texCoordBR.Y;

        VertexBR.Position.X = x + w;
        VertexBR.Position.Y = y + h;
        VertexBR.Col = color;
        VertexBR.TextureCoordinate.X = texCoordBR.X;
        VertexBR.TextureCoordinate.Y = texCoordBR.Y;

        SortKey = depth;
    }
}

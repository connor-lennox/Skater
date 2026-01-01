//
// Created by connor on 12/30/25.
//

#pragma once
#include <vector>

#include "Texture.h"
#include "VertexArray.h"
#include "Skater/Color.h"
#include "Skater/Math/Vector2.h"

namespace Skater {
    struct VertexPositionColorTexture {
        Vector2 Position;
        Color Col;
        Vector2 TextureCoordinate;
    };

    struct RenderBatchItem {
        Texture* ItemTexture = nullptr;
        uint32_t SortKey = 0;

        VertexPositionColorTexture VertexTL;
        VertexPositionColorTexture VertexTR;
        VertexPositionColorTexture VertexBL;
        VertexPositionColorTexture VertexBR;

        void Set(float x, float y, float w, float h, Color color, Vector2 texCoordTL, Vector2 texCoordBR, uint32_t depth);
    };

    class RenderBatcher {
    public:
        RenderBatcher();
        ~RenderBatcher();

        RenderBatchItem* GetNextBatchItem();
        void DrawBatch();
    private:
        static constexpr uint32_t MAX_BATCH_SIZE = 1000;

        uint32_t _batchItemIndex = 0;
        std::vector<RenderBatchItem> _batchItems;

        VertexPositionColorTexture* _verts = nullptr;

        VertexArray* _vao;

        void SetSize(uint32_t numItems);
        void IncreaseSize();

        void FlushVertexArray(uint32_t start, uint32_t end, const Texture* texture) const;

        static bool CompareItems(const RenderBatchItem& a, const RenderBatchItem& b);
    };
}

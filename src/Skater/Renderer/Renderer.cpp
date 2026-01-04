//
// Created by connor on 12/30/25.
//

#include "Skater/Renderer/Renderer.h"

namespace Skater {
    Renderer::Renderer() = default;

    Renderer::~Renderer() = default;

    void Renderer::Start() {
        // nothing for now?
    }

    void Renderer::Finish() {
        _batcher.DrawBatch();
    }

    void Renderer::Draw(Texture *texture, const Vector2 position, const Rectangle srcRect, const Color color, const uint32_t layerDepth) {
        const auto batchItem = _batcher.GetNextBatchItem();
        batchItem->ItemTexture = texture;

        float w, h;
        Vector2 tl, br;
        if (!srcRect.IsEmpty()) {
            w = srcRect.Width;
            h = srcRect.Height;
            tl = Vector2(srcRect.X * texture->GetTexelWidth(),
                         srcRect.Y * texture->GetTexelHeight());
            br = Vector2((srcRect.X + srcRect.Width) * texture->GetTexelWidth(),
                         (srcRect.Y + srcRect.Height) * texture->GetTexelHeight());
        } else {
            w = texture->GetWidth();
            h = texture->GetHeight();
            tl = Vector2::Zero;
            br = Vector2::One;
        }

        batchItem->Set(position.X, position.Y, w, h, color, tl, br, layerDepth);
    }
}

//
// Created by connor on 1/22/26.
//

#pragma once
#include "Texture.h"

namespace Skater {
    /// It's basically a Texture wrapper with a pre-baked TextureRegion (represented as a Rectangle).
    class AtlasTexture final : public Texture {
    public:
        AtlasTexture(Texture *atlas, Rectangle rect);
        ~AtlasTexture() override;

        void Bind() const override;
        void Unbind() const override;

        [[nodiscard]] uint32_t GetWidth() const override;
        [[nodiscard]] uint32_t GetHeight() const override;

        [[nodiscard]] float GetTexelWidth() const override;
        [[nodiscard]] float GetTexelHeight() const override;

        [[nodiscard]] uint32_t GetId() const override;
        [[nodiscard]] Rectangle GetBounds() const override;
    private:
        Texture *_atlas;
        Rectangle _rect;
    };
}

//
// Created by connor on 12/29/25.
//

#pragma once

#include "Skater/Math/Rectangle.h"
#include "Skater/Renderer/Texture.h"

namespace Skater {
    class GlTexture final : public Texture {
    public:
        GlTexture(uint8_t image[], uint32_t width, uint32_t height, TextureSpecification specification);
        ~GlTexture() override;

        void Bind() const override;
        void Unbind() const override;

        [[nodiscard]] uint32_t GetWidth() const override { return _width; }
        [[nodiscard]] uint32_t GetHeight() const override { return _height; }

        [[nodiscard]] float GetTexelWidth() const override { return _texelWidth; }
        [[nodiscard]] float GetTexelHeight() const override { return _texelHeight; }

        [[nodiscard]] Rectangle GetBounds() const override { return _bounds; }

        [[nodiscard]] uint32_t GetId() const override { return _textureId; }
    private:
        uint32_t _textureId = 0;
        uint32_t _width = 0;
        uint32_t _height = 0;

        Rectangle _bounds;

        float _texelWidth = 1;
        float _texelHeight = 1;
    };
}
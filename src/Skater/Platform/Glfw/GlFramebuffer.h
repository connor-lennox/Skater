//
// Created by connor on 12/29/25.
//

#pragma once
#include <cstdint>

#include "Skater/Renderer/Framebuffer.h"
#include "Skater/Renderer/Texture.h"

namespace Skater {
    class GlFramebuffer final : public Framebuffer {
    public:
        GlFramebuffer(uint32_t width, uint32_t height);
        ~GlFramebuffer() override;

        void Bind() const override;
        void Unbind() const override;
    private:
        void Init();

        uint32_t _width = 0;
        uint32_t _height = 0;

        uint32_t _fboId = 0;

        Texture* _texture = nullptr;
        uint32_t _depthStencilRboId = 0;
    };
}

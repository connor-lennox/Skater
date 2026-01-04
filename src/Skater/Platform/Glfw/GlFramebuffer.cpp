//
// Created by connor on 12/29/25.
//

#include "GlFramebuffer.h"

#include "glad/glad.h"

namespace Skater {
    class Window;

    GlFramebuffer::GlFramebuffer(const uint32_t width, const uint32_t height) {
        _width = width;
        _height = height;
        this->Init();
    }

    GlFramebuffer::~GlFramebuffer() {
        glDeleteFramebuffers(1, &_fboId);
        glDeleteRenderbuffers(1, &_depthStencilRboId);
    }

    void GlFramebuffer::Init() {
        // Create FBO and bind
        glGenFramebuffers(1, &_fboId);
        glBindFramebuffer(GL_FRAMEBUFFER, _fboId);

        // Create and attach texture
        constexpr TextureSpecification spec (ImageFormat::RGB, FilterMode::Nearest, WrapMode::Clamp);
        _texture = Texture::CreateEmpty(_width, _height, spec);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _texture->GetId(), 0);

        // Depth and Stencil Renderbuffer
        glGenRenderbuffers(1, &_depthStencilRboId);
        glBindRenderbuffer(GL_RENDERBUFFER, _depthStencilRboId);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, _width, _height);

        // Unbind Renderbuffer after configuration
        glBindRenderbuffer(GL_RENDERBUFFER, 0);

        // Link Depth/Stencil renderbuffer to FBO
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _depthStencilRboId);
    }

    void GlFramebuffer::Bind() const {
        glBindFramebuffer(GL_FRAMEBUFFER, _fboId);
    }

    void GlFramebuffer::Unbind() const {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void GlFramebuffer::BlitToScreen(const Rectangle destination) const {
        glBlitNamedFramebuffer(_fboId, 0, 0, 0, _width, _height, destination.Left(), destination.Top(), destination.Right(), destination.Bottom(), GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT, GL_NEAREST);
    }
}

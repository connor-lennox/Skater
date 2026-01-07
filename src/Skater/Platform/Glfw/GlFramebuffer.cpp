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
        glCreateFramebuffers(1, &_fboId);

        // Create and attach texture
        constexpr TextureSpecification spec (ImageFormat::RGB, FilterMode::Nearest, WrapMode::Clamp);
        _texture = Texture::CreateEmpty(_width, _height, spec);
        glNamedFramebufferTexture(_fboId, GL_COLOR_ATTACHMENT0, _texture->GetId(), 0);

        // Depth and Stencil Renderbuffer
        glGenRenderbuffers(1, &_depthStencilRboId);
        glNamedRenderbufferStorage(_depthStencilRboId, GL_DEPTH24_STENCIL8, _width, _height);

        // Link Depth/Stencil renderbuffer to FBO
        glNamedFramebufferRenderbuffer(_fboId, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _depthStencilRboId);
    }

    void GlFramebuffer::Bind() const {
        glBindFramebuffer(GL_FRAMEBUFFER, _fboId);
    }

    void GlFramebuffer::Unbind() const {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void GlFramebuffer::BlitToScreen(const Rectangle destination) const {
        glBlitNamedFramebuffer(_fboId, 0, 0, 0, _width, _height, destination.Left(), destination.Bottom(), destination.Right(), destination.Top(), GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT, GL_NEAREST);
    }
}

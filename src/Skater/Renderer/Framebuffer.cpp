//
// Created by connor on 12/29/25.
//

#include "Skater/Renderer/Framebuffer.h"
#include "../Platform/Glfw/GlFramebuffer.h"

namespace Skater {
    Framebuffer *Framebuffer::Create(const uint32_t width, const uint32_t height) {
        return new GlFramebuffer(width, height);
    }
}

//
// Created by connor on 12/29/25.
//

#include "Skater/Renderer/Texture.h"

#include "../Platform/Glfw/GlTexture.h"

namespace Skater {
    Texture *Texture::Create(uint8_t image[], const uint32_t width, const uint32_t height, const TextureSpecification specification) {
        return new GlTexture(image, width, height, specification);
    }

    Texture *Texture::CreateEmpty(const uint32_t width, const uint32_t height, const TextureSpecification specification) {
        return new GlTexture(nullptr, width, height, specification);
    }

}

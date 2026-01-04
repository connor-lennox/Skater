//
// Created by connor on 1/3/26.
//

#include "Skater/Renderer/Shader.h"

#include "../Platform/Glfw/GlShader.h"

namespace Skater {
    Shader *Shader::Create(const uint8_t *vertexSrc, const uint8_t *fragmentSrc) {
        return new GlShader(vertexSrc, fragmentSrc);
    }
}

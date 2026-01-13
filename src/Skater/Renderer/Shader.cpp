//
// Created by connor on 1/3/26.
//

#include "Skater/Renderer/Shader.h"

#include "embedded_resources.h"

#include "../Platform/Glfw/GlShader.h"

namespace Skater {
    Shader *Shader::Create(const uint8_t *vertexSrc, const uint8_t *fragmentSrc) {
        return new GlShader(vertexSrc, fragmentSrc);
    }

    Shader *Shader::CreateDefault() {
        return new GlShader(resources_shaders_default_vertex_glsl_data, resources_shaders_default_fragment_glsl_data);
    }
}

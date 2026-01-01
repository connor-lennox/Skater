//
// Created by connor on 12/29/25.
//

#pragma once
#include "glad/glad.h"
#include "Skater/Renderer/Texture.h"

namespace Skater {
    class GlTextureUtil {
    public:
        static GLenum ImageFormatToGl(const ImageFormat format) {
            switch (format) {
                case ImageFormat::RGB: return GL_RGB;
                case ImageFormat::RGBA: return GL_RGBA;
            }

            return 0;
        }

        static GLenum FilterModeToGl(const FilterMode mode) {
            switch (mode) {
                case FilterMode::Nearest: return GL_NEAREST;
                case FilterMode::Linear: return GL_LINEAR;
            }

            return 0;
        }

        static GLenum WrapModeToGl(const WrapMode mode) {
            switch (mode) {
                case WrapMode::Repeat: return GL_REPEAT;
                case WrapMode::Clamp: return GL_CLAMP_TO_EDGE;
                case WrapMode::Mirror: return GL_MIRRORED_REPEAT;
            }

            return 0;
        }
    };
}

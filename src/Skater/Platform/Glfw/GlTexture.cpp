//
// Created by connor on 12/29/25.
//

#include "GlTexture.h"

#include "GlTextureUtil.h"
#include "glad/glad.h"

namespace Skater {
    GlTexture::GlTexture(uint8_t image[], const uint32_t width, const uint32_t height, const TextureSpecification specification) {
        _width = width;
        _height = height;

        _texelWidth = 1.0f / width;
        _texelHeight = 1.0f / height;

        _bounds = Rectangle(0, 0, width, height);

        // Create and bind texture
        glGenTextures(1, &_textureId);
        glBindTexture(GL_TEXTURE_2D, _textureId);

        // Set texture parameters
        const auto glFilter = static_cast<GLint>(GlTextureUtil::FilterModeToGl(specification.filterMode));
        const auto glWrap = static_cast<GLint>(GlTextureUtil::WrapModeToGl(specification.wrapMode));

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, glFilter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, glFilter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, glWrap);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, glWrap);

        // Set image data
        const auto glImageFormat = static_cast<GLint>(GlTextureUtil::ImageFormatToGl(specification.imageFormat));

        glTexImage2D(GL_TEXTURE_2D, 0, glImageFormat, width, height, 0, glImageFormat, GL_UNSIGNED_BYTE, image);
    }

    GlTexture::~GlTexture() {
        glDeleteTextures(1, &_textureId);
    }

    void GlTexture::Bind() const {
        glBindTexture(GL_TEXTURE_2D, _textureId);
    }

    void GlTexture::Unbind() const {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

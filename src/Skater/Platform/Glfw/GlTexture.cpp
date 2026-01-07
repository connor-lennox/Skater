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
        glCreateTextures(GL_TEXTURE_2D, 1, &_textureId);

        // Set texture parameters
        const auto glFilter = static_cast<GLint>(GlTextureUtil::FilterModeToGl(specification.filterMode));
        const auto glWrap = static_cast<GLint>(GlTextureUtil::WrapModeToGl(specification.wrapMode));

        glTextureParameteri(_textureId, GL_TEXTURE_MIN_FILTER, glFilter);
        glTextureParameteri(_textureId, GL_TEXTURE_MAG_FILTER, glFilter);
        glTextureParameteri(_textureId, GL_TEXTURE_WRAP_S, glWrap);
        glTextureParameteri(_textureId, GL_TEXTURE_WRAP_T, glWrap);

        // Set image data
        const auto glInternalFormat = static_cast<GLint>(GlTextureUtil::ImageFormatToGlInternalFormat(specification.imageFormat));
        const auto glFormat = static_cast<GLint>(GlTextureUtil::ImageFormatToGlFormat(specification.imageFormat));

        glTextureStorage2D(_textureId, 1, glInternalFormat, width, height);
        if (image != nullptr) {
            glTextureSubImage2D(_textureId, 0, 0, 0, width, height, glFormat, GL_UNSIGNED_BYTE, image);
        }
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

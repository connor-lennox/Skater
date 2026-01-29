//
// Created by connor on 1/22/26.
//

#include "Skater/Graphics/Atlas/AtlasTexture.h"

namespace Skater {
    AtlasTexture::AtlasTexture(Texture *atlas, const Rectangle rect) : _atlas(atlas), _rect(rect) {}
    AtlasTexture::~AtlasTexture() = default;

    void AtlasTexture::Bind() const {
        _atlas->Bind();
    }

    void AtlasTexture::Unbind() const {
        _atlas->Unbind();
    }

    Rectangle AtlasTexture::GetBounds() const {
        return _rect;
    }

    uint32_t AtlasTexture::GetWidth() const {
        return _rect.Width;
    }

    uint32_t AtlasTexture::GetHeight() const {
        return _rect.Height;
    }

    float AtlasTexture::GetTexelWidth() const {
        return _atlas->GetTexelWidth();
    }

    float AtlasTexture::GetTexelHeight() const {
        return _atlas->GetTexelHeight();
    }

    uint32_t AtlasTexture::GetId() const {
        return _atlas->GetId();
    }

}

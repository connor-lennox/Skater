//
// Created by connor on 12/31/25.
//

#pragma once
#include "TextureRegion.h"
#include "Skater/Core/Component.h"

namespace Skater {
    class SpriteRenderer : public Component {
    public:
        SpriteRenderer() : Component("SpriteRenderer") {}

        void Render() override;

        void SetTextureRegion(const TextureRegion &textureRegion);

        uint32_t HFrames = 1;
        uint32_t VFrames = 1;
        uint32_t Frame = 0;
    private:
        TextureRegion _textureRegion;

        [[nodiscard]] Rectangle GetRenderArea() const;
    };
}

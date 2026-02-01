//
// Created by connor on 12/31/25.
//

#pragma once
#include "GraphicsComponent.h"
#include "TextureRegion.h"
#include "Skater/Core/Component.h"
#include "Skater/Renderer/SpriteEffects.h"

namespace Skater {
    class SpriteRenderer : public GraphicsComponent {
    public:
        SpriteRenderer() : GraphicsComponent("SpriteRenderer") {}

        void Render() override;

        void SetTextureRegion(const TextureRegion &textureRegion);

        void SetFlipHorizontal(bool state);
        void SetFlipVertical(bool state);

        uint32_t HFrames = 1;
        uint32_t VFrames = 1;
        uint32_t Frame = 0;
    private:
        TextureRegion _textureRegion;

        SpriteEffects _spriteEffects = SpriteEffects();

        [[nodiscard]] Rectangle GetRenderArea() const;
    };
}

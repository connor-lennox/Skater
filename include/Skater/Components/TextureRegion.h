//
// Created by connor on 12/31/25.
//

#pragma once
#include "Skater/Math/Rectangle.h"
#include "Skater/Renderer/Texture.h"

namespace Skater {
    struct TextureRegion {
        TextureRegion() : TextureRegion(nullptr, Rectangle::Empty) {}
        explicit TextureRegion(Texture* texture) : TextureRegion(texture, Rectangle::Empty) {}
        TextureRegion(Texture* texture, Rectangle sourceRect);

        Texture* Tex = nullptr;
        Rectangle SourceRect;

        [[nodiscard]] Point GetSourceTextureSize() const;
        [[nodiscard]] Rectangle GetTextureRect() const;
    };
}

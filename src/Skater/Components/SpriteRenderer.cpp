//
// Created by connor on 12/31/25.
//

#include "Skater/Components/SpriteRenderer.h"

#include "Skater/Game.h"

namespace Skater {
    void SpriteRenderer::SetTextureRegion(const TextureRegion &textureRegion) {
        _textureRegion = textureRegion;
    }

    Rectangle SpriteRenderer::GetRenderArea() const {
        const auto textureSize = _textureRegion.GetSourceTextureSize();
        const auto frameRenderSize = Point(textureSize.X / HFrames, textureSize.Y / VFrames);
        const auto frameRenderOffset = Point(frameRenderSize.X * (Frame % HFrames), frameRenderSize.Y * (Frame / HFrames));

        const auto baseRect = _textureRegion.GetTextureRect();
        return Rectangle(baseRect.X + frameRenderOffset.X, baseRect.Y + frameRenderOffset.Y,
            frameRenderSize.X, frameRenderSize.Y);
    }

    void SpriteRenderer::Render() {
        // Can't draw without a texture
        if (_textureRegion.Tex == nullptr) {
            return;
        }

        const auto renderArea = GetRenderArea();

        const auto centeringOffset = (renderArea.Size() / 2.0).ToVector2();

        // TODO: Add tint color and layer depth to new GraphicsComponent parent class
        Game::GetInstance().GetRenderer()->Draw(_textureRegion.Tex, _entity->Position - centeringOffset, renderArea, Color::White, 0);
    }

}

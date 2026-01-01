//
// Created by connor on 12/31/25.
//

#include "Skater/Components/TextureRegion.h"

namespace Skater {
    TextureRegion::TextureRegion(Texture *texture, const Rectangle sourceRect) : Tex(texture), SourceRect(sourceRect) {}

    Point TextureRegion::GetSourceTextureSize() const {
        if (!SourceRect.IsEmpty()) {
            return SourceRect.Size();
        }
        return Tex->GetBounds().Size();
    }

    Rectangle TextureRegion::GetTextureRect() const {
        if (!SourceRect.IsEmpty()) {
            return SourceRect;
        }
        return Tex->GetBounds();
    }
}

//
// Created by connor on 1/10/26.
//

#include "Skater/Components/TextRenderer.h"

#include "Skater/Game.h"

namespace Skater {
    void TextRenderer::Render() {
        if (_font == nullptr || _text.empty()) {
            return;
        }

        const auto renderer = Game::GetInstance().GetRenderer();

        const auto tex = _font->GetFontAtlas();
        auto root_pos = _entity->Position.Floor();

        for (const auto c : _text) {
            // Special handling for newlines
            if (c == '\n') {
                root_pos.X = _entity->Position.X;
                root_pos.Y += static_cast<float>(_font->GetLineGap());
            }

            const auto glyph = _font->GetGlyph(c);
            if (glyph == nullptr) {
                continue;
            }

            renderer->Draw(tex, root_pos + glyph->Offset, glyph->AtlasRect, ModulateColor, SortingLayer);

            root_pos.X += glyph->Advance;
        }
    }

}

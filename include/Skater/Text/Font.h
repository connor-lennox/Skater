//
// Created by connor on 1/9/26.
//

#pragma once
#include "Skater/Renderer/Texture.h"

namespace Skater {
    class FontGlyph {
    public:
        FontGlyph() = default;
        FontGlyph(const char character, const Rectangle atlasRect, const float advance, const Vector2 offset)
            : Character(character), AtlasRect(atlasRect), Advance(advance), Offset(offset) {}

        char Character = 'a';
        Rectangle AtlasRect = Rectangle::Empty;
        float Advance = 0;
        Vector2 Offset = Vector2::Zero;
    };

    class Font {
    public:
        Font() = default;
        ~Font();

        void SetGlyphs(FontGlyph *glyphs, const char startingCodepoint, const uint32_t numGlyphs) {
            _glyphs = glyphs;
            _startingCodepoint = startingCodepoint;
            _numGlyphs = numGlyphs;
        }

        void SetSpacing(int ascent, int descent, int lineGap);
        void SetFontAtlas(Texture *atlas) { _fontAtlas = atlas; }

        [[nodiscard]] int GetAscent() const { return _ascent; }
        [[nodiscard]] int GetDescent() const { return _descent; }
        [[nodiscard]] int GetLineGap() const { return _lineGap; }

        [[nodiscard]] Rectangle GetAtlasRect(char code) const;
        [[nodiscard]] float GetAdvance(char code) const;

        [[nodiscard]] FontGlyph *GetGlyph(char code) const;

        [[nodiscard]] Texture* GetFontAtlas() const { return _fontAtlas; }
    private:
        int _ascent = 0;
        int _descent = 0;
        int _lineGap = 0;

        char _startingCodepoint = 0;
        uint32_t _numGlyphs = 0;
        FontGlyph *_glyphs = nullptr;

        Texture *_fontAtlas = nullptr;
    };
}

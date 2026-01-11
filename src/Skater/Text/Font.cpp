//
// Created by connor on 1/9/26.
//

#include "Skater/Text/Font.h"

namespace Skater {
    Font::~Font() {
        delete _glyphs;
        delete _fontAtlas;
    }

    void Font::SetSpacing(const int ascent, const int descent, const int lineGap) {
        _ascent = ascent;
        _descent = descent;
        _lineGap = lineGap;
    }

    Rectangle Font::GetAtlasRect(const char code) const {
        const auto idx = code - _startingCodepoint;
        if (idx < 0 || idx >= _numGlyphs) {
            return Rectangle::Empty;
        }

        return _glyphs[idx].AtlasRect;
    }

    float Font::GetAdvance(const char code) const {
        const auto idx = code - _startingCodepoint;
        if (idx < 0 || idx >= _numGlyphs) {
            return 0;
        }

        return _glyphs[idx].Advance;
    }

    FontGlyph *Font::GetGlyph(const char code) const {
        const auto idx = code - _startingCodepoint;
        if (idx < 0 || idx >= _numGlyphs) {
            return nullptr;
        }

        return &_glyphs[idx];
    }
}

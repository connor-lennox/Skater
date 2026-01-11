//
// Created by connor on 1/9/26.
//


#include "Skater/Text/FontSystem.h"
#include "stb_truetype.h"

namespace Skater {
    FontSystem::FontSystem(const uint8_t *fontBuffer) {
        _fontBuffer = fontBuffer;
        _fontInfo = new stbtt_fontinfo();
        stbtt_InitFont(_fontInfo, fontBuffer, 0);
    }

    FontSystem::~FontSystem() {
        delete _fontBuffer;
        delete _fontInfo;
    }

    Font *FontSystem::BuildFont(const float fontSize, const char startCodepoint, const char endCodepoint) const {
        const auto scaleFactor = stbtt_ScaleForPixelHeight(_fontInfo, fontSize);

        const auto numGlyphs = endCodepoint - startCodepoint + 1;
        if (numGlyphs <= 0) {
            return nullptr;
        }

        stbtt_pack_context packContext;

        stbtt_packedchar charData[numGlyphs];

        // Build grayscale alpha map for bitmap atlas texture
        uint8_t mask[TEXTURE_SIZE * TEXTURE_SIZE];

        stbtt_PackBegin(&packContext, mask, TEXTURE_SIZE, TEXTURE_SIZE, TEXTURE_SIZE, 1, nullptr);
        stbtt_PackFontRange(&packContext, _fontBuffer, 0, fontSize, startCodepoint, numGlyphs, charData);
        stbtt_PackEnd(&packContext);

        // Convert grayscale to RGBA8 texture - all white with target alpha
        uint8_t texturePixels[TEXTURE_SIZE * TEXTURE_SIZE * 4];
        for (auto i = 0; i < TEXTURE_SIZE * TEXTURE_SIZE; i++) {
            if (mask[i] > 0) {
                texturePixels[4 * i + 0] = 255;
                texturePixels[4 * i + 1] = 255;
                texturePixels[4 * i + 2] = 255;
            } else {
                texturePixels[4 * i + 0] = 0;
                texturePixels[4 * i + 1] = 0;
                texturePixels[4 * i + 2] = 0;
            }

            texturePixels[4 * i + 3] = mask[i];
        }

        const auto atlasTexture = Texture::Create(
            texturePixels,
            TEXTURE_SIZE, TEXTURE_SIZE,
            TextureSpecification(ImageFormat::RGBA, FilterMode::Nearest, WrapMode::Clamp)
        );

        int ascent, descent, lineGap;
        stbtt_GetFontVMetrics(_fontInfo, &ascent, &descent, &lineGap);

        FontGlyph glyphs[numGlyphs];
        for (auto i = 0; i < numGlyphs; i++) {
            const char c = startCodepoint + i;

            const auto packData = charData[i];
            const auto r = Rectangle(packData.x0, packData.y0, packData.x1 - packData.x0, packData.y1 - packData.y0);
            const auto adv = packData.xadvance;
            const auto offset = Vector2(packData.xoff, packData.yoff);

            glyphs[i].Character = c;
            glyphs[i].AtlasRect = r;
            glyphs[i].Advance = adv;
            glyphs[i].Offset = offset;
        }

        const auto font = new Font();
        font->SetGlyphs(glyphs, startCodepoint, numGlyphs);
        font->SetSpacing(ascent, descent, lineGap);
        font->SetFontAtlas(atlasTexture);
        return font;
    }

}

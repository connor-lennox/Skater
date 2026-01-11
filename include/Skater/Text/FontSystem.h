//
// Created by connor on 1/9/26.
//

#pragma once
#include "Font.h"

class stbtt_fontinfo;

namespace Skater {
    class FontSystem {
    public:
        explicit FontSystem(const uint8_t *fontBuffer);
        ~FontSystem();

        [[nodiscard]] Font *BuildFont(const float size) const {
            return BuildFont(size, 32, 126);
        }
        [[nodiscard]] Font *BuildFont(float fontSize, char startCodepoint, char endCodepoint) const;
    private:
        static constexpr uint32_t TEXTURE_SIZE = 1024;

        const uint8_t *_fontBuffer;
        stbtt_fontinfo *_fontInfo = nullptr;
    };
}

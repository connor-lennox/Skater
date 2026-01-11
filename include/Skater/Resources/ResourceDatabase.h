//
// Created by connor on 1/3/26.
//

#pragma once
#include <string>
#include <unordered_map>

#include "Skater/Renderer/Texture.h"
#include "Skater/Text/FontSystem.h"

namespace Skater {
    class AudioStream;

    class ResourceDatabase {
    public:
        static Texture* LoadTexture(const std::string &filename);
        static Texture* LoadTextureFromBytes(uint8_t bytes[], uint32_t len);

        static FontSystem* LoadFontSystem(const std::string &filename);
        static FontSystem* LoadFontSystemFromBytes(uint8_t bytes[]);

        static AudioStream* LoadAudioStream(const std::string &filename);
        static AudioStream* LoadAudioStreamFromBytes(uint8_t bytes[], uint32_t len);
    private:
        inline static std::unordered_map<std::string, Texture*> _textureCache;
        inline static std::unordered_map<std::string, FontSystem*> _fontSystemCache;
        inline static std::unordered_map<std::string, AudioStream*> _audioStreamCache;
    };
}

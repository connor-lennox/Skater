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
        static FontSystem* LoadFontSystem(const std::string &filename);
        static AudioStream* LoadAudioStream(const std::string &filename);
    private:
        inline static std::unordered_map<std::string, Texture*> _textureCache;
        inline static std::unordered_map<std::string, FontSystem*> _fontSystemCache;
        inline static std::unordered_map<std::string, AudioStream*> _audioStreamCache;
    };
}

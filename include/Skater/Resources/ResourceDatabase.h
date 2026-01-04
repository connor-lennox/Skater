//
// Created by connor on 1/3/26.
//

#pragma once
#include <string>
#include <unordered_map>

#include "Skater/Renderer/Texture.h"

namespace Skater {
    class ResourceDatabase {
    public:
        static Texture* LoadTexture(const std::string &filename);
    private:
        static std::unordered_map<std::string, Texture*> _textureCache;
    };
}

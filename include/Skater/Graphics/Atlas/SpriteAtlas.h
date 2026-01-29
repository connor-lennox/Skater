//
// Created by connor on 1/27/26.
//

#pragma once
#include <string>
#include <unordered_map>

#include "AtlasTexture.h"
#include "Skater/Renderer/Texture.h"

namespace Skater {
    class SpriteAtlas {
    public:
        SpriteAtlas(Texture *atlas, std::unordered_map<std::string, AtlasTexture*> *atlasTextures);
        ~SpriteAtlas();

        [[nodiscard]] AtlasTexture *GetAtlasTexture(const std::string& identifier) const;
    private:
        Texture *_atlas;
        std::unordered_map<std::string, AtlasTexture*> *_atlasTextures;
    };
}

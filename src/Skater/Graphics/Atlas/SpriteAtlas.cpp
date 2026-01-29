//
// Created by connor on 1/27/26.
//

#include "Skater/Graphics/Atlas/SpriteAtlas.h"

namespace Skater {
    SpriteAtlas::SpriteAtlas(Texture *atlas, std::unordered_map<std::string, AtlasTexture*> *atlasTextures)
        : _atlas(atlas), _atlasTextures(atlasTextures) {}

    SpriteAtlas::~SpriteAtlas() {
        delete _atlas;
        delete _atlasTextures;
    }

    AtlasTexture *SpriteAtlas::GetAtlasTexture(const std::string& identifier) const {
        return _atlasTextures->at(identifier);
    }
}

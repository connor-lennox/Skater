//
// Created by connor on 1/3/26.
//

#include "Skater/Resources/ResourceDatabase.h"
#include "Skater/Renderer/Texture.h"

#include "stb_image.h"

namespace Skater {
    Texture *ResourceDatabase::LoadTexture(const std::string &filename) {
        if (_textureCache.contains(filename)) {
            return _textureCache.at(filename);
        }

        int x, y, n;
        const auto imageData = stbi_load(filename.c_str(), &x, &y, &n, 0);

        const auto imageFormat = n == 4 ? ImageFormat::RGBA : ImageFormat::RGB;

        Texture* res = Texture::Create(imageData, x, y, TextureSpecification(imageFormat, FilterMode::Nearest, WrapMode::Repeat));
        _textureCache[filename] = res;

        return res;
    }
}

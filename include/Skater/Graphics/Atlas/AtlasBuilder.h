//
// Created by connor on 1/27/26.
//

#pragma once
#include <string>
#include <utility>
#include <vector>

#include "SpriteAtlas.h"
#include "Skater/Graphics/Image.h"

namespace Skater {
    class AtlasBuilder {
    public:
        AtlasBuilder() = default;

        void AddImage(const std::string &identifier, Image *image);

        SpriteAtlas *Build();
    private:
        struct AtlasElement {
            std::string identifier;
            Image *image;

            AtlasElement(std::string identifier, Image *image) : identifier(std::move(identifier)), image(image) {}
        };

        std::vector<AtlasElement> _elements;
        ImageFormat _imageFormat = ImageFormat::RGBA;

        static constexpr uint32_t MINIMUM_SIZE = 128;

        [[nodiscard]] SpriteAtlas *TryBuild(uint32_t imageSize) const;

        static bool CompareElements(const AtlasElement &a, const AtlasElement &b);
    };
}

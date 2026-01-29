//
// Created by connor on 1/27/26.
//

#include "Skater/Graphics/Atlas/AtlasBuilder.h"

#include <algorithm>

using namespace std;

namespace Skater {
    void AtlasBuilder::AddImage(const std::string &identifier, Image *image) {
        if (_elements.empty()) {
            _imageFormat = image->GetImageFormat();
        } else {
            if (image->GetImageFormat() != _imageFormat) {
                printf("Can't pack images of differing image formats!");
                return;
            }
        }
        _elements.emplace_back(identifier, image);
    }

    SpriteAtlas *AtlasBuilder::Build() {
        auto size = MINIMUM_SIZE;
        SpriteAtlas *result = nullptr;

        // Sort the elements from tallest to shortest, for packing
        std::ranges::sort(_elements, CompareElements);

        while (result == nullptr) {
            result = TryBuild(size);
            size *= 2;
        }

        return result;
    }

    SpriteAtlas *AtlasBuilder::TryBuild(const uint32_t imageSize) const {
        unordered_map<string, Point> imagePositions;

        uint32_t xPos = 0;
        uint32_t yPos = 0;
        uint32_t hIncrement = 0;

        for (const auto &element: _elements) {
            // Make sure this element can fit in the row on its own:
            if (element.image->GetWidth() > imageSize) {
                return nullptr;
            }

            // Check to see if we go down to the next row.
            if (xPos + element.image->GetWidth() > imageSize) {
                yPos += hIncrement;
                xPos = 0;
                hIncrement = 0;
            }

            // At this point, we've run off the bottom. Can't pack at this size!
            if (yPos + element.image->GetHeight() > imageSize) {
                return nullptr;
            }

            // Stash the position of this image for later
            imagePositions.insert({ element.identifier, Point(xPos, yPos) });
            xPos += element.image->GetWidth();

            if (element.image->GetHeight() > hIncrement) {
                hIncrement = element.image->GetHeight();
            }
        }

        // At this point, we've positioned everything and just need to build the sprite atlas itself
        const auto atlasImage = Image(imageSize, imageSize, _imageFormat);

        // Blit all subimages into the atlas image
        for (const auto& element : _elements) {
            const auto position = imagePositions[element.identifier];
            atlasImage.BlitIn(element.image, position.X, position.Y);
        }

        // Move texture over to the GPU
        const auto atlas = Texture::Create(&atlasImage);

        // Build AtlasTextures for each element in the Atlas
        const auto textures = new unordered_map<string, AtlasTexture*>();
        for (const auto& element : _elements) {
            const auto identifier = element.identifier;
            const auto position = imagePositions[identifier];
            const auto rect = Rectangle(position.X, position.Y, element.image->GetWidth(), element.image->GetHeight());
            textures->insert({ identifier, new AtlasTexture(atlas, rect) });
        }

        return new SpriteAtlas(atlas, textures);
    }

    bool AtlasBuilder::CompareElements(const AtlasElement &a, const AtlasElement &b) {
        return a.image->GetHeight() > b.image->GetHeight();
    }
}

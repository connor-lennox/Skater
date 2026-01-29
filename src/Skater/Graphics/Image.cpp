//
// Created by connor on 1/27/26.
//

#include "Skater/Graphics/Image.h"

#include <cstdio>
#include <cstring>

namespace Skater {
    Image::Image(uint8_t *data, const uint32_t width, const uint32_t height, const ImageFormat imageFormat)
        : _data(data), _width(width), _height(height), _imageFormat(imageFormat) {}

    Image::Image(const uint32_t width, const uint32_t height, const ImageFormat imageFormat)
        : _width(width), _height(height), _imageFormat(imageFormat) {
        const auto bytesPerPixel = _imageFormat == ImageFormat::RGBA ? 4 : 3;
        _data = new uint8_t[width * height * bytesPerPixel];
    }

    Image::~Image() {
        delete _data;
    }

    void Image::BlitIn(const Image *other, const uint32_t x, const uint32_t y) const {
        if (other->GetWidth() + x > GetWidth() || other->GetHeight() + y > GetHeight()) {
            printf("Image blit was outside acceptable range!");
            return;
        }

        if (other->GetImageFormat() != GetImageFormat()) {
            printf("Image blit between mismatched image formats not supported!");
            return;
        }

        const auto otherData = other->GetData();
        const auto bytesPerPixel = GetImageFormat() == ImageFormat::RGBA ? 4 : 3;
        const auto bytesPerCopy = other->GetWidth() * bytesPerPixel;

        for (auto dy = 0; dy < other->GetHeight(); dy++) {
            const auto srcIdx = dy * other->GetWidth() * bytesPerPixel;
            const auto destIdx = (((y + dy) * GetWidth()) + x) * bytesPerPixel;
            memcpy(&_data[destIdx], &otherData[srcIdx], bytesPerCopy);
        }
    }
}

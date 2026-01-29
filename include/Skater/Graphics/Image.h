//
// Created by connor on 1/27/26.
//

#pragma once
#include <cstdint>

#include "ImageFormat.h"

namespace Skater {
    class Image {
    public:
        Image(uint8_t *data, uint32_t width, uint32_t height, ImageFormat imageFormat);
        Image(uint32_t width, uint32_t height, ImageFormat imageFormat);
        ~Image();

        /// Blits the "other" image into us at the given x and y coordinates.
        void BlitIn(const Image *other, uint32_t x, uint32_t y) const;

        [[nodiscard]] uint8_t* GetData() const { return _data; }
        [[nodiscard]] uint32_t GetWidth() const { return _width; }
        [[nodiscard]] uint32_t GetHeight() const { return _height; }

        [[nodiscard]] ImageFormat GetImageFormat() const { return _imageFormat; }
    private:
        uint8_t *_data;

        uint32_t _width = 0;
        uint32_t _height = 0;

        ImageFormat _imageFormat;
    };
}

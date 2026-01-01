//
// Created by connor on 12/29/25.
//

#pragma once
#include <cstdint>

#include "Skater/Math/Rectangle.h"

namespace Skater {
    enum class ImageFormat {
        RGB,
        RGBA
    };

    enum class FilterMode {
        Nearest,
        Linear
    };

    enum class WrapMode {
        Repeat,
        Clamp,
        Mirror
    };

    struct TextureSpecification {
        ImageFormat imageFormat;
        FilterMode filterMode;
        WrapMode wrapMode;
    };

    class Texture {
    public:
        virtual ~Texture() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        [[nodiscard]] virtual uint32_t GetWidth() const = 0;
        [[nodiscard]] virtual uint32_t GetHeight() const = 0;

        [[nodiscard]] virtual float GetTexelWidth() const = 0;
        [[nodiscard]] virtual float GetTexelHeight() const = 0;

        [[nodiscard]] virtual uint32_t GetId() const = 0;

        [[nodiscard]] virtual Rectangle GetBounds() const = 0;

        static Texture* Create(uint8_t image[], uint32_t width, uint32_t height, TextureSpecification specification);
        static Texture* CreateEmpty(uint32_t width, uint32_t height, TextureSpecification specification);
    };
}

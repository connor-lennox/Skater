//
// Created by connor on 12/29/25.
//

#pragma once
#include <cstdint>

#include "Skater/Math/Rectangle.h"

namespace Skater {
    class Framebuffer {
    public:
        virtual ~Framebuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        virtual void BlitToScreen(Rectangle destination) const = 0;

        static Framebuffer* Create(uint32_t width, uint32_t height);
    };
}

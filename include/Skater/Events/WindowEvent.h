//
// Created by connor on 12/16/25.
//

#pragma once
#include "Event.h"

namespace Skater {
    class WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(WindowClose)
    };

    class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(const uint32_t width, const uint32_t height)
            : _width(width), _height(height) {}

        uint32_t GetWidth() const { return _width; }
        uint32_t GetHeight() const { return _height; }

        EVENT_CLASS_TYPE(WindowResize)
    private:
        uint32_t _width, _height;
    };
}

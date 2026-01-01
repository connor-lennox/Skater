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
        WindowResizeEvent(const unsigned int width, const unsigned int height)
            : _width(width), _height(height) {}

        unsigned int GetWidth() const { return _width; }
        unsigned int GetHeight() const { return _height; }

        EVENT_CLASS_TYPE(WindowResize)
    private:
        unsigned int _width, _height;
    };
}

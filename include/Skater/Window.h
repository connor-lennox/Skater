//
// Created by connor on 12/15/25.
//

#pragma once

#include <functional>
#include <string>
#include <utility>

#include "Skater/Events/Event.h"

namespace Skater {
    struct WindowProperties {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        explicit WindowProperties(
            std::string title = "Skater Game",
            const unsigned int width = 1280,
            const unsigned int height = 720)
        : Title(std::move(title)), Width(width), Height(height) {}
    };

    class Window {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        [[nodiscard]] virtual unsigned int GetWidth() const = 0;
        [[nodiscard]] virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProperties& props = WindowProperties());
    };
}

//
// Created by connor on 12/16/25.
//

#pragma once
#include <GLFW/glfw3.h>

#include "Skater/Window.h"

namespace Skater {
    class GlWindow : public Window {
    public:
        explicit GlWindow(const WindowProperties& props);
        ~GlWindow() override;

        void OnUpdate() override;

        [[nodiscard]] unsigned int GetWidth() const override { return _data.Width; }
        [[nodiscard]] unsigned int GetHeight() const override { return _data.Height; }

        void SetEventCallback(const EventCallbackFn &callback) override { _data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        [[nodiscard]] bool IsVSync() const override;
    private:
        GLFWwindow* _window{};

        struct WindowData {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;
            EventCallbackFn EventCallback;
        };

        WindowData _data;

        void Init(const WindowProperties& props);
        void Shutdown() const;
        void UpdateJoysticks() const;
    };
}

//
// Created by connor on 12/15/25.
//

#pragma once
#include "Window.h"
#include "Core/Scene.h"
#include "Renderer/Framebuffer.h"
#include "Renderer/Renderer.h"
#include "Skater/Events/WindowEvent.h"

namespace Skater {
    class Game {
    public:
        Game();
        virtual ~Game();

        virtual void Setup() {}
        void Run();

        void OnEvent(Event& event);

        [[nodiscard]] Renderer* GetRenderer() const { return _renderer; }

        void SetScene(Scene* scene);

        void SetBackbufferSize(uint32_t width, uint32_t height);

        Rectangle GetRenderTargetDestination() const { return _renderTargetDest; };

        static Game& GetInstance();
    private:
        void OnWindowClose(WindowCloseEvent& e);

        Window* _window;
        bool _running = true;

        Renderer* _renderer;
        Scene* _currentScene = nullptr;

        Framebuffer* _backbuffer;

        void UpdateRenderTargetDest();
        Rectangle _renderTargetDest = Rectangle();
    };
}

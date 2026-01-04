//
// Created by connor on 12/15/25.
//

#pragma once
#include "Window.h"
#include "Core/Scene.h"
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

        static Game& GetInstance();
    private:
        void OnWindowClose(WindowCloseEvent& e);

        Window* _window;
        bool _running = true;

        Renderer* _renderer;
        Scene* _currentScene = nullptr;
    };
}

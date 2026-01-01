//
// Created by connor on 12/15/25.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Skater/Game.h"

#include <iostream>

#include "Skater/Events/Event.h"
#include "Skater/Events/WindowEvent.h"
#include "Skater/Input/Input.h"
#include "Skater/Renderer/RenderCommand.h"

namespace Skater {
    namespace {
        Game* _staticGame;
    }

    Game::Game() {
        _window = Window::Create();
        _window->SetEventCallback([this]<typename T0>(T0 && PH1) { OnEvent(std::forward<T0>(PH1)); });

        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return;
        }

        glViewport(0, 0, 800, 600);

        _renderer = new Renderer();

        _staticGame = this;
    }

    Game::~Game() {
        delete _window;
    }

    void Game::OnEvent(Event &event) {
        switch (event.GetEventType()) {
            case EventType::None:
                break;
            case EventType::WindowClose:
                OnWindowClose(dynamic_cast<WindowCloseEvent &>(event));
                break;
            case EventType::WindowResize:
                break;
            case EventType::WindowFocus:
                break;
            case EventType::WindowLostFocus:
                break;
            case EventType::WindowMoved:
                break;
            case EventType::AppTick:
                break;
            case EventType::AppUpdate:
                break;
            case EventType::AppRender:
                break;
            case EventType::KeyPressed:
                break;
            case EventType::KeyReleased:
                break;
            case EventType::MouseButtonPressed:
                break;
            case EventType::MouseButtonReleased:
                break;
            case EventType::MouseMoved:
                break;
            case EventType::MouseScrolled:
                break;
        }
    }

    void Game::Run() {
        RenderCommand::SetClearColor(Color::CornflowerBlue);

        while(_running)
        {
            RenderCommand::Clear();

            Input::Update();

            _renderer->Start();

            _renderer->Finish();

            _window->OnUpdate();
        }
    }

    Game& Game::GetInstance() {
        return *_staticGame;
    }

    void Game::OnWindowClose(WindowCloseEvent &e) {
        _running = false;
    }
}

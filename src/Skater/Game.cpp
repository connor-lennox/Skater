//
// Created by connor on 12/15/25.
//

#include "Skater/Game.h"

#include "glad/glad.h"
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

        RenderCommand::Init();

        _renderer = new Renderer();
        _backbuffer = Framebuffer::Create(384, 216);
        UpdateRenderTargetDest();

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
                UpdateRenderTargetDest();
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
        Setup();

        RenderCommand::SetClearColor(Color::CornflowerBlue);

        while(_running)
        {
            RenderCommand::Clear();

            Input::Update();

            if (_currentScene != nullptr) {
                _currentScene->Update();

                _backbuffer->Bind();
                glViewport(0, 0, 384, 216);
                _renderer->Start();
                _currentScene->Render();
                _renderer->Finish();

                glViewport(0, 0, _window->GetWidth(), _window->GetHeight());
                _backbuffer->BlitToScreen(_renderTargetDest);
            }

            _window->OnUpdate();
        }
    }

    void Game::SetScene(Scene *scene) {
        _currentScene = scene;
    }

    void Game::SetBackbufferSize(const uint32_t width, const uint32_t height) {
        if (_backbuffer != nullptr) {
            _backbuffer->Unbind();
            delete _backbuffer;
        }
        _backbuffer = Framebuffer::Create(width, height);
    }

    Game& Game::GetInstance() {
        return *_staticGame;
    }

    void Game::OnWindowClose(WindowCloseEvent &e) {
        _running = false;
    }

    void Game::UpdateRenderTargetDest() {
        const auto gameResolution = Point(_backbuffer->GetWidth(), _backbuffer->GetHeight());
        const auto resolutionRatio = static_cast<float>(gameResolution.X) / gameResolution.Y;
        const auto windowBounds = Point(_window->GetWidth(), _window->GetHeight());
        const auto windowRatio = static_cast<float>(windowBounds.X) / windowBounds.Y;

        float scale;

        if (resolutionRatio < windowRatio) {
            scale = static_cast<float>(windowBounds.Y) / gameResolution.Y;
        } else if (resolutionRatio > windowRatio) {
            scale = static_cast<float>(windowBounds.X) / gameResolution.X;
        } else {
            // If they have the same ratio, use the full window
            _renderTargetDest = Rectangle(0, 0, windowBounds.X, windowBounds.Y);
            return;
        }

        // Scale the backbuffer rect to fit nicely in the window
        const auto scaledRect = Rectangle(0, 0, gameResolution.X * scale, gameResolution.Y * scale);
        const auto centered = Rectangle::CenterRectangle(Rectangle(0, 0, _window->GetWidth(), _window->GetHeight()), scaledRect);
        _renderTargetDest = centered;
    }
}

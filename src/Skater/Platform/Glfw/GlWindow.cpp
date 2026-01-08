//
// Created by connor on 12/16/25.
//

#include <glad/glad.h>

#include "GlWindow.h"

#include "GlKeyUtil.h"
#include "Skater/Window.h"
#include "Skater/Events/WindowEvent.h"
#include "Skater/Input/Input.h"

namespace Skater {
    static bool GLFWInitialized = false;

    Window *Window::Create(const WindowProperties &props) {
        return new GlWindow(props);
    }

    GlWindow::GlWindow(const WindowProperties &props) {
        Init(props);
    }

    GlWindow::~GlWindow() {
        Shutdown();
    }

    void GlWindow::Init(const WindowProperties &props) {
        _data.Title = props.Title;
        _data.Width = props.Width;
        _data.Height = props.Height;

        if (!GLFWInitialized) {
            glfwInit();
            GLFWInitialized = true;
        }

        _window = glfwCreateWindow(static_cast<int>(props.Width), static_cast<int>(props.Height), props.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(_window);
        glfwSetWindowUserPointer(_window, &_data);
        SetVSync(true);

        // GLFW Callbacks
        glfwSetWindowCloseCallback(_window, [](GLFWwindow* window) {
            const WindowData& data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));

            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetWindowSizeCallback(_window, [](GLFWwindow* window, const int width, const int height) {
            WindowData& data = *static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetKeyCallback(_window, [](GLFWwindow* /*window*/, const int key, int /*scancode*/, const int action, int /*mods*/) {
            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedInputEvent event(GlKeyUtil::GlfwKeyToKey(key));
                    Input::ProcessInputEvent(event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedInputEvent event(GlKeyUtil::GlfwKeyToKey(key));
                    Input::ProcessInputEvent(event);
                    break;
                }
                default: break;
            }
        });

        glfwSetCursorPosCallback(_window, [](GLFWwindow* /*window*/, const double xpos, const double ypos) {
            MouseMovedInputEvent event(Vector2(static_cast<float>(xpos), static_cast<float>(ypos)));
            Input::ProcessInputEvent(event);
        });

        glfwSetMouseButtonCallback(_window, [](GLFWwindow* /*window*/, const int button, const int action, int /*mods*/) {
            switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressedInputEvent event(GlKeyUtil::GlfwMouseButtonToMouseButton(button));
                    Input::ProcessInputEvent(event);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleasedInputEvent event(GlKeyUtil::GlfwMouseButtonToMouseButton(button));
                    Input::ProcessInputEvent(event);
                    break;
                }
                default: break;
            }
        });
    }

    void GlWindow::Shutdown() const {
        glfwDestroyWindow(_window);
    }

    void GlWindow::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(_window);
    }

    void GlWindow::SetVSync(const bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }

        _data.VSync = enabled;
    }

    bool GlWindow::IsVSync() const {
        return _data.VSync;
    }
}

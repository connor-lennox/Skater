//
// Created by connor on 1/8/26.
//

#pragma once
#include <string>

#include "Key.h"
#include "MouseButton.h"
#include "Skater/Math/Vector2.h"

namespace Skater {
    enum class InputEventType {
        None = 0,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
        JoystickUpdated
    };

    #define INPUT_EVENT_CLASS_TYPE(type) static InputEventType GetStaticType() { return InputEventType::type; }\
                                            virtual InputEventType GetEventType() const override { return GetStaticType(); } \
                                            virtual const char* GetName() const override { return #type; }

    class InputEvent {
    public:
        virtual ~InputEvent() = default;

        virtual InputEventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual std::string ToString() const { return GetName(); }
    };


    class KeyPressedInputEvent final : public InputEvent {
    public:
        explicit KeyPressedInputEvent(const Key key) : _key(key) {}

        Key GetKey() const { return _key; }

        INPUT_EVENT_CLASS_TYPE(KeyPressed)
    private:
        Key _key;
    };


    class KeyReleasedInputEvent final : public InputEvent {
    public:
        explicit KeyReleasedInputEvent(const Key key) : _key(key) {}

        Key GetKey() const { return _key; }

        INPUT_EVENT_CLASS_TYPE(KeyReleased)
    private:
        Key _key;
    };


    class MouseButtonPressedInputEvent final : public InputEvent {
    public:
        explicit MouseButtonPressedInputEvent(const MouseButton button) : _button(button) {}

        MouseButton GetMouseButton() const { return _button; }

        INPUT_EVENT_CLASS_TYPE(MouseButtonPressed)
    private:
        MouseButton _button;
    };


    class MouseButtonReleasedInputEvent final : public InputEvent {
    public:
        explicit MouseButtonReleasedInputEvent(const MouseButton button) : _button(button) {}

        MouseButton GetMouseButton() const { return _button; }

        INPUT_EVENT_CLASS_TYPE(MouseButtonReleased)
    private:
        MouseButton _button;
    };


    class MouseMovedInputEvent final : public InputEvent {
    public:
        explicit MouseMovedInputEvent(const Vector2 position) : _position(position) {}

        Vector2 GetMousePosition() const { return _position; }

        INPUT_EVENT_CLASS_TYPE(MouseMoved)
    private:
        Vector2 _position;
    };


    class MouseScrolledInputEvent final : public InputEvent {
    public:
        explicit MouseScrolledInputEvent(const float amount) : _amount(amount) {}

        float GetScrollAmount() const { return _amount; }

        INPUT_EVENT_CLASS_TYPE(MouseScrolled)
    private:
        float _amount;
    };
}

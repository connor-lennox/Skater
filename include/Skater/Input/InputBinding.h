//
// Created by connor on 1/7/26.
//

#pragma once
#include "JoystickAxis.h"
#include "JoystickButton.h"
#include "Key.h"
#include "MouseButton.h"

namespace Skater {
    class InputBinding {
    public:
        virtual ~InputBinding() = default;
        virtual float GetValue() = 0;
    };

    class KeyInputBinding final : public InputBinding {
    public:
        explicit KeyInputBinding(Key key);
        float GetValue() override;
    private:
        Key _key = Key::None;
    };

    class MouseButtonInputBinding final : public InputBinding {
    public:
        explicit MouseButtonInputBinding(MouseButton button);
        float GetValue() override;
    private:
        MouseButton _button = MouseButton::None;
    };

    class JoystickButtonInputBinding final : public InputBinding {
    public:
        explicit JoystickButtonInputBinding(const JoystickButton button) : JoystickButtonInputBinding(button, -1) {}
        JoystickButtonInputBinding(JoystickButton button, int joystickIdx);
        float GetValue() override;
    };

    class JoystickAxisInputBinding final : public InputBinding {
    public:
        explicit JoystickAxisInputBinding(const JoystickAxis axis) : JoystickAxisInputBinding(axis, -1) {}
        JoystickAxisInputBinding(JoystickAxis axis, int joystickIdx);
        float GetValue() override;
    };
}

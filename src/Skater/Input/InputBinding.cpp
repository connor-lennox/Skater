//
// Created by connor on 1/7/26.
//

#include "Skater/Input/InputBinding.h"

#include "Skater/Input/Input.h"

namespace Skater {
    KeyInputBinding::KeyInputBinding(const Key key) : _key(key) {}

    float KeyInputBinding::GetValue() {
        return Input::IsKeyPressed(_key) ? 1.0 : 0.0;
    }


    MouseButtonInputBinding::MouseButtonInputBinding(const MouseButton button) : _button(button) {}

    float MouseButtonInputBinding::GetValue() {
        return Input::IsMouseButtonPressed(_button) ? 1.0 : 0.0;
    }


}

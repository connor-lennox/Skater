//
// Created by connor on 1/7/26.
//

#include "Skater/Input/InputAction.h"

#include <cstdio>

namespace Skater {
    InputAction::~InputAction() {
        // Bindings should be owned only by a single Action
        for (const auto binding : _bindings) {
            delete binding;
        }
    }

    void InputAction::Update() {
        _previousValue = _currentValue;

        // The current value of an action is the max of all its bindings
        _currentValue = 0;
        for (InputBinding* binding : _bindings) {
            _currentValue = std::max(_currentValue, binding->GetValue());
        }
    }

    float InputAction::GetValue() const {
        return _currentValue;
    }

    bool InputAction::IsPressed() const {
        return _currentValue > Deadzone;
    }

    bool InputAction::WasJustPressed() const {
        return _currentValue >= Deadzone && _previousValue < Deadzone;
    }

    bool InputAction::WasJustReleased() const {
        return _currentValue < Deadzone && _previousValue >= Deadzone;
    }

    void InputAction::AddBinding(InputBinding *binding) {
        _bindings.push_back(binding);
    }
}

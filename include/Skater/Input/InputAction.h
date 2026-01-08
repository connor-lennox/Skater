//
// Created by connor on 1/7/26.
//

#pragma once
#include <vector>

#include "InputBinding.h"

namespace Skater {
    class InputAction {
    public:
        ~InputAction();

        float Deadzone = 0.2;

        void Update();

        [[nodiscard]] float GetValue() const;

        [[nodiscard]] bool IsPressed() const;
        [[nodiscard]] bool WasJustPressed() const;
        [[nodiscard]] bool WasJustReleased() const;

        void AddBinding(InputBinding* binding);

        InputAction* WithBinding(InputBinding* binding) {
            AddBinding(binding);
            return this;
        }
    private:
        std::vector<InputBinding*> _bindings;
        float _currentValue = 0;
        float _previousValue = 0;
    };
}

//
// Created by connor on 1/7/26.
//

#pragma once
#include "MouseButton.h"
#include "Skater/Math/Vector2.h"

namespace Skater {
    class MouseState {
    public:
        MouseState() = default;
        MouseState(const MouseState &obj) = default;

        void SetPosition(Vector2 position);

        void SetButton(MouseButton button);
        void ClearButton(MouseButton button);

        [[nodiscard]] Vector2 GetPosition() const { return _currentPosition; }
        [[nodiscard]] bool GetButton(MouseButton button) const;
    private:
        Vector2 _currentPosition = Vector2::Zero;
        uint8_t _buttonMask = 0;
    };

    class Mouse {
    public:
        static MouseState GetState();

        static void SetPosition(Vector2 position);

        static void SetButton(MouseButton button);
        static void ClearButton(MouseButton button);
    private:
        static inline MouseState _currentState;
    };
}

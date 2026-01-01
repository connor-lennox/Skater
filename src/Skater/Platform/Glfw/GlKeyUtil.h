//
// Created by connor on 12/17/25.
//

#pragma once
#include <GLFW/glfw3.h>

#include "Skater/Input/Keys.h"

namespace Skater {
    class GlKeyUtil {
    public:
        static Keys GlfwKeyToKeys(const int key) {
            switch (key) {
                case GLFW_KEY_SPACE: return Keys::Space;
                case GLFW_KEY_APOSTROPHE: return Keys::Quotes;
                case GLFW_KEY_COMMA: return Keys::Comma;
                case GLFW_KEY_MINUS: return Keys::Minus;
                case GLFW_KEY_PERIOD: return Keys::Period;
                case GLFW_KEY_SLASH: return Keys::Slash;

                case GLFW_KEY_0: return Keys::D0;
                case GLFW_KEY_1: return Keys::D1;
                case GLFW_KEY_2: return Keys::D2;
                case GLFW_KEY_3: return Keys::D3;
                case GLFW_KEY_4: return Keys::D4;
                case GLFW_KEY_5: return Keys::D5;
                case GLFW_KEY_6: return Keys::D6;
                case GLFW_KEY_7: return Keys::D7;
                case GLFW_KEY_8: return Keys::D8;
                case GLFW_KEY_9: return Keys::D9;

                case GLFW_KEY_SEMICOLON: return Keys::Semicolon;
                case GLFW_KEY_EQUAL: return Keys::Equal;

                case GLFW_KEY_A: return Keys::A;
                case GLFW_KEY_B: return Keys::B;
                case GLFW_KEY_C: return Keys::C;
                case GLFW_KEY_D: return Keys::D;
                case GLFW_KEY_E: return Keys::E;
                case GLFW_KEY_F: return Keys::F;
                case GLFW_KEY_G: return Keys::G;
                case GLFW_KEY_H: return Keys::H;
                case GLFW_KEY_I: return Keys::I;
                case GLFW_KEY_J: return Keys::J;
                case GLFW_KEY_K: return Keys::K;
                case GLFW_KEY_L: return Keys::L;
                case GLFW_KEY_M: return Keys::M;
                case GLFW_KEY_N: return Keys::N;
                case GLFW_KEY_O: return Keys::O;
                case GLFW_KEY_P: return Keys::P;
                case GLFW_KEY_Q: return Keys::Q;
                case GLFW_KEY_R: return Keys::R;
                case GLFW_KEY_S: return Keys::S;
                case GLFW_KEY_T: return Keys::T;
                case GLFW_KEY_U: return Keys::U;
                case GLFW_KEY_V: return Keys::V;
                case GLFW_KEY_W: return Keys::W;
                case GLFW_KEY_X: return Keys::X;
                case GLFW_KEY_Y: return Keys::Y;
                case GLFW_KEY_Z: return Keys::Z;

                case GLFW_KEY_LEFT_BRACKET: return Keys::OpenBrackets;
                case GLFW_KEY_BACKSLASH: return Keys::Backslash;
                case GLFW_KEY_RIGHT_BRACKET: return Keys::CloseBrackets;

                case GLFW_KEY_GRAVE_ACCENT: return Keys::GraveAccent;
                case GLFW_KEY_ESCAPE: return Keys::Escape;
                case GLFW_KEY_ENTER: return Keys::Enter;
                case GLFW_KEY_TAB: return Keys::Tab;
                case GLFW_KEY_BACKSPACE: return Keys::Backspace;
                case GLFW_KEY_INSERT: return Keys::Insert;
                case GLFW_KEY_DELETE: return Keys::Delete;

                case GLFW_KEY_RIGHT: return Keys::Right;
                case GLFW_KEY_LEFT: return Keys::Left;
                case GLFW_KEY_DOWN: return Keys::Down;
                case GLFW_KEY_UP: return Keys::Up;

                case GLFW_KEY_PAGE_UP: return Keys::PageUp;
                case GLFW_KEY_PAGE_DOWN: return Keys::PageDown;
                case GLFW_KEY_HOME: return Keys::Home;
                case GLFW_KEY_END: return Keys::End;

                case GLFW_KEY_CAPS_LOCK: return Keys::CapsLock;
                case GLFW_KEY_SCROLL_LOCK: return Keys::ScrollLock;
                case GLFW_KEY_NUM_LOCK: return Keys::NumLock;

                case GLFW_KEY_PRINT_SCREEN: return Keys::PrintScreen;

                case GLFW_KEY_F1: return Keys::F1;
                case GLFW_KEY_F2: return Keys::F2;
                case GLFW_KEY_F3: return Keys::F3;
                case GLFW_KEY_F4: return Keys::F4;
                case GLFW_KEY_F5: return Keys::F5;
                case GLFW_KEY_F6: return Keys::F6;
                case GLFW_KEY_F7: return Keys::F7;
                case GLFW_KEY_F8: return Keys::F8;
                case GLFW_KEY_F9: return Keys::F9;
                case GLFW_KEY_F10: return Keys::F10;
                case GLFW_KEY_F11: return Keys::F11;
                case GLFW_KEY_F12: return Keys::F12;
                case GLFW_KEY_F13: return Keys::F13;
                case GLFW_KEY_F14: return Keys::F14;
                case GLFW_KEY_F15: return Keys::F15;
                case GLFW_KEY_F16: return Keys::F16;
                case GLFW_KEY_F17: return Keys::F17;
                case GLFW_KEY_F18: return Keys::F18;
                case GLFW_KEY_F19: return Keys::F19;
                case GLFW_KEY_F20: return Keys::F20;
                case GLFW_KEY_F21: return Keys::F21;
                case GLFW_KEY_F22: return Keys::F22;
                case GLFW_KEY_F23: return Keys::F23;
                case GLFW_KEY_F24: return Keys::F24;

                case GLFW_KEY_KP_0: return Keys::NumPad0;
                case GLFW_KEY_KP_1: return Keys::NumPad1;
                case GLFW_KEY_KP_2: return Keys::NumPad2;
                case GLFW_KEY_KP_3: return Keys::NumPad3;
                case GLFW_KEY_KP_4: return Keys::NumPad4;
                case GLFW_KEY_KP_5: return Keys::NumPad5;
                case GLFW_KEY_KP_6: return Keys::NumPad6;
                case GLFW_KEY_KP_7: return Keys::NumPad7;
                case GLFW_KEY_KP_8: return Keys::NumPad8;
                case GLFW_KEY_KP_9: return Keys::NumPad9;

                case GLFW_KEY_KP_DECIMAL: return Keys::Decimal;
                case GLFW_KEY_KP_DIVIDE: return Keys::Divide;
                case GLFW_KEY_KP_MULTIPLY: return Keys::Multiply;
                case GLFW_KEY_KP_SUBTRACT: return Keys::Subtract;
                case GLFW_KEY_KP_ADD: return Keys::Add;
                case GLFW_KEY_KP_ENTER: return Keys::Enter;
                case GLFW_KEY_KP_EQUAL: return Keys::Equal;

                case GLFW_KEY_LEFT_SHIFT: return Keys::LeftShift;
                case GLFW_KEY_LEFT_CONTROL: return Keys::LeftControl;
                case GLFW_KEY_LEFT_ALT: return Keys::LeftAlt;
                case GLFW_KEY_LEFT_SUPER: return Keys::LeftSuper;

                case GLFW_KEY_RIGHT_SHIFT: return Keys::RightShift;
                case GLFW_KEY_RIGHT_CONTROL: return Keys::RightControl;
                case GLFW_KEY_RIGHT_ALT: return Keys::RightAlt;
                case GLFW_KEY_RIGHT_SUPER: return Keys::RightSuper;

                default: return Keys::None;
            }
        }
    };
}

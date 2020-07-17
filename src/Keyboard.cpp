#include "../include/Keyboard.hpp"
#include <GLFW/glfw3.h>

extern "C++" {

    namespace gl {

        namespace priv {

            static int GLToGlfw(const Keyboard::Key &key) {
                switch (key) {
                    case Keyboard::Space:
                        return GLFW_KEY_SPACE;
                    case Keyboard::Apostrophe:
                        return GLFW_KEY_APOSTROPHE;
                    case Keyboard::Comma:
                        return GLFW_KEY_COMMA;
                    case Keyboard::Minus:
                        return GLFW_KEY_MINUS;
                    case Keyboard::Period:
                        return GLFW_KEY_PERIOD;
                    case Keyboard::Slash:
                        return GLFW_KEY_SLASH;
                    case Keyboard::Zero:
                        return GLFW_KEY_0;
                    case Keyboard::One:
                        return GLFW_KEY_1;
                    case Keyboard::Two:
                        return GLFW_KEY_2;
                    case Keyboard::Three:
                        return GLFW_KEY_3;
                    case Keyboard::Four:
                        return GLFW_KEY_4;
                    case Keyboard::Five:
                        return GLFW_KEY_5;
                    case Keyboard::Six:
                        return GLFW_KEY_6;
                    case Keyboard::Seven:
                        return GLFW_KEY_7;
                    case Keyboard::Eight:
                        return GLFW_KEY_8;
                    case Keyboard::Nine:
                        return GLFW_KEY_9;
                    case Keyboard::Semicolon:
                        return GLFW_KEY_SEMICOLON;
                    case Keyboard::Equal:
                        return GLFW_KEY_EQUAL;
                    case Keyboard::A:
                        return GLFW_KEY_A;
                    case Keyboard::B:
                        return GLFW_KEY_B;
                    case Keyboard::C:
                        return GLFW_KEY_C;
                    case Keyboard::D:
                        return GLFW_KEY_D;
                    case Keyboard::E:
                        return GLFW_KEY_E;
                    case Keyboard::F:
                        return GLFW_KEY_F;
                    case Keyboard::G:
                        return GLFW_KEY_G;
                    case Keyboard::H:
                        return GLFW_KEY_H;
                    case Keyboard::I:
                        return GLFW_KEY_I;
                    case Keyboard::J:
                        return GLFW_KEY_J;
                    case Keyboard::K:
                        return GLFW_KEY_K;
                    case Keyboard::L:
                        return GLFW_KEY_L;
                    case Keyboard::M:
                        return GLFW_KEY_M;
                    case Keyboard::N:
                        return GLFW_KEY_N;
                    case Keyboard::O:
                        return GLFW_KEY_O;
                    case Keyboard::P:
                        return GLFW_KEY_P;
                    case Keyboard::Q:
                        return GLFW_KEY_Q;
                    case Keyboard::R:
                        return GLFW_KEY_R;
                    case Keyboard::S:
                        return GLFW_KEY_S;
                    case Keyboard::T:
                        return GLFW_KEY_T;
                    case Keyboard::U:
                        return GLFW_KEY_U;
                    case Keyboard::V:
                        return GLFW_KEY_V;
                    case Keyboard::W:
                        return GLFW_KEY_W;
                    case Keyboard::X:
                        return GLFW_KEY_X;
                    case Keyboard::Y:
                        return GLFW_KEY_Y;
                    case Keyboard::Z:
                        return GLFW_KEY_Z;
                    case Keyboard::LeftBracket:
                        return GLFW_KEY_LEFT_BRACKET;
                    case Keyboard::RightBracket:
                        return GLFW_KEY_RIGHT_BRACKET;
                    case Keyboard::BackSlash:
                        return GLFW_KEY_BACKSLASH;
                    case Keyboard::GraveAccent:
                        return GLFW_KEY_GRAVE_ACCENT;
                    case Keyboard::World1:
                        return GLFW_KEY_WORLD_1;
                    case Keyboard::World2:
                        return GLFW_KEY_WORLD_2;
                    case Keyboard::Escape:
                        return GLFW_KEY_ESCAPE;
                    case Keyboard::Enter:
                        return GLFW_KEY_ENTER;
                    case Keyboard::Tab:
                        return GLFW_KEY_TAB;
                    case Keyboard::Backspace:
                        return GLFW_KEY_BACKSPACE;
                    case Keyboard::Insert:
                        return GLFW_KEY_INSERT;
                    case Keyboard::Delete:
                        return GLFW_KEY_DELETE;
                    case Keyboard::Up:
                        return GLFW_KEY_UP;
                    case Keyboard::Left:
                        return GLFW_KEY_LEFT;
                    case Keyboard::Right:
                        return GLFW_KEY_RIGHT;
                    case Keyboard::Down:
                        return GLFW_KEY_DOWN;
                    case Keyboard::PageUp:
                        return GLFW_KEY_PAGE_UP;
                    case Keyboard::PageDown:
                        return GLFW_KEY_PAGE_DOWN;
                    case Keyboard::Home:
                        return GLFW_KEY_HOME;
                    case Keyboard::End:
                        return GLFW_KEY_END;
                    case Keyboard::CapsLock:
                        return GLFW_KEY_CAPS_LOCK;
                    case Keyboard::ScrollLock:
                        return GLFW_KEY_SCROLL_LOCK;
                    case Keyboard::NumLock:
                        return GLFW_KEY_NUM_LOCK;
                    case Keyboard::PrintScreen:
                        return GLFW_KEY_PRINT_SCREEN;
                    case Keyboard::Pause:
                        return GLFW_KEY_PAUSE;
                    case Keyboard::F1:
                        return GLFW_KEY_F1;
                    case Keyboard::F2:
                        return GLFW_KEY_F2;
                    case Keyboard::F3:
                        return GLFW_KEY_F3;
                    case Keyboard::F4:
                        return GLFW_KEY_F4;
                    case Keyboard::F5:
                        return GLFW_KEY_F5;
                    case Keyboard::F6:
                        return GLFW_KEY_F6;
                    case Keyboard::F7:
                        return GLFW_KEY_F7;
                    case Keyboard::F8:
                        return GLFW_KEY_F8;
                    case Keyboard::F9:
                        return GLFW_KEY_F9;
                    case Keyboard::F10:
                        return GLFW_KEY_F10;
                    case Keyboard::F11:
                        return GLFW_KEY_F11;
                    case Keyboard::F12:
                        return GLFW_KEY_F12;
                    case Keyboard::F13:
                        return GLFW_KEY_F13;
                    case Keyboard::F14:
                        return GLFW_KEY_F14;
                    case Keyboard::F15:
                        return GLFW_KEY_F15;
                    case Keyboard::F16:
                        return GLFW_KEY_F16;
                    case Keyboard::F17:
                        return GLFW_KEY_F17;
                    case Keyboard::F18:
                        return GLFW_KEY_F18;
                    case Keyboard::F19:
                        return GLFW_KEY_F19;
                    case Keyboard::F20:
                        return GLFW_KEY_F20;
                    case Keyboard::F21:
                        return GLFW_KEY_F21;
                    case Keyboard::F22:
                        return GLFW_KEY_F22;
                    case Keyboard::F23:
                        return GLFW_KEY_F23;
                    case Keyboard::F24:
                        return GLFW_KEY_F24;
                    case Keyboard::F25:
                        return GLFW_KEY_F25;
                    case Keyboard::Num0:
                        return GLFW_KEY_KP_0;
                    case Keyboard::Num1:
                        return GLFW_KEY_KP_1;
                    case Keyboard::Num2:
                        return GLFW_KEY_KP_2;
                    case Keyboard::Num3:
                        return GLFW_KEY_KP_3;
                    case Keyboard::Num4:
                        return GLFW_KEY_KP_4;
                    case Keyboard::Num5:
                        return GLFW_KEY_KP_5;
                    case Keyboard::Num6:
                        return GLFW_KEY_KP_6;
                    case Keyboard::Num7:
                        return GLFW_KEY_KP_7;
                    case Keyboard::Num8:
                        return GLFW_KEY_KP_8;
                    case Keyboard::Num9:
                        return GLFW_KEY_KP_9;
                    case Keyboard::NumDecimal:
                        return GLFW_KEY_KP_DECIMAL;
                    case Keyboard::NumDivide:
                        return GLFW_KEY_KP_DIVIDE;
                    case Keyboard::NumMultiply:
                        return GLFW_KEY_KP_MULTIPLY;
                    case Keyboard::NumSubtract:
                        return GLFW_KEY_KP_SUBTRACT;
                    case Keyboard::NumAdd:
                        return GLFW_KEY_KP_ADD;
                    case Keyboard::NumEnter:
                        return GLFW_KEY_KP_ENTER;
                    case Keyboard::NumEqual:
                        return GLFW_KEY_KP_EQUAL;
                    case Keyboard::LShift:
                        return GLFW_KEY_LEFT_SHIFT;
                    case Keyboard::RShift:
                        return GLFW_KEY_RIGHT_SHIFT;
                    case Keyboard::LControl:
                        return GLFW_KEY_LEFT_CONTROL;
                    case Keyboard::RControl:
                        return GLFW_KEY_RIGHT_CONTROL;
                    case Keyboard::LAlt:
                        return GLFW_KEY_LEFT_ALT;
                    case Keyboard::RAlt:
                        return GLFW_KEY_RIGHT_ALT;
                    case Keyboard::LSuper:
                        return GLFW_KEY_LEFT_SUPER;
                    case Keyboard::RSuper:
                        return GLFW_KEY_RIGHT_SUPER;
                    case Keyboard::Menu:
                        return GLFW_KEY_MENU;
                    default:
                        return GLFW_KEY_UNKNOWN;
                }

            }

        }

        namespace Keyboard {

            bool isKeyPressed(const Key &key) { return glfwGetKey(glfwGetCurrentContext(), priv::GLToGlfw(key)) == GLFW_PRESS; }

        }

    }

}
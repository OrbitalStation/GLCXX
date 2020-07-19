#ifndef GLCXX_LOW
#define GLCXX_LOW

#include "Keyboard.hpp"

extern "C++" {

    namespace gl {

        class Window;

        namespace low {

            void viewport(const int &x, const int &y, const int &width, const int &height);

            typedef void(*CursorMoveCallback)(Window &window, const float &x, const float &y);

            void setCursorMoveCallback(const Window &window, const CursorMoveCallback &callback);

            typedef void(*WindowResizeCallback)(Window &window, const unsigned int &width, const unsigned int &height);

            void setWindowResizeCallback(const Window &window, const WindowResizeCallback &callback);

            typedef void (*MouseWheelScroll)(Window &window, const float &offsetX, const float &offsetY);

            void setMouseWheelScrollCallback(const Window &window, const MouseWheelScroll &callback);

            typedef void (*KeyCallback)(Window &window, const Keyboard::Key &key, const int &scanCode,
                    const Keyboard::KeyType &type);

            void setKeyCallback(const Window &window, const KeyCallback &callback);

        }

    }

}

#endif /* GLCXX_LOW */

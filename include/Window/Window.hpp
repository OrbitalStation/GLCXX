#ifndef GLCXX_WINDOW
#define GLCXX_WINDOW

#include "../Color.hpp"
#include "../System/Drawable.hpp"
#include "Event.hpp"
#include "View.hpp"

extern "C++" {

    namespace gl {

        class Window {

        public:

            Window(const unsigned int &width, const unsigned int &height, const char * const &title);

            void setView(View &view);

            bool isOpen();

            void clear(const Color &color = Color::Black);

            void refresh();

            bool pollEvents(Event &event);

            void close();

            void destroy();

            void draw(Drawable &drawable);

        private:

            void *data;

            View *camera;

        };

    }

}

#endif /* GLCXX_WINDOW */

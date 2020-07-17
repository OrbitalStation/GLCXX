#ifndef GLCXX_MAIN
#define GLCXX_MAIN

#include "System/Config.hpp"

extern "C++" {

    namespace gl {

        void init();

        void terminate();

        double getTime();

    }

}

#endif /* GLCXX_MAIN */

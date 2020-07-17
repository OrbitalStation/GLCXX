#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "../include/Window/Window.hpp"

extern "C++" {

    namespace gl {

        namespace priv { unsigned int shaderProgram; }

        Window::Window(const unsigned int &width, const unsigned int &height, const char * const &title) :
                camera(nullptr) {
            this->data = (void *)(glfwCreateWindow(int(width), int(height), title, nullptr, nullptr));
            if (this->data == nullptr) throw error("Cannot create window");
            glfwMakeContextCurrent((GLFWwindow *)this->data);
            static bool is_first_time = false;
            if (!is_first_time) {

                if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) == 0)
                    throw error("Cannot load OpenGL functions");

                int success;

                char log[512];

                const char *vertexShaderSource = "#version 330 core\n"
                                                 "layout (location = 0) in vec3 pos;\n"
                                                 "layout (location = 1) in vec4 color;\n"
                                                 "out vec4 _color;\n"
                                                 "uniform mat4 projection;\n"
                                                 "uniform mat4 view;\n"
                                                 "uniform mat4 model;\n"
                                                 "void main() {\n"
                                                 "    gl_Position = projection * view * model * vec4(pos, 1.f);\n"
                                                 "    _color = color;\n"
                                                 "}\n\0";

                unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

                glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);

                glCompileShader(vertexShader);

                glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

                if (success == 0) {
                    glGetShaderInfoLog(vertexShader, 512, nullptr, log);
                    throw error((std::string("Cannot create vertex shader: ") + log).c_str());
                }

                const char *fragmentShaderSource = "#version 330 core\n"
                                                   "in vec4 _color;\n"
                                                   "out vec4 FragColor;\n"
                                                   "void main() {\n"
                                                   "    FragColor = _color;\n"
                                                   "}\n\0";

                unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

                glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);

                glCompileShader(fragmentShader);

                glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

                if (success == 0) {
                    glGetShaderInfoLog(fragmentShader, 512, nullptr, log);
                    throw error((std::string("Cannot create fragment shader: ") + log).c_str());
                }

                priv::shaderProgram = glCreateProgram();

                glAttachShader(priv::shaderProgram, vertexShader);

                glAttachShader(priv::shaderProgram, fragmentShader);

                glLinkProgram(priv::shaderProgram);

                glGetProgramiv(priv::shaderProgram, GL_LINK_STATUS, &success);

                if (success == 0) {
                    glGetProgramInfoLog(priv::shaderProgram, 512, nullptr, log);
                    throw error((std::string("Cannot create shader program: ") + log).c_str());
                }

                glDeleteShader(vertexShader);

                glDeleteShader(fragmentShader);

                glUseProgram(priv::shaderProgram);

                glEnable(GL_DEPTH_TEST);

                is_first_time = true;
            }
        }

        void Window::setView(View &view) {
            this->camera = &view;
        }

        bool Window::isOpen() { return !glfwWindowShouldClose((GLFWwindow *)this->data); }

        void Window::clear(const Color &color) {
            if (glfwGetCurrentContext() != (GLFWwindow *)this->data) return;
            glClearColor(Color::toFloat(color.r), Color::toFloat(color.g), Color::toFloat(color.b), Color::toFloat(color.a));
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void Window::refresh() {
            this->camera->flush();
            glfwSwapBuffers((GLFWwindow *)this->data);
        }

        bool Window::pollEvents(Event &event) {
            event.clear();
            if (glfwGetCurrentContext() != (GLFWwindow *)this->data || glfwWindowShouldClose((GLFWwindow *)this->data)) return false;
            glfwPollEvents();
            if (glfwWindowShouldClose((GLFWwindow *)this->data)) {
                glfwSetWindowShouldClose((GLFWwindow *)this->data, GLFW_FALSE);
                event.type = Event::windowClosed;
                return true;
            }
            return false;
        }

        void Window::close() { glfwSetWindowShouldClose((GLFWwindow *)this->data, GLFW_TRUE); }

        void Window::destroy() { glfwDestroyWindow((GLFWwindow *)this->data); }

        void Window::draw(Drawable &drawable) {
            if (this->data == nullptr || this->camera == nullptr) return;
            if (glfwGetCurrentContext() != (GLFWwindow *)this->data) return;
            if (glfwWindowShouldClose((GLFWwindow *)this->data)) return;
            drawable.draw();
        }

    }

}

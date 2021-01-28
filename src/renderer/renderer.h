#pragma once

#include <iostream>
#include "glad/gl.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


namespace renderer
{
    const char* test();

    class Window
    {
        // member variables
        private:
            const char* m_title;
            int m_width, m_height;
            GLFWwindow* m_internal_window;
            bool m_closed;
        // methods
        public:
            Window(const char* title, int width, int height);
            ~Window();
            void update() const;
            bool is_closed() const;
        private:
            bool init();
    };
}

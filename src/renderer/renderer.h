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
            void clear() const;
            void update();
            bool is_closed() const;
            inline int get_width() const { return m_width; };
            inline int get_height() const { return m_height; };
        private:
            bool init();
    };
}

#include "renderer.h"

namespace renderer
{
    const char* test()
    {
        const char* stringy = "Hello renderer!";
        return stringy;
    }

    Window::Window(const char* title, int width, int height)
    {
        m_title = title;
        m_width = width;
        m_height = height;
        if (!init()) 
            glfwTerminate();
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    bool Window::init()
    {
        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            return false;
        }
        
        m_internal_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
        if (!m_internal_window)
        {
            std::cerr << "Failed to create GLFW window." << std::endl;
            return false;
        }
        glfwMakeContextCurrent(m_internal_window);

        return true;
    }

    void Window::update() const
    {
        glfwPollEvents();
        glfwSwapBuffers(m_internal_window);
    }

    bool Window::is_closed() const
    {
        // return m_closed;
        return glfwWindowShouldClose(m_internal_window);
    }
}

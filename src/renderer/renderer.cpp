#include "renderer.h"


namespace FakeEngine
{
    namespace renderer
    {
        const char* test()
        {
            const char* stringy = "Hello renderer!";
            return stringy;
        }

        void resize_GLFW_window(GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);
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

            if (!gladLoadGL(glfwGetProcAddress))
            {
                std::cerr << "Failed to initialize glad" << std::endl;
                return false;
            }

            glfwSetWindowSizeCallback(m_internal_window, resize_GLFW_window);
            
            glClearColor(0.f, 0.25f, 1.f, 1.f);

            return true;
        }

        void Window::clear() const
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void Window::update()
        {
            glfwPollEvents();
            glfwGetFramebufferSize(m_internal_window, &m_width, &m_height);
            glfwSwapBuffers(m_internal_window);
        }

        bool Window::is_closed() const
        {
            // return m_closed;
            return glfwWindowShouldClose(m_internal_window) == 1;
        }
    }
}
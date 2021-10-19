#pragma once

// #include "ExternalLibraries.h"
#include "logger/logger.h"
#include "glad/gl.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"


namespace FakeEngine
{
    namespace renderer
    {
        const char* test();

        class Window
        {
            // member variables
            private:
                Logger windowlogger;
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
                inline void set_width(int width) { m_width = width; };
                inline void set_height(int height) { m_height = height; };
                static void resize_GLFW_window(GLFWwindow* window, 
                    int width, int height);
            private:
                bool init();
        };

        class Core
        {
        private:
            /* data */
        public:
            Core(/* args */);
            ~Core();
            /**
             * These functions are to be called according to the
             * RenderMeAttrib's pointer to the appropriate render function.
             * The presence of this RenderMeAttrib also determines whether the
             * Substance gets rendered.
             */
            void render_sprite();  // Todo
            void render_vector();  // Todo
        };
    }
}

#include <iostream>
#include "renderer.h"


int main() {
    using namespace renderer;

    std::cout << "Hello, FakeLara!" << std::endl;

    Window window("Hello, FakeLara!", 800, 600);
    glClearColor(0.f, 0.25f, 1.f, 1.f);
    std::cout << glGetString(GL_VERSION) << std::endl;

    while (!window.is_closed())
    {
        std::cout << window.get_width() << ", "
        << window.get_height() << std::endl;

        window.clear();
        glBegin(GL_TRIANGLES);
        glVertex2f(-1.0f, 0.f);
        glVertex2f(1.0f, 0.f);
        glVertex2f(0.f, 0.7f);
        glEnd();
        window.update();
    }

    return 0;
}

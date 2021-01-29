#include "FakeEngine.h"


int main()
{
    using namespace FakeEngine;

    std::cout << "I'm in!" << std::endl;

    renderer::Window window("Hello, FakeLara!", 800, 600);

    while (!window.is_closed())
    {
        std::cout << window.get_width() << ", "
        << window.get_height() << std::endl;

        window.clear();
        glBegin(GL_TRIANGLES);
        glVertex2f(-1.0f, 0.0f);
        glVertex2f( 1.0f, 0.0f);
        glVertex2f( 0.0f, 0.7f);
        glEnd();
        window.update();
    }

    return 0;
}

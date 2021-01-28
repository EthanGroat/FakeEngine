#include <iostream>
#include "renderer.h"


int main() {
    using namespace renderer;

    std::cout << "Hello, FakeLara!" << std::endl;

    Window window("Hello, FakeLara!", 800, 600);
    glClearColor(0.f, 0.25f, 1.f, 1.f);

    while (!window.is_closed())
    {
        window.update();
    }

    return 0;
}

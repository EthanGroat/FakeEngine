#include <iostream>
#include "renderer.h"


int main() {
    using namespace renderer;

    std::cout << "Hello, FakeLara!" << std::endl;

    Window window("Hello, FakeLara!", 800, 600);

    while (!window.is_closed())
    {
        window.update();
    }

    return 0;
}

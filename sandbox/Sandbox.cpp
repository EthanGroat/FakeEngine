#include "FakeEngine.h"


class SandboxApp : public FakeEngine::Application
{
    public:
        void run()
        {
            std::cout << "running sandbox..." << std::endl;

            FakeEngine::renderer::Window window("Hello, FakeLara!", 800, 600);

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
        }
};


// Entry into FakeEngine
int main()
{
    return FakeEngine::run_application(new SandboxApp());
}

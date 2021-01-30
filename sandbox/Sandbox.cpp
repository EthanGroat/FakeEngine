#include "FakeEngine.h"


class SandboxApp : public FakeEngine::Application
{
    public:
        /* run() contains the main code of your FakeEngine Application */
        void run()
        {
            std::cout << "running sandbox..." << std::endl;

            FakeEngine::Logger log = FakeEngine::Logger();

            FakeEngine::renderer::Window window("Hello, FakeLara!", 800, 600);

            float vertices[3][2] = {
                {-0.8f, 0.0f},
                { 0.8f, 0.0f},
                { 0.0f, 0.9f}
            };

            unsigned int buffers[] = {0, 0, 0, 0};
            glGenBuffers(4, buffers);

            glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0);
            glBufferData(GL_ARRAY_BUFFER, 
                6*sizeof(float), 
                vertices, 
                GL_STATIC_DRAW
            );

            while (!window.is_closed())
            {
                // std::cout << window.get_width() << ", "
                // << window.get_height() << std::endl;

                window.clear();
                
                glDrawArrays(GL_TRIANGLES, 0, 3);

                window.update();
            }
        }
};


// Entry into FakeEngine
int main()
{
    return FakeEngine::run_application(new SandboxApp());
}

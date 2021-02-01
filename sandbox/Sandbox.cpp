#include "FakeEngine.h"


class SandboxApp : public FakeEngine::Application
{
    // member variables
    private:
        FakeEngine::Logger clientlogger;

    // methods
    public:
        SandboxApp():  // our app constructor
          clientlogger(FAKELOGGER_CYAN)  // initialize our custom logger
        {
            clientlogger.printl("Hi from inside SandboxApp constructor!");
        }
        
        ~SandboxApp()  // our destructor
        {
        }

        /* run() contains the main code of your FakeEngine Application */
        void run()
        {
            clientlogger.print(FAKELOGGER_GREEN, "running sandbox...\n");

            FakeEngine::renderer::Window window("Hello, FakeLara!", 960, 540);

            vector_2d vert[3] = {
                {-0.8f, 0.0f},
                { 0.8f, 0.00006723411f},
                { 0.0f, 0.93246f}
            };

            clientlogger.set_color(FAKELOGGER_VIOLET);
            clientlogger.printl("Triangle buffer:");
            clientlogger.print_array(vert, 3);

            clientlogger.printl();
            clientlogger.print("Event Category identifier for Application: ");
            clientlogger.printl(EveCatApplication);


            unsigned int buffers[] = {0, 0, 0, 0};
            glGenBuffers(4, buffers);

            glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vector_2d), 0);
            glBufferData(GL_ARRAY_BUFFER, 
                3*sizeof(vector_2d), 
                vert, 
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
int main(int argc, char* argv[])
{
    return FakeEngine::run_application(new SandboxApp());
}

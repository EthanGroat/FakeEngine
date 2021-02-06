#include "FakeEngine.h"

using namespace FakeEngine;

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

            FakeList f = FakeList<vector_2d>();
            f.initialize(vert, 3);

            clientlogger.set_color(FAKELOGGER_VIOLET);
            clientlogger.printl("Triangle array buffer:");
            clientlogger.print_array(vert, 3);
            clientlogger.printl();

            clientlogger.printl("Now the same using my custom resizable list:");
            clientlogger.print_array(f.get_internal_array(), 3);
            clientlogger.print("number of items: ");
            clientlogger.printl(f.length());
            clientlogger.print("variable internal buffer size (in items): ");
            clientlogger.printl(f.internal_buffer_length());
            clientlogger.printl();

            clientlogger.set_color(FAKELOGGER_CYAN);
            int arr[16] = {0};
            const char* hi = "Hi:D";
            for (int i=0; i<4; ++i)
                arr[i] = hi[i];
            Event* test_event = new Event(EveTypeCustom, 1, arr);
            clientlogger.print_event(test_event);

            unsigned int buffers[] = {0, 0, 0, 0};
            glGenBuffers(4, buffers);

            glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vector_2d), 0);
            glBufferData(GL_ARRAY_BUFFER, 
                3*sizeof(vector_2d), 
                f.get_internal_array(),
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

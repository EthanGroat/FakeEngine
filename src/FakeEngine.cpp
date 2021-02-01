#include "FakeEngine.h"


namespace FakeEngine
{
    Application::Application()
    {
        fakelogger = Logger(FAKELOGGER_BLUE, "Hello from engine logger.");
    }
    
    Application::~Application()
    {
    }
    
    /* run() contains the main code of your FakeEngine Application
    (must be implemented in client applications) */
    void Application::run()
    {
        fakelogger.printl("running engine library default code...");
        fakelogger.printl("(Did you forget to implement your application's run() function?)");
    }

    /**** ENTRY POINT ****/
    int run_application(Application* app)
    {
        app->run();
        delete app;

        return 0;
    }
}

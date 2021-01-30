#include "FakeEngine.h"


namespace FakeEngine
{
    Application::Application()
    {
    }
    
    Application::~Application()
    {
    }
    
    /* run() contains the main code of your FakeEngine Application
    (must be implemented in client applications) */
    void Application::run()
    {
        std::cout << "running engine library default code..." << std::endl
        << "(Did you forget to implement your application's run() function?)"
        << std::endl;
    }

    /**** ENTRY POINT ****/
    int run_application(Application* app)
    {
        app->run();
        delete app;

        return 0;
    }
}

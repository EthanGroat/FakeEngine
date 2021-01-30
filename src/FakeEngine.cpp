#include "FakeEngine.h"


namespace FakeEngine
{    

    Application::Application(/* args */)
    {
    }
    
    Application::~Application()
    {
    }
    
    /* run must be overridden to run a FakeEngine Application */
    void Application::run()
    {
        std::cout << "running engine library code..." << std::endl
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

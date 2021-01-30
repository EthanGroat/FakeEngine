#include <iostream>
#include "renderer.h"


namespace FakeEngine
{
    class Application
    {
    private:
        /* data */
    public:
        Application(/* args */);
        virtual ~Application();
        virtual void run();
    };
    
    /**** ENTRY POINT ****/
    int run_application(Application* app);
}


#include <iostream>
#include "renderer.h"
#include "logger.h"
#include "types.h"


namespace FakeEngine
{
    class Application
    {
      private:
        /* data */
      public:
        Application();
        virtual ~Application();
        virtual void run();
    };
    
    /**** ENTRY POINT ****/
    int run_application(Application* app);
}


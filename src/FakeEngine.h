#include "renderer.h"
#include "types.h"
#include "logger.h"
#include "event.h"


namespace FakeEngine
{
    class Application
    {
      private:
        Logger fakelogger;
      public:
        Application();
        virtual ~Application();
        virtual void run();
    };
    
    /**** ENTRY POINT ****/
    int run_application(Application* app);
}


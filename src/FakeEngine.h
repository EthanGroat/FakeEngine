#pragma once

/** 
 * #include "ExternalLibraries.h" 
 * must be included if client applications are not using the 
 * precompiled ExternalLibraries header.
 */
#include "renderer.h"
#include "types.h"
#include "logger.h"
#include "entt/entt.hpp"
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


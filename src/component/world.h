#pragma once

// #include "ExternalLibraries.h"
#include "renderer/renderer.h"
#include "gameobject.h"
#include "boost/graph/tree_traits.hpp"


namespace FakeEngine
{
    // Tree World;

    class WorldManager
    {
        private:
            /* data */
        protected:
                static WorldManager* instance;
                WorldManager() {}  // protected constructor for singleton
        public:
            ///@brief THERE CAN BE ONLY ONE
            ///@return Highlander
            static WorldManager* get_instance()
            {
                if (!instance)
                    instance = new WorldManager;
                return instance;
            }
            ~WorldManager();

            FRAMETIME_T update();

    };
    WorldManager* WorldManager::instance = nullptr;
}

#pragma once

#include "types.h"
#include <entt.hpp>


namespace FakeEngine
{
    typedef struct entity entity;
    struct entity
    {
        u_int32_t id;
    };


    /** @brief sigleton Universe, unless and until I make a multiverse.
     * This holds references to the scenes and all entities and components 
     * in them
     */
    class Universe
    {
    protected:
        static Universe* instance;
        Universe() {}
    public:
        ///@brief THERE CAN BE ONLY ONE
        ///@return The Highlander
        static Universe* get_instance()
        {
            if (!instance)
                instance = new Universe;
            return instance;
        }
    };
    
}

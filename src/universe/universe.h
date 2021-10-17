#pragma once

#include "types.h"
#include "entt/entt.hpp"


namespace FakeEngine
{
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
    
    /*
    possible usage ideas:
    my_scene = Universe.get_instance().create_scene();
    my_scene.add_entity(Entity("Box", transform_2d));

    box_ent = my_scene.get_entity("Box");
    box_ent.set_parent(other_ent);
    box_ent.transform_add(delta_position);  // uses transform component

    box_ent.add_component(
            Universe.new_component<SoundEffect>(
                "media/boxsounds.wav", 
                plays_by_default=false
                )
        )
    */


    class Entity
    {
    private:
        entt::entity m_entity_handle;
        Universe* m_the_universe;
    public:
        Entity()
        {
            m_the_universe = Universe::get_instance();
        }
    };
}

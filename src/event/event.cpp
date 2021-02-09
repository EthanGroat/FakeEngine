#include "event.h"


using namespace FakeEngine;

void Event::post()
{
    EventBoard::get_instance()->post_event(*this);
}

void EventBoard::handle_events()
{
    iterator = 0;
    while (iterator < event_bus.length())
    {
        sub_table->dispatch(next_event());
        ++iterator;
    }
    event_bus.clear();
}


#pragma once

#include "types.h"
#include <stdarg.h>
#include <time.h>
#include <map>
#include <list>


#define EVENT_C_SHIFT (16)
#define EVENT_T_SHIFT (12)

#define EVENT_PAYLOAD_TYPE     int
#define EVENT_PAYLOAD_LENGTH  (16)


namespace FakeEngine
{
    enum EventCategory
    {
        EveCatNone          =                         0,
        EveCatApplication   =  (1 << 0 + EVENT_C_SHIFT),
        EveCatKeyboard      =  (1 << 1 + EVENT_C_SHIFT),
        EveCatMouseMovem    =  (1 << 2 + EVENT_C_SHIFT),
        EveCatMouseButton   =  (1 << 3 + EVENT_C_SHIFT),
        EveCatMouseScroll   =  (1 << 4 + EVENT_C_SHIFT),
        EveCatCustom        =  (1 << 5 + EVENT_C_SHIFT),
    };

    int EVENT_C_BITMASK = 0xFFFFFFFF << EVENT_C_SHIFT;

    enum EventType
    {
        EveTypeNone                =                                         0,
        EveTypeWindowClose         =  EveCatApplication + (1 << EVENT_T_SHIFT),
        EveTypeWindowResize        =  EveCatApplication + (2 << EVENT_T_SHIFT),
        EveTypeWindowFocus         =  EveCatApplication + (3 << EVENT_T_SHIFT),
        EveTypeWindowLostFocus     =  EveCatApplication + (4 << EVENT_T_SHIFT),
        EveTypeAppTick             =  EveCatApplication + (5 << EVENT_T_SHIFT),
        EveTypeAppUpdate           =  EveCatApplication + (6 << EVENT_T_SHIFT),
        EveTypeKeyPressed          =  EveCatKeyboard    + (1 << EVENT_T_SHIFT),
        EveTypeKeyReleased         =  EveCatKeyboard    + (2 << EVENT_T_SHIFT),
        EveTypeMouseMoved          =  EveCatMouseMovem  + (1 << EVENT_T_SHIFT),
        EveTypeMouseButtonPressed  =  EveCatMouseButton + (1 << EVENT_T_SHIFT),
        EveTypeMouseButtonReleased =  EveCatMouseButton + (2 << EVENT_T_SHIFT),
        EveTypeMouseScrolled       =  EveCatMouseScroll + (1 << EVENT_T_SHIFT),
        EveTypeCustom              =  EveCatCustom      + (1 << EVENT_T_SHIFT),
    };

    int EVENT_T_BITMASK = 0xFFFFFFFF << EVENT_T_SHIFT;

    // here for debugging support
    static std::map<int, const char*> event_type_strings
    {
        { EveTypeNone                ,  "EveTypeNone"               },
        { EveTypeWindowClose         ,  "EveTypeWindowClose"        },
        { EveTypeWindowResize        ,  "EveTypeWindowResize"       },
        { EveTypeWindowFocus         ,  "EveTypeWindowFocus"        },
        { EveTypeWindowLostFocus     ,  "EveTypeWindowLostFocus"    },
        { EveTypeAppTick             ,  "EveTypeAppTick"            },
        { EveTypeAppUpdate           ,  "EveTypeAppUpdate"          },
        { EveTypeKeyPressed          ,  "EveTypeKeyPressed"         },
        { EveTypeKeyReleased         ,  "EveTypeKeyReleased"        },
        { EveTypeMouseMoved          ,  "EveTypeMouseMoved"         },
        { EveTypeMouseButtonPressed  ,  "EveTypeMouseButtonPressed" },
        { EveTypeMouseButtonReleased ,  "EveTypeMouseButtonReleased"},
        { EveTypeMouseScrolled       ,  "EveTypeMouseScrolled"      },
        { EveTypeCustom              ,  "EveTypeCustom"             },
    };

    class Event
    {
        private:
            // bit string that holds the EventCategory, EventType, and Event id.
            int m_event_signature;
            time_t m_timestamp;
            EVENT_PAYLOAD_TYPE m_payload[EVENT_PAYLOAD_LENGTH];

        public:
            ///@param type takes an EventType
            ///@param id describes the specific event in more granular detail than just EventType, such as which specific key is being pressed/released
            Event(EventType type, int id):
                m_event_signature(type | (id & ~EVENT_T_BITMASK)),
                m_timestamp(time(NULL))
            {}
            ///@param type What is this event's EventType?
            ///@param id describes the specific event in more granular detail than just EventType, such as which specific key is being pressed or released.
            ///@param payload an array of integers for extra info which may be needed by some event listeners; array should be of length 16. Although the payload is a specific type, it can be interpreted differently by different event handling scripts.
            Event(EventType type, int id, EVENT_PAYLOAD_TYPE* payload):
                m_event_signature(type | (id & ~EVENT_T_BITMASK)),
                m_timestamp(time(NULL))
            {
                for (int i = 0; i < EVENT_PAYLOAD_LENGTH; ++i)
                    m_payload[i] = payload[i];
            }
            
            inline bool is(EventCategory category) const
                { return m_event_signature & category == category; }
            inline bool is(EventType type) const
                { return m_event_signature & type == type; }
            inline EventCategory get_event_category() const
                { return (EventCategory)(m_event_signature & EVENT_C_BITMASK); }
            inline EventType get_event_type() const
                { return (EventType)(m_event_signature & EVENT_T_BITMASK); }
            // here for debugging support
            inline const char* get_event_type_name() const
                { return event_type_strings[get_event_type()]; }

            /* 
             * @brief This is what is used to subscribe to a particular event.
             * @return the signature for the event, which encodes the event 
             * category, type & id
             */
            inline int signature()
            {
                return m_event_signature;
            }
            inline int timestamp()
            {
                return m_timestamp;
            }
            /*
             * @brief The event's payload is a fixed length array of integers, 
             * but despite this limitation, it can be interpreted differently 
             * by different event handling functions. Creative uses include 
             * interpreting parts of the data as a list of signed 64-bit 
             * fixed-point numbers for position, scaling, rotation, forces or 
             * impulses; a couple of game object ids for a collision event and 
             * the vertex or point in space at which they collided, and maybe 
             * even the momentums with which they collided, in order to compute 
             * a post-collision velocity vector for both objects; a short 
             * message composed of chars, etc.
             * @return a pointer to the payload
             */
            inline EVENT_PAYLOAD_TYPE* payload()
            {
                return m_payload;
            }
    };

    class Subscription
    {
        public:
            int event_signature;
            bool (*callback_function)(int*);

            // Allow sorting by event_signature for logarithmic time complexity during accesses in the subscription record
            int operator <(Subscription other)
            {
                if (event_signature < other.event_signature)
                    return 1;
                else
                    return 0;                
            }
    };

    // Singleton subscription record: a structure to hold all subscriptions
    class SubscriptionTable
    {
        public:
            std::map<int, FakeList<Subscription>> records;
        protected:
            static SubscriptionTable* instance;
            SubscriptionTable() {}  // protected constructor
        public:
            ///@brief THERE CAN BE ONLY ONE
            ///@return Highlander
            static SubscriptionTable* get_instance()
            {
                if (!instance)
                    instance = new SubscriptionTable;
                return instance;
            }
    };
    SubscriptionTable* SubscriptionTable::instance = nullptr;

    class EventBoard
    {
        protected:
            static EventBoard* instance;
            FakeList<Event> event_bus;
            EventBoard() {}
        public:
            ///@brief THERE CAN BE ONLY ONE
            ///@return Highlander
            static EventBoard* get_instance()
            {
                if (!instance)
                    instance = new EventBoard;
                return instance;
            }

            ///@brief Emits an event to the event bus/board/buffer
            void post(Event e)
            {
                event_bus.enq(e);
            }
            Event next_event()
            {
                // This saved me from segmentation errors
                if (event_bus.length() > 0)
                    return event_bus.get(0);
                else
                    return Event(EveTypeNone, 0);
            }
            Event dequeue()
            {
                if (event_bus.length() > 0)
                    return event_bus.deq();
                else
                    return Event(EveTypeNone, 0);
            }
    };
    EventBoard* EventBoard::instance = nullptr;


}

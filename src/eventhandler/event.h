#pragma once

#include "types.h"
#include <stdarg.h>
#include <time.h>
#include <map>


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
            ///@param type takes an EventType
            ///@param id describes the specific event in more granular detail than just EventType, such as which specific key is being pressed/released
            ///@param payload is an array of integers for extra info which may be needed by some event listeners; array should be of length 16
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

            inline int signature()
            {
                return m_event_signature;
            }
            inline int timestamp()
            {
                return m_timestamp;
            }
            inline EVENT_PAYLOAD_TYPE* payload()
            {
                return m_payload;
            }
    };
}

#pragma once

#define EVENT_C_SHIFT (4)
#define EVENT_T_SHIFT (4)

#define EVENT_NAME_MAX_LENGTH (32)
#define EVENT_TABLE_SIZE (1)

namespace FakeEngine
{
    enum EventCategory
    {
        EveCatNone          =         0,
        EveCatApplication   =  (1 << 0),
        EveCatKeyboard      =  (1 << 1),
        EveCatMouseMovem    =  (1 << 2),
        EveCatMouseButton   =  (1 << 3),
        EveCatMouseScroll   =  (1 << 3),
    };

    enum EventType
    {
        EveTypeNone                =                                         0,
        EveTypeWindowClose         =  (EveCatApplication << EVENT_C_SHIFT) + 0,
        EveTypeWindowResize        =  (EveCatApplication << EVENT_C_SHIFT) + 1,
        EveTypeWindowFocus         =  (EveCatApplication << EVENT_C_SHIFT) + 2,
        EveTypeWindowLostFocus     =  (EveCatApplication << EVENT_C_SHIFT) + 3,
        EveTypeAppTick             =  (EveCatApplication << EVENT_C_SHIFT) + 4,
        EveTypeAppUpdate           =  (EveCatApplication << EVENT_C_SHIFT) + 5,
        EveTypeKeyPressed          =  (EveCatKeyboard    << EVENT_C_SHIFT) + 0,
        EveTypeKeyReleased         =  (EveCatKeyboard    << EVENT_C_SHIFT) + 1,
        EveTypeMouseMoved          =  (EveCatMouseMovem  << EVENT_C_SHIFT) + 0,
        EveTypeMouseButtonPressed  =  (EveCatMouseButton << EVENT_C_SHIFT) + 0,
        EveTypeMouseButtonReleased =  (EveCatMouseButton << EVENT_C_SHIFT) + 1,
        EveTypeMouseScrolled       =  (EveCatMouseScroll << EVENT_C_SHIFT) + 0,
    };

    // typedef struct {
    //     char name[EVENT_NAME_MAX_LENGTH];
        
    // } EventType;
}

#pragma once

#define EVENT_C_SHIFT (4)
#define EVENT_T_SHIFT (4)

enum EventCategory
{
    EveCatNone          =          0,
    EveCatApplication   =   (1 << 0),
    EveCatKeyboard      =   (1 << 1),
    EveCatMouseMovem    =   (1 << 2),
    EveCatMouseButton   =   (1 << 3),
    EveCatMouseScroll   =   (1 << 3),
};

enum EventType
{
    EveTypeNone         =                                          0,
    WindowClose         =   (EveCatApplication << EVENT_C_SHIFT) + 0,
    WindowResize        =   (EveCatApplication << EVENT_C_SHIFT) + 1,
    WindowFocus         =   (EveCatApplication << EVENT_C_SHIFT) + 2,
    WindowLostFocus     =   (EveCatApplication << EVENT_C_SHIFT) + 3,
    AppTick             =   (EveCatApplication << EVENT_C_SHIFT) + 4,
    AppUpdate           =   (EveCatApplication << EVENT_C_SHIFT) + 5,
    KeyPressed          =   (EveCatKeyboard    << EVENT_C_SHIFT) + 0,
    KeyReleased         =   (EveCatKeyboard    << EVENT_C_SHIFT) + 1,
    MouseMoved          =   (EveCatMouseMovem  << EVENT_C_SHIFT) + 0,
    MouseButtonPressed  =   (EveCatMouseButton << EVENT_C_SHIFT) + 0,
    MouseButtonReleased =   (EveCatMouseButton << EVENT_C_SHIFT) + 1,
    MouseScrolled       =   (EveCatMouseScroll << EVENT_C_SHIFT) + 0,
};

add_library(
    event SHARED
    event.h
    event.cpp
)

target_include_directories(
    event PUBLIC
    ../
)

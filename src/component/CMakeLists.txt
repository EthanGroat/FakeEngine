add_library(
    component SHARED
    component.h
    component.cpp
)

target_include_directories(
    component PUBLIC
    ../
)

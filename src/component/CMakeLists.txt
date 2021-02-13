add_library(
    component SHARED
    component.h
    component.cpp
)

target_precompile_headers(component PRIVATE ../ExternalLibraries.h)

target_include_directories(
    component PUBLIC
    ../
)

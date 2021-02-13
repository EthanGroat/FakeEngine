add_library(
    event SHARED
    event.h
    event.cpp
)

target_precompile_headers(event PRIVATE ../ExternalLibraries.h)

target_include_directories(
    event PUBLIC
    ../
)

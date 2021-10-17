add_library(
    universe SHARED
    universe.h
    universe.cpp
)

target_precompile_headers(universe PRIVATE ../ExternalLibraries.h)

target_include_directories(
    universe PUBLIC
    ../
    ../entt/single_include
)

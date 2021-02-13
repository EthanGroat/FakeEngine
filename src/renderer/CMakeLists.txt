add_library(
    renderer SHARED
    renderer.h
    renderer.cpp
)

target_precompile_headers(renderer PRIVATE ../ExternalLibraries.h)

target_include_directories(
    renderer PUBLIC
    ${PROJECT_SOURCE_DIR}/glad/include
    ../
)

target_link_libraries(renderer glfw glad event)

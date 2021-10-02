cmake_minimum_required(VERSION 3.17)
project(FakeEngine)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(renderer)
add_subdirectory(logger)
add_subdirectory(event)
add_subdirectory(entt)
add_subdirectory(universe)

add_library(${PROJECT_NAME} SHARED FakeEngine.cpp)

target_precompile_headers(${PROJECT_NAME} PRIVATE ExternalLibraries.h)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    renderer
    logger
    event
    entt/single_include
    universe
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    glfw
    renderer
    logger
    event
    EnTT::EnTT
    universe
)

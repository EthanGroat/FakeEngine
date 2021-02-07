cmake_minimum_required(VERSION 3.17)
project(FakeEngine)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(renderer)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(logger)
add_subdirectory(eventhandler)
add_subdirectory(component)

add_library(${PROJECT_NAME} SHARED FakeEngine.cpp)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    renderer
    logger
    eventhandler
    component
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    glfw
    renderer
    logger
    component
)

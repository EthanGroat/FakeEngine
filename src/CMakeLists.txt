cmake_minimum_required(VERSION 3.17)
project(FakeEngine)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(renderer)
add_subdirectory(glfw)
add_subdirectory(glad)

add_executable(${PROJECT_NAME} FakeEngine.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC renderer)

target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC renderer)

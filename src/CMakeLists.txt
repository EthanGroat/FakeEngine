cmake_minimum_required(VERSION 3.17)
project(FakeEngine)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(renderer)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE renderer)

cmake_minimum_required(VERSION 3.17)
project(Sandbox)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(../src ${CMAKE_BINARY_DIR}/engine_libraries)

add_executable(${PROJECT_NAME} Sandbox.cpp)

target_precompile_headers(${PROJECT_NAME} REUSE_FROM FakeEngine)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ../src
    ../src/renderer
    ../src/glad/include
)

target_link_libraries(${PROJECT_NAME} PUBLIC FakeEngine)

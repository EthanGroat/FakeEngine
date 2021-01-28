add_library(
    renderer SHARED
    renderer.h
    renderer.cpp
)
target_include_directories(renderer PUBLIC ${PROJECT_SOURCE_DIR}/glad/include)

target_link_libraries(renderer glfw glad)

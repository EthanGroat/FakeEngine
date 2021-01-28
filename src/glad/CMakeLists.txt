add_library(
    glad SHARED
    include/glad/gl.h
    include/glad/vulkan.h
    include/KHR/khrplatform.h
    include/vk_platform.h
    src/gl.c
    src/vulkan.c
)

target_include_directories(glad PRIVATE include)

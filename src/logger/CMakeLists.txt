add_library(
    logger SHARED
    logger.h
    logger.cpp
)

target_include_directories(
    logger PUBLIC
    ../
)

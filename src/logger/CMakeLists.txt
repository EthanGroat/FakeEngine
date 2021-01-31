add_library(
    logger STATIC
    logger.h
    logger.cpp
)

target_include_directories(
    logger PUBLIC
    ../
)

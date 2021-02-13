add_library(
    logger SHARED
    logger.h
    logger.cpp
)

target_precompile_headers(logger PRIVATE ../ExternalLibraries.h)

target_include_directories(
    logger PUBLIC
    ../
)

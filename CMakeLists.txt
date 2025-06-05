include(FetchContent)

cmake_minimum_required(VERSION 3.12)
project(str_has_prefix C)

set(CMAKE_C_STANDARD 11)

add_library(str_has_prefix STATIC str_has_prefix.h str_has_prefix.c)

if(NOT FLUENT_LIBC_RELEASE) # Manually add libraries only if not in release mode
    FetchContent_Declare(
            types
            GIT_REPOSITORY https://github.com/rodrigoo-r/types
            GIT_TAG        master
    )

    FetchContent_Declare(
            stdbool
            GIT_REPOSITORY https://github.com/rodrigoo-r/std_bool
            GIT_TAG        master
    )

    FetchContent_MakeAvailable(types)
    FetchContent_MakeAvailable(stdbool)

    target_include_directories(str_has_prefix PRIVATE ${CMAKE_BINARY_DIR}/_deps/types-src)
    target_link_libraries(str_has_prefix PRIVATE types)

    target_include_directories(str_has_prefix PRIVATE ${CMAKE_BINARY_DIR}/_deps/stdbool-src)
    target_link_libraries(str_has_prefix PRIVATE stdbool)
endif ()
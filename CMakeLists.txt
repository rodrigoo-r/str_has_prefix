include(FetchContent)

cmake_minimum_required(VERSION 3.31)
project(str_has_prefix C)

set(CMAKE_C_STANDARD 11)

add_library(str_has_prefix STATIC library.c)

if(NOT FLUENT_LIBC_RELEASE) # Manually add libraries only if not in release mode
    FetchContent_Declare(
            types
            GIT_REPOSITORY https://github.com/rodrigoo-r/types
            GIT_TAG        master
    )

    FetchContent_MakeAvailable(types)

    target_include_directories(str_has_prefix PRIVATE ${CMAKE_BINARY_DIR}/_deps/types-src)
    target_link_libraries(str_has_prefix PRIVATE types)
endif ()
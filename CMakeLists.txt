cmake_minimum_required(VERSION 3.15)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
set(TARGET "sparse_matrix")

set(GCC_LIKE_CXX $<$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>:-Wall -Wextra -pedantic -Werror>)
set(MSVC_CXX $<$<COMPILE_LANG_AND_ID:CXX,MSVC>:-W4>)

project(homework-6 VERSION ${PROJECT_VERSION})

add_executable(${TARGET} main.cpp matrix.cpp)

set_target_properties(${TARGET} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON)

target_compile_options(${TARGET} PUBLIC
    ${GCC_LIKE_CXX}
    ${MSVC_CXX})

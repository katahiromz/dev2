# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(stdc C CXX)

# set output directory (build/)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# staticaly link
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # using Clang
    set(CMAKE_C_FLAGS "-static")
    set(CMAKE_CXX_FLAGS "-static")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # using GCC
    set(CMAKE_C_FLAGS "-static")
    set(CMAKE_CXX_FLAGS "-static")
elseif (MSVC)
    # replace "/MD" with "/MT" (building without runtime DLLs)
    set(CompilerFlags
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_RELWITHDEBINFO
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_RELWITHDEBINFO)
    foreach(CompilerFlags ${CompilerFlags})
        string(REPLACE "/MD" "/MT" ${CompilerFlags} "${${CompilerFlags}}")
    endforeach()
endif()

##############################################################################

add_subdirectory(abort)
add_subdirectory(abs)
add_subdirectory(access)
add_subdirectory(assert)
add_subdirectory(atexit)
add_subdirectory(atoi)
add_subdirectory(bsearch)
add_subdirectory(ctemplate)
add_subdirectory(div)
add_subdirectory(exit)
add_subdirectory(fgets)
add_subdirectory(fopen)
add_subdirectory(fseek)
add_subdirectory(ftell)
add_subdirectory(getenv)
add_subdirectory(isctype)
add_subdirectory(main)
add_subdirectory(malloc)
add_subdirectory(math)
add_subdirectory(memcmp)
add_subdirectory(memcpy)
add_subdirectory(memmove)
add_subdirectory(memset)
add_subdirectory(printf)
add_subdirectory(puts)
add_subdirectory(qsort)
add_subdirectory(rand)
add_subdirectory(remove)
add_subdirectory(rename)
add_subdirectory(setjmp)
add_subdirectory(sizeof)
add_subdirectory(strcat)
add_subdirectory(strchr)
add_subdirectory(strcmp)
add_subdirectory(strcpy)
add_subdirectory(strcspn)
add_subdirectory(strftime)
add_subdirectory(strlen)
add_subdirectory(strncmp)
add_subdirectory(strpbrk)
add_subdirectory(strrchr)
add_subdirectory(strspn)
add_subdirectory(strstr)
add_subdirectory(strtod)
add_subdirectory(strtok)
add_subdirectory(strtol)
add_subdirectory(strtoul)
add_subdirectory(struct)
add_subdirectory(system)
add_subdirectory(time)
add_subdirectory(tolower)
add_subdirectory(toupper)
add_subdirectory(va_list)
add_subdirectory(vprintf)

##############################################################################

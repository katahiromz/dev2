# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(va_list C CXX)

##############################################################################

# va_list.exe
add_executable(va_list main.cpp)
#target_link_libraries(va_list ...)

##############################################################################

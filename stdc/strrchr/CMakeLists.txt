# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(strrchr C CXX)

##############################################################################

# strrchr.exe
add_executable(strrchr main.cpp)
#target_link_libraries(strrchr ...)

##############################################################################

# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(FindFirstFile C CXX)

##############################################################################

# FindFirstFile.exe
add_executable(FindFirstFile main.cpp)
target_link_libraries(FindFirstFile comctl32 comdlg32 shell32 shlwapi)

##############################################################################

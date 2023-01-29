# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(Win32TemplateConsoleApp C CXX)

##############################################################################

# Win32TemplateConsoleApp.exe
add_executable(Win32TemplateConsoleApp main.cpp)
target_link_libraries(Win32TemplateConsoleApp comctl32 comdlg32 shell32 shlwapi)

##############################################################################

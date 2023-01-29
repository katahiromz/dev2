# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(Win32TemplateWindowApp C CXX)

##############################################################################

# Visual C++?
if(MSVC)
    add_definitions(-DMSVC=1)
endif()

# Unicode?
option(USE_UNICODE "Use Unicode" OFF)
if(USE_UNICODE)
    add_definitions(-DUNICODE -D_UNICODE)
endif()

# Win32TemplateWindowApp.exe
add_executable(Win32TemplateWindowApp WIN32 main.cpp main_res.rc AboutDlg.cpp utils.cpp)
target_link_libraries(Win32TemplateWindowApp comctl32 comdlg32 shell32 shlwapi)

##############################################################################

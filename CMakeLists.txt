cmake_minimum_required(VERSION 3.10)
project(SNN_GPU)
#Forces CMake to export the compile commands to a file so clang can read it
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# This will now work because pacman put the files in the right place
find_package(OpenCL REQUIRED)

add_executable(snn_app main.cpp)

# Link the OpenCL library found by the system
target_link_libraries(snn_app PRIVATE OpenCL::OpenCL)

message(STATUS "OpenCL found: ${OpenCL_FOUND}")
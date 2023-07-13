cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

#============================================================================
# Initialize the project
#============================================================================
project(mjcarroll-custom-msgs VERSION 1.0.0)

#============================================================================
# Find gz-cmake
#============================================================================
find_package(gz-cmake3 REQUIRED)
find_package(gz-msgs10 REQUIRED)

add_subdirectory(lib1)
add_subdirectory(lib2)

add_executable(foo_main foo_main.cc)

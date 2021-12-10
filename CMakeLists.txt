cmake_minimum_required (VERSION 3.1)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")

project("maze-bench-cpp" VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (maze-bench "src/main.cpp")

find_path(PNGPP_INCLUDE_DIRS "png++/color.hpp")
target_include_directories(maze-bench PRIVATE ${PNGPP_INCLUDE_DIRS})

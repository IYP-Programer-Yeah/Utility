cmake_minimum_required (VERSION 3.5)

set(REPO_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED, ON)

add_subdirectory(googletest)
add_subdirectory(Utility)
add_subdirectory(Test)

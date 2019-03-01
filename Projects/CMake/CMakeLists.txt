cmake_minimum_required (VERSION 2.6)

set(REPO_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)
set(CMAKE_PROJECT_ROOT ${REPO_ROOT}/Projects/CMake)
set(LOCAL_BUILD_DIR ${CMAKE_PROJECT_ROOT}/Build)
set(LOCAL_INCLUDE_DIR ${LOCAL_BUILD_DIR}/Include)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(googletest)
add_subdirectory(Utility)
add_subdirectory(Test)
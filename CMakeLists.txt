cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 17)

set(PROJECT_NAME MeidiasEngine)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(THIRDPARTY_SOURCE_DIR ${CMAKE_SOURCE_DIR}/thirdparty)

project(${PROJECT_NAME})

include(src/CMakeLists.txt)
include(thirdparty/CMakeLists.txt)
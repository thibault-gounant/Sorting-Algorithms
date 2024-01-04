cmake_minimum_required(VERSION 3.30)
project(Sorting-Algorithms C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/binaries)

add_executable(${PROJECT_NAME} ./sources/main.c)

cmake_minimum_required(VERSION 3.30)
project(Sorting-Algorithms C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/binaries)

add_subdirectory(libraries/SDL2)

include_directories(${PROJECT_SOURCE_DIR}/headers ${SDL2_INCLUDE_DIRS})

aux_source_directory(./sources/sorts SORTS)
aux_source_directory(./sources/utils UTILS)

add_executable(${PROJECT_NAME} ./sources/main.c ${SORTS} ${UTILS})
add_executable(${PROJECT_NAME}_tests ./tests/test.c ${SORTS} ${UTILS})

target_link_libraries(${PROJECT_NAME} SDL2::SDL2-static)
target_link_libraries(${PROJECT_NAME}_tests SDL2::SDL2-static)

enable_testing()
add_test(NAME bubble_sort_tests COMMAND ${PROJECT_NAME}_tests 1)
add_test(NAME insertion_sort_tests COMMAND ${PROJECT_NAME}_tests 2)
add_test(NAME selection_sort_tests COMMAND ${PROJECT_NAME}_tests 3)

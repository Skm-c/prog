cmake_minimum_required(VERSION 3.2...3.27.5)

project(multi-project_project)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(universities)
add_subdirectory(merge_sort)
add_subdirectory(unit_test_example)
add_subdirectory(vector_list_test)
add_subdirectory(long_number_test)

set(CMAKE_SUPPRESS_REGENERATION true)
cmake_minimum_required(VERSION 3.19)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 14)

file(GLOB main_files "${PROJECT_SOURCE_DIR}/*/*.cpp")
foreach(main_file IN LISTS main_files)
    get_filename_component(main_name ${main_file} NAME_WE)
    message(STATUS "found executable main file ${main_name}.cpp")
    add_executable(${main_name} ${main_file})
endforeach()

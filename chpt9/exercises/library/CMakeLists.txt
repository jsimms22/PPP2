cmake_minimum_required(VERSION 3.27.0)

project(library)

add_subdirectory(src)

add_executable(library main.cpp)

target_link_libraries(library PUBLIC src)

target_include_directories(library PUBLIC "${PROJECT_SOURCE_DIR}/src")

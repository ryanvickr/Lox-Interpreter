cmake_minimum_required(VERSION 3.15)
project(clox)

add_library(lox-compile "")
target_sources(lox-compile PRIVATE lox-compile.cc PUBLIC lox-compile.h)
# add_subdirectory("counter")

add_executable(${PROJECT_NAME} main.cc)

target_link_libraries(${PROJECT_NAME} lox-compile)

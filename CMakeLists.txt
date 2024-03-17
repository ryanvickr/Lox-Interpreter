cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)
project(clox)

add_library(util "")
add_library(loxobject "")
add_library(token "")
add_library(scanner "")
add_library(lox-compile "")
add_subdirectory("src")

add_executable(${PROJECT_NAME} main.cc)

target_link_libraries(${PROJECT_NAME} lox-compile)

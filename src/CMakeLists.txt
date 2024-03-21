# Packages in the src directory.
add_subdirectory("common")
add_subdirectory("scanning")
target_sources(lox-compile PRIVATE lox-compile.cc PUBLIC lox-compile.h)

target_link_libraries(lox-compile scanner token util)

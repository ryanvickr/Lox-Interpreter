target_sources(token PRIVATE token.cc PUBLIC token.h)
target_sources(scanner PRIVATE scanner.cc PUBLIC scanner.h)

target_link_libraries(scanner token)
target_link_libraries(lox-compile scanner token)
target_sources(lox-compile PRIVATE lox-compile.cc PUBLIC lox-compile.h)
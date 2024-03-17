# Packages in the src directory.

target_sources(util PRIVATE util.cc PUBLIC util.h)
target_sources(loxobject PRIVATE lox-object.cc PUBLIC lox-object.h)
target_sources(token PRIVATE token.cc PUBLIC token.h)
target_sources(scanner PRIVATE scanner.cc PUBLIC scanner.h)

target_link_libraries(token loxobject)
target_link_libraries(scanner token util)
target_link_libraries(lox-compile scanner token util)
target_sources(lox-compile PRIVATE lox-compile.cc PUBLIC lox-compile.h)
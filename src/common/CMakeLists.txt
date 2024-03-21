target_sources(loxobject PRIVATE lox-object.cc PUBLIC lox-object.h)
target_sources(util PRIVATE util.cc PUBLIC util.h)

target_link_libraries(token loxobject)

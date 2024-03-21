target_sources(expression PRIVATE expression.cc PUBLIC expression.h)
target_sources(parser PRIVATE parser.cc PUBLIC parser.h)

target_link_libraries(expression token loxobject)

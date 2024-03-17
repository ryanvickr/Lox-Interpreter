#include "lox-compile.h"

#include <iostream>
#include <string_view>

namespace loxcompile {

void LoxCompile::RunFile(std::string_view file_path) {
    Error(1, "balhasdlfhasld");
}

void LoxCompile::Error(int line, std::string_view message) {
    Report(line, "", message);
}

void LoxCompile::Report(int line, std::string_view where,
            std::string_view message) {
    std::cerr << "[line " << line << "] Error" << 
        where << ": " << message << std::endl;
    had_error_ = true;
}

} // loxcompile

// Author: Ryan Vickramasinghe
#include "lox-compile.h"

#include <iostream>
#include <string>
#include <string_view>

#include "token.h"

namespace loxcompile {

void LoxCompile::RunFile(std::string_view file_path) {
    Error(1, "balhasdlfhasld");
}

void LoxCompile::RunPrompt() {
    std::string line;
    std::cout << "WELCOME TO RYANVICKR'S LOX PARSER\n> ";
    while(std::getline(std::cin, line)) {
        if (had_error_) break;
        std::cout << "> ";

        // Interpret the line.
    }
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

}  // loxcompile

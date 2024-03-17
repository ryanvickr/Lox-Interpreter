// Author: Ryan Vickramasinghe
#include "lox-compile.h"

#include <iostream>
#include <string>
#include <string_view>

#include "scanner.h"
#include "token.h"
#include "util.h"

namespace loxcompile {

void LoxCompile::RunFile(std::string_view file_path) {
    util::Error(1, "balhasdlfhasld");
    Scanner scan("");
}

void LoxCompile::RunPrompt() {
    std::string line;
    std::cout << "WELCOME TO RYANVICKR'S LOX PARSER\n> ";
    while(std::getline(std::cin, line)) {
        if (had_error_) break;
        std::cout << "> ";

        // Interpret the line.
        Scanner scan(line);
        scan.ScanTokens();
    }
}

}  // loxcompile

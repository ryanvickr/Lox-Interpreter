// Author: Ryan Vickramasinghe
#include "lox-compile.h"

#include <iostream>
#include <string>
#include <string_view>

namespace loxcompile {
namespace {
enum TokenType {
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // One or two character tokens.
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literals.
    IDENTIFIER, STRING, NUMBER,

    // Keywords.
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,
    
    END_OF
};
}  // namespace

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

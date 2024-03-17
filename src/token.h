// Author: Ryan Vickramasinghe
#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>

#include "lox-object.h"

namespace loxcompile {

class Token {
 public:
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

    Token(const TokenType& type, const std::string& lexeme,
        std::unique_ptr<LoxObject> literal, int line);

    std::ostream& operator<<(std::ostream& stream);

 private:
    const TokenType type_;
    const std::string lexeme_;
    std::unique_ptr<LoxObject> literal_;  // non-const to enable move
    const int line_;
};

}  // loxcompile

#endif // TOKEN_H

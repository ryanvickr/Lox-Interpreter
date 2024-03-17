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

    Token(Token&& mv_token):
        type_(mv_token.type_), lexeme_(mv_token.lexeme_),
        literal_(mv_token.literal_.get()), line_(mv_token.line_) {}

    Token(Token& cp_token):
        type_(cp_token.type_), lexeme_(cp_token.lexeme_),
        literal_(cp_token.literal_.get()), line_(cp_token.line_) {}

    std::ostream& operator<<(std::ostream& stream);

 private:
    const TokenType type_;
    const std::string lexeme_;
    const std::unique_ptr<LoxObject> literal_;
    const int line_;
};

}  // loxcompile

#endif // TOKEN_H

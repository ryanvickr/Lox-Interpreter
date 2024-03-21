// Author: Ryan Vickramasinghe
#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>

#include "../common/lox-object.h"

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
        IDENTIFIER, STRING, INTEGER, DOUBLE,

        // Keywords.
        AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
        PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,
        
        END_OF
    };

    Token(const TokenType& type, const std::string& lexeme,
        std::unique_ptr<LoxObject> literal, int line);

    friend std::ostream& operator<<(
        std::ostream& out, const Token& token) {
        out << token.type_ << " " << token.lexeme_ << " ";
        if (token.literal_) {
            out << *token.literal_;
        } else {
            out << "NULL";
        }
        return out;
    }

    const TokenType type_;
    const std::string lexeme_;
    std::unique_ptr<LoxObject> literal_;  // non-const to enable move
    const int line_;
};

}  // loxcompile

#endif // TOKEN_H

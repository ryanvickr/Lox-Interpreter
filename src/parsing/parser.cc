// Author: Ryan Vickramasinghe
#include "parser.h"

#include "../scanning/token.h"

namespace loxcompile {

Parser::Parser(std::vector<Token>&& tokens):
    tokens_(std::move(tokens)) {}

bool Parser::Match(const Token::TokenType& type) {
    if (!Check(type)) return false;
    
    Advance();
    return true;
}

bool Parser::Match(const std::vector<Token::TokenType>& types) {
    for (const auto& type : types) {
        bool match = Match(type);
        if (!match) return false;
    }

    return true;
}

bool Parser::Check(const Token::TokenType& type) {
    if (IsAtEnd()) return false;
    return Peek().type_ == type;
}

Token& Parser::Advance() {
    if (!IsAtEnd()) current_++;
    return Previous();
}

bool Parser::IsAtEnd() {
    return Peek().type_ == Token::TokenType::END_OF;
}

Token& Parser::Peek() {
    return tokens_[current_];
}

Token& Parser::Previous() {
    return tokens_[current_ - 1];
}

}  // loxcompile

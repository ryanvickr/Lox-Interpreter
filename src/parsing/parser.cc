// Author: Ryan Vickramasinghe
#include "parser.h"

#include "../scanning/token.h"

namespace loxcompile {

Parser::Parser(std::vector<Token>&& tokens):
    tokens_(std::move(tokens)) {}

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

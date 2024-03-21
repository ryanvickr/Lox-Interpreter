// Author: Ryan Vickramasinghe
#include "token.h"

#include <iostream>
#include <string>
#include <utility>

namespace loxcompile {

Token::Token(const TokenType& type, const std::string& lexeme,
        std::unique_ptr<LoxObject> literal, int line): 
        type_(type), lexeme_(lexeme),
        literal_(std::move(literal)), line_(line)  {}

}  // loxcompile

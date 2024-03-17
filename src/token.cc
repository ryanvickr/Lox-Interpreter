// Author: Ryan Vickramasinghe
#include "token.h"

#include <iostream>
#include <string>

namespace loxcompile {

Token::Token(const TokenType& type, const std::string& lexeme,
        const std::unique_ptr<std::string>& literal, int line): 
        type_(type), lexeme_(lexeme), literal_(literal.get()), 
        line_(line)  {}

std::ostream& Token::operator<<(std::ostream& stream) {
    stream << this->type_ << " " << this->lexeme_;
    return stream;
}

}  // loxcompile

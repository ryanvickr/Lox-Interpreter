// Author: Ryan Vickramasinghe
#include "lox-object.h"

#include <iostream>

LoxString::LoxString(const std::string& value):
    value_(value) {}

LoxString::LoxString(std::string&& value):
    value_(std::move(value)) {}

std::ostream& LoxString::operator<<(std::ostream& stream) {
    stream << this->value_;
    return stream;
}

bool LoxString::operator==(const LoxString& other_str) {
    return this->value_ == other_str.value_;
}

// Author: Ryan Vickramasinghe
#include "lox-object.h"

#include <iostream>

/// @section `LoxString` function definitions.

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

/// @section `LoxInteger` function definitions.

LoxInteger::LoxInteger(int value): value_(value) {}

std::ostream& LoxInteger::operator<<(std::ostream& stream) {
    stream << this->value_;
    return stream;
}

bool LoxInteger::operator==(const LoxInteger& other_int) {
    return this->value_ == other_int.value_;
}

/// @section `LoxDouble` function definitions.

LoxDouble::LoxDouble(double value): value_(value) {}

std::ostream& LoxDouble::operator<<(std::ostream& stream) {
    stream << this->value_;
    return stream;
}

bool LoxDouble::operator==(const LoxDouble& other_dbl) {
    return this->value_ == other_dbl.value_;
}

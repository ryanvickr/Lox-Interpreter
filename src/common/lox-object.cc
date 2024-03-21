// Author: Ryan Vickramasinghe
#include "lox-object.h"

#include <iostream>

namespace loxcompile {

/// @section `LoxString` function definitions.

LoxString::LoxString(const std::string& value):
    value_(value) {}

LoxString::LoxString(std::string&& value):
    value_(std::move(value)) {}

std::ostream& LoxString::output(std::ostream& os) const {
    os << value_;
    return os;
}

/// @section `LoxInteger` function definitions.

LoxInteger::LoxInteger(int value): value_(value) {}

std::ostream& LoxInteger::output(std::ostream& os) const {
    os << std::to_string(value_);
    return os;
}

/// @section `LoxDouble` function definitions.

LoxDouble::LoxDouble(double value): value_(value) {}

std::ostream& LoxDouble::output(std::ostream& os) const {
    os << std::to_string(value_);
    return os;
}

}  // loxcompile

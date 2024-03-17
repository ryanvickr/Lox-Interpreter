// Author: Ryan Vickramasinghe
#ifndef LOX_OBJECT_H
#define LOX_OBJECT_H

#include <iostream>
#include <string>

// Empty base interface class.
struct LoxObject {};

// The Lox representation of a string literal.
struct LoxString : LoxObject {
    LoxString(const std::string& value);

    LoxString(std::string&& value);

    std::ostream& operator<<(std::ostream& stream);

    bool operator==(const LoxString& other_str);

    std::string value_;
};

#endif // LOX_OBJECT_H
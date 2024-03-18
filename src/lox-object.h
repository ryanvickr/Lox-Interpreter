// Author: Ryan Vickramasinghe
#ifndef LOX_OBJECT_H
#define LOX_OBJECT_H

#include <iostream>
#include <string>

namespace loxcompile {

// Base class for all lox objects. Allows us to define custom
// operator overloads for each object type.
struct LoxObject {
    virtual ~LoxObject() = default;
    virtual std::ostream& output(std::ostream&) const = 0;
};

inline std::ostream& operator<<(
    std::ostream& os, const LoxObject& obj) {
    return obj.output(os);
}

// The Lox representation of a string literal.
struct LoxString : LoxObject {
    LoxString(const std::string& value);

    LoxString(std::string&& value);

    std::ostream& output(std::ostream& os) const override;

    std::string value_;
};

// The Lox representation of an integer literal.
struct LoxInteger : LoxObject {
    LoxInteger(int value);

    std::ostream& output(std::ostream& os) const override;

    int value_;
};

// The Lox representation of a double literal.
struct LoxDouble : LoxObject {
    LoxDouble(double value);

    std::ostream& output(std::ostream& os) const override;

    double value_;
};

}  // loxcompile

#endif // LOX_OBJECT_H
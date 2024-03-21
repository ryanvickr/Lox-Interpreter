// Author: Ryan Vickramasinghe
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "../scanning/token.h"

namespace loxcompile {

class Expression {};

class BinaryExpression : public Expression {
 public:
    BinaryExpression(
        const Expression& left, Token&& op, 
        const Expression& right);

 private:
    const Expression left_;
    const Token op_;
    const Expression right_;
};

}  // loxcompile

#endif // EXPRESSION_H

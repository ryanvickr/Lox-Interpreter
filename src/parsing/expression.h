// Author: Ryan Vickramasinghe
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "../common/lox-object.h"
#include "../scanning/token.h"

namespace loxcompile {

class Expression {};

class BinaryExpression : public Expression {
 public:
    BinaryExpression(
        const Expression& left, Token&& op, 
        const Expression& right);

    const Expression left_;
    const Token op_;
    const Expression right_;
};

class GroupingExpression : public Expression {
 public:
    GroupingExpression(const Expression& expression);

    const Expression expression_;
};

class LiteralExpression : public Expression {
 public:
    LiteralExpression(std::unique_ptr<LoxObject> obj);

    std::unique_ptr<LoxObject> obj_;
};

class UnaryExpression : public Expression {
 public:
    UnaryExpression(Token&& op, Expression right);

    Token op_;
    Expression right_;
};

}  // loxcompile

#endif // EXPRESSION_H

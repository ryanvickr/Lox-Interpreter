// Author: Ryan Vickramasinghe
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "../common/lox-object.h"
#include "../scanning/token.h"

namespace loxcompile {

// Forward-declare to allow for Visitor-pattern.
class Visitor;
class BinaryExpression;
class GroupingExpression;
class LiteralExpression;
class UnaryExpression;

class Expression {
 public:
    virtual ~Expression() = default;

    virtual void Accept(Visitor* visitor) = 0;
};

class Visitor {
 public:
    virtual ~Visitor() = default;

    virtual void VisitBinaryExpr(BinaryExpression* expr) = 0;

    virtual void VisitGroupingExpr(GroupingExpression* expr) = 0;

    virtual void VisitLiteralExpr(LiteralExpression* expr) = 0;

    virtual void VisitUnaryExpr(UnaryExpression* expr) = 0;
};

class BinaryExpression : public Expression {
 public:
    BinaryExpression(
        std::unique_ptr<Expression> left, Token&& op, 
        std::unique_ptr<Expression> right);

    void Accept(Visitor* visitor) override;

    const std::unique_ptr<Expression> left_;
    const Token op_;
    const std::unique_ptr<Expression> right_;
};

class GroupingExpression : public Expression {
 public:
    GroupingExpression(std::unique_ptr<Expression> expression);

    void Accept(Visitor* visitor) override;

    const std::unique_ptr<Expression> expression_;
};

class LiteralExpression : public Expression {
 public:
    LiteralExpression(std::unique_ptr<LoxObject> obj);

    void Accept(Visitor* visitor) override;

    std::unique_ptr<LoxObject> obj_;
};

class UnaryExpression : public Expression {
 public:
    UnaryExpression(Token&& op, std::unique_ptr<Expression> right);

    void Accept(Visitor* visitor) override;

    Token op_;
    const std::unique_ptr<Expression> right_;
};

}  // loxcompile

#endif // EXPRESSION_H

// Author: Ryan Vickramasinghe
#include "expression.h"

#include "../common/lox-object.h"
#include "../scanning/token.h"

namespace loxcompile {

/* BinaryExpression Implementation */

BinaryExpression::BinaryExpression(
    std::unique_ptr<Expression> left, Token&& op, 
    std::unique_ptr<Expression> right):
    left_(std::move(left)), op_(std::move(op)),
    right_(std::move(right)) {}

void BinaryExpression::Accept(Visitor* visitor) {
    visitor->VisitBinaryExpr(this);
}

/* GroupingExpression Implementation */

GroupingExpression::GroupingExpression(
    std::unique_ptr<Expression> expression):
    expression_(std::move(expression)) {}

void GroupingExpression::Accept(Visitor* visitor) {
    visitor->VisitGroupingExpr(this);
}

/* LiteralExpression Implementation */

LiteralExpression::LiteralExpression(std::unique_ptr<LoxObject> obj):
    obj_(std::move(obj)) {}

void LiteralExpression::Accept(Visitor* visitor) {
    visitor->VisitLiteralExpr(this);
}

/* UnaryExpression Implementation */

UnaryExpression::UnaryExpression(
    Token&& op, std::unique_ptr<Expression> right):
    op_(std::move(op)), right_(std::move(right)) {}

void UnaryExpression::Accept(Visitor* visitor) {
    visitor->VisitUnaryExpr(this);
}

}  // loxcompile

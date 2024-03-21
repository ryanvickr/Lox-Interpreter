// Author: Ryan Vickramasinghe
#include "expression.h"

#include "../scanning/token.h"

namespace loxcompile {

BinaryExpression::BinaryExpression(
    const Expression& left, Token&& op, 
    const Expression& right):
    left_(left), op_(std::move(op)), right_(right) {}

GroupingExpression::GroupingExpression(const Expression& expression):
    expression_(expression) {}

LiteralExpression::LiteralExpression(std::unique_ptr<LoxObject> obj):
    obj_(std::move(obj)) {}

UnaryExpression::UnaryExpression(Token&& op, Expression right):
    op_(std::move(op)), right_(right) {}

}  // loxcompile

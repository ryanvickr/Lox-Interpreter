// Author: Ryan Vickramasinghe
#include "expression.h"

#include "../scanning/token.h"

namespace loxcompile {

BinaryExpression::BinaryExpression(
    const Expression& left, Token&& op, 
    const Expression& right):
    left_(left), op_(std::move(op)), right_(right) {}

}  // loxcompile

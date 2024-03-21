// Author: Ryan Vickramasinghe
#ifndef PARSER_H
#define PARSER_H

#include <vector>

#include "../scanning/token.h"

namespace loxcompile {

class Parser {
 public:
    Parser(std::vector<Token>&& tokens);

 private:
   /// @brief Checks if the current token is of the given type
   // and consumes it if so.
   /// @param type The `TokenType` to compare against.
   /// @return Return true iff the provided `TokenType` matches
   // the current `Token`'s type.
   bool Match(const Token::TokenType& type);

   /// @brief Checks if the current token matches all given
   // types and consumes it if so.
   /// @param type The `TokenType` to compare against.
   /// @return Return true iff the provided `TokenType` matches
   // the current `Token`'s type.
   bool Match(const std::vector<Token::TokenType>& types);

   /// @brief Checks if the current token is of the given type.
   // Unlike match(), it never consumes the token, it only looks
   // at it.
   /// @param type The `TokenType` to compare against.
   /// @return Return true iff the provided `TokenType` matches
   // the current `Token`'s type.
   bool Check(const Token::TokenType& type);

   /// @brief Consumes the current token and returns it.
   /// @return Returns a reference to the current `Token`.
   Token& Advance();

   /// @brief Checks whether the `current_` pointer is at the end
   // of the token list.
   /// @return Returns true if we are at the end, false otherwise.
   bool IsAtEnd();

   /// @brief Checks the current token.
   /// @return Returns a reference to the current `Token`.
   Token& Peek();

   /// @brief Checks the previous token.
   /// @return Returns a reference to the previous `Token`.
   Token& Previous();

   std::vector<Token> tokens_;
   int current_ = 0;
};

}  // loxcompile 

#endif // PARSER_H

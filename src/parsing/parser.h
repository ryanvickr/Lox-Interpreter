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

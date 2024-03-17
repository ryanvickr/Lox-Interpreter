// Author: Ryan Vickramasinghe
#ifndef SCANNER_H
#define SCANNER_H

#include <memory>
#include <string>
#include <vector>

#include "lox-compile.h"
#include "token.h"

namespace loxcompile {

class Scanner {
 public:
    explicit Scanner(const std::string& source);

    /// @brief Returns true if the code scanning succeeded,
    // and false otherwise.
    bool ScanTokens();

 private:
    void ScanToken();

    char Advance();

    void AddToken(const Token::TokenType& type);

    void AddToken(
        const Token::TokenType& type, 
        std::unique_ptr<LoxObject> literal);

    const std::string source_;
    std::vector<Token> tokens_;
    int line_ = 1;
    int start_ = 0;
    // Index of where we are in `source_`.
    int current_ = 0;
    // Keeps track of whether this scanner had an error.
    bool had_error_ = false;
};

}  // loxcompile

#endif // SCANNER_H

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

    void ScanTokens();

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
};

}  // loxcompile

#endif // SCANNER_H

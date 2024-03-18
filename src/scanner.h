// Author: Ryan Vickramasinghe
#ifndef SCANNER_H
#define SCANNER_H

#include <memory>
#include <string>
#include <vector>

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

    /// @brief Parses a string literal from `source_`, and adds
    // it to the available tokens. Note: no escape sequences
    // are currently allowed.
    void String();

    /// @brief Parses an integer or double literal from `source_`,
    // and adds it to the available tokens.
    void Number();

    /// @section private helper methods.

    /// @brief Returns the next character from `source_`, and
    // increments the `current_` pointer.
    char Advance();

    void AddToken(const Token::TokenType& type);

    void AddToken(
        const Token::TokenType& type, 
        std::unique_ptr<LoxObject> literal);

    /// @brief Returns true if we are at the end of `source_`.
    bool IsAtEnd();

    /// @brief Returns true if the current char is equivalent to
    // the `expected` char. Will also return false if at the end
    // of `source_`. Used to check for double tokens (e.g. `!=`).
    bool Match(char expected);

    /// @brief Returns the next character from `source_`. If this
    // is the end of `source_`, returns `\0`.
    char Peek();

    // /// @brief Returns the 2nd next character from `source_`. If
    // // this is the end of `source_`, returns `\0`.
    // char PeekNext();

    const std::string source_;
    std::vector<Token> tokens_;
    int line_ = 1;
    // Stores the start index of the current token.
    int start_ = 0;
    // Index of where we are in `source_`.
    int current_ = 0;
    // Keeps track of whether this scanner had an error.
    bool had_error_ = false;
};

}  // loxcompile

#endif // SCANNER_H

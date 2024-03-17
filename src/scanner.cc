// Author: Ryan Vickramasinghe
#include "scanner.h"

#include <string>

#include "lox-compile.h"
#include "util.h"

namespace loxcompile {

Scanner::Scanner(const std::string& source): source_(source) {}

bool Scanner::ScanTokens() {
    // Loop through our source code until we have reached the end.
    while(current_ >= source_.length()) {
        // TODO: Loop through the source and parse out our tokens.
        start_ = current_;
        ScanToken();
    }

    tokens_.emplace_back(
        Token::TokenType::END_OF, "", nullptr, line_);

    return !had_error_;
}

void Scanner::ScanToken() {
    char c = Advance();
    switch (c) {
        case '(': AddToken(Token::TokenType::LEFT_PAREN); break;
        case ')': AddToken(Token::TokenType::RIGHT_PAREN); break;
        case '{': AddToken(Token::TokenType::LEFT_BRACE); break;
        case '}': AddToken(Token::TokenType::RIGHT_BRACE); break;
        case ',': AddToken(Token::TokenType::COMMA); break;
        case '.': AddToken(Token::TokenType::DOT); break;
        case '-': AddToken(Token::TokenType::MINUS); break;
        case '+': AddToken(Token::TokenType::PLUS); break;
        case ';': AddToken(Token::TokenType::SEMICOLON); break;
        case '*': AddToken(Token::TokenType::STAR); break;

        default:
            util::Error(line_, "Unexpected char.");
            had_error_ = true;
            break;
    }
}

char Scanner::Advance() {
    return source_[current_++];
}

void Scanner::AddToken(const Token::TokenType& type) {
    AddToken(type, nullptr);
}

void Scanner::AddToken(
    const Token::TokenType& type,
    std::unique_ptr<LoxObject> literal) {
    std::string text = source_.substr(start_, current_);
    tokens_.emplace_back(type, text, std::move(literal), line_);
}

}  // loxcompile

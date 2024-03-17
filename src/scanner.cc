// Author: Ryan Vickramasinghe
#include "scanner.h"

#include <string>

#include "lox-compile.h"
#include "util.h"

namespace loxcompile {

Scanner::Scanner(const std::string& source): source_(source) {}

bool Scanner::ScanTokens() {
    // Loop through our source code until we have reached the end.
    while(!IsAtEnd()) {
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
        // Single-char tokens:
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
        // Two-char tokens:
        case '!':
            AddToken(Match('=') ?
                Token::TokenType::BANG_EQUAL :
                Token::TokenType::BANG);
            break;
        case '=':
            AddToken(Match('=') ?
                Token::TokenType::EQUAL_EQUAL :
                Token::TokenType::EQUAL);
            break;
        case '<':
            AddToken(Match('=') ?
                Token::TokenType::LESS_EQUAL :
                Token::TokenType::LESS);
            break;
        case '>':
            AddToken(Match('=') ?
                Token::TokenType::GREATER_EQUAL :
                Token::TokenType::GREATER);
            break;
        // The `//` char can also refer to comments.
        case '/':
            if (Match('/')) {
                // Skip through to chars till the end of this line.
                while (Peek() != '\n' && !IsAtEnd()) Advance();
            } else {
                AddToken(Token::TokenType::SLASH);
            }
            break;
        // Skip over whitespace:
        case ' ':
        case '\r':
        case '\t': break;
        // Newline:
        case '\n': line_++; break;

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

bool Scanner::IsAtEnd() {
    return current_ >= source_.length();
}

bool Scanner::Match(char expected) {
    if (IsAtEnd()) return false;
    if (source_[current_] != expected) return false;

    current_++;
    return true;
}

char Scanner::Peek() {
    if (IsAtEnd()) return '\0'; // We're at the end of the line.
    return source_[current_];
}

}  // loxcompile

// Author: Ryan Vickramasinghe
#include "scanner.h"

#include <ctype.h>
#include <map>
#include <string>
#include <utility>

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
        // Handle string literals:
        case '"': String(); break;

        default:
            if (isdigit(c)) {
                // Handle number literals:
                Number();
            } else if (isalpha(c)) {
                // Handle reserved word identifiers:
                Identifier();
            } else {
                util::Error(line_, "Unexpected char.");
                had_error_ = true;
            }

            break;
    }
}

void Scanner::String() {
    // Iterate through till we find the end of this string literal.
    while (Peek() != '\"' && !IsAtEnd()) {
        if (Peek() == '\n') line_++;
        Advance();
    }

    if (IsAtEnd()) {
        util::Error(line_, "Unterminated string.");
        had_error_ = true;
        return;
    }

    // Iterate past the closing `"`.
    Advance();

    // Get the value enclosing the quotes.
    std::string value = source_.substr(start_ + 1, current_ - 1);
    AddToken(
        Token::TokenType::STRING,
        std::make_unique<LoxString>(std::move(value)));
}

void Scanner::Number() {
    while (isdigit(Peek())) Advance();

    // Check if this is a decimal (double).
    bool is_decimal = false;
    if (Peek() == '.') {
        Advance();
        if (!isdigit(Peek())) {
            util::Error(line_, "Invalid number.");
            had_error_ = true;
            return;
        } else {
            is_decimal = true;
        }
    }

    while(isdigit(Peek())) Advance();

    if (is_decimal) {
        double value = std::stod(source_.substr(start_, current_));
        AddToken(
            Token::TokenType::DOUBLE,
            std::make_unique<LoxDouble>(value));
    } else {
        int value = std::stoi(source_.substr(start_, current_));
        AddToken(
            Token::TokenType::INTEGER,
            std::make_unique<LoxInteger>(value));
    }
}

void Scanner::Identifier() {
    while (isalnum(Peek())) Advance();

    const static std::map<std::string, Token::TokenType>
        keywords = {
            {"and", Token::TokenType::AND},
            {"class", Token::TokenType::CLASS},
            {"else", Token::TokenType::ELSE},
            {"false", Token::TokenType::FALSE},
            {"for", Token::TokenType::FOR},
            {"fun", Token::TokenType::FUN},
            {"if", Token::TokenType::IF},
            {"nil", Token::TokenType::NIL},
            {"or", Token::TokenType::OR},
            {"print", Token::TokenType::PRINT},
            {"return", Token::TokenType::RETURN},
            {"super", Token::TokenType::SUPER},
            {"this", Token::TokenType::THIS},
            {"true", Token::TokenType::TRUE},
            {"var", Token::TokenType::VAR},
            {"while", Token::TokenType::WHILE},
        };
    
    std::string keyword = source_.substr(start_, current_);

    const auto& type = keywords.find(keyword);
    if (type == keywords.end()) {
        // This is an identifier.
        AddToken(Token::TokenType::IDENTIFIER);
    } else {
        AddToken(type->second);
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

// char Scanner::PeekNext() {
//     if (current_ + 1 >= source_.length()) return '\0';
//     return source_[current_ + 1];
// }

}  // loxcompile

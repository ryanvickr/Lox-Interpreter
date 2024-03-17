// Author: Ryan Vickramasinghe
#ifndef SCANNER_H
#define SCANNER_H

#include <string>

#include "token.h"

namespace loxcompile {

class Scanner {
 public:
    explicit Scanner(const std::string& source);

 private:
    const std::string source_;
    std::vector<Token> tokens_;
};

}  // loxcompile

#endif // SCANNER_H

// Author: Ryan Vickramasinghe
#include <iostream>
#include <string_view>

namespace loxcompile::util {

void Report(int line, std::string_view where,
            std::string_view message) {
    std::cerr << "[line " << line << "] Error" << 
        where << ": " << message << std::endl;
}

void Error(int line, std::string_view message) {
    Report(line, "", message);
}

}  // loxcompile::util

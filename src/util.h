// Author: Ryan Vickramasinghe
#ifndef UTIL_H
#define UTIL_H

#include <string_view>

namespace loxcompile::util {

void Error(int line, std::string_view message);

void Report(int line, std::string_view where,
        std::string_view message);

}  // loxcompile::util

#endif // UTIL_H

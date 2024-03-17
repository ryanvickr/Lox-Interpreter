// Author: Ryan Vickramasinghe

#ifndef LOX_COMPILE_H
#define LOX_COMPILE_H

#include <string_view>

#include "lox-compile.h"

class LoxCompile {
 public:
    static void RunFile(std::string_view file_path);
};

#endif // LOX_COMPILE_H

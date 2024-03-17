// Author: Ryan Vickramasinghe

#ifndef LOX_COMPILE_H
#define LOX_COMPILE_H

#include <string_view>

#include "lox-compile.h"

namespace loxcompile {

class LoxCompile {
 public:
    void RunFile(std::string_view file_path);

 private:
    void Report(int line, std::string_view where,
            std::string_view message);

    void Error(int line, std::string_view message);

    bool had_error_ = false;
};

} // loxcompile

#endif // LOX_COMPILE_H

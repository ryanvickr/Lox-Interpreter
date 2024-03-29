// Author: Ryan Vickramasinghe
#ifndef LOX_COMPILE_H
#define LOX_COMPILE_H

#include <string_view>

#include "lox-compile.h"

namespace loxcompile {

class LoxCompile {
 public:
   void RunFile(std::string_view file_path);

   void RunPrompt();

 private:
    // void Run()

   // Signals that the code being compiled is not executable.
   bool had_error_ = false;
};

}  // loxcompile

#endif // LOX_COMPILE_H

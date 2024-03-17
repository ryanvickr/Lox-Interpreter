// Author: Ryan Vickramasinghe
#include <iostream>

#include "lox-compile.h"

using ::loxcompile::LoxCompile;

int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cerr << "Usage: clox []" << std::endl;
        return 1;
    }
    
    LoxCompile compiler;
    if (argc == 2) {
        // Interpret from the provided file.
        compiler.RunFile("");
    } else {
        compiler.RunPrompt();
    }

    return 0;
}
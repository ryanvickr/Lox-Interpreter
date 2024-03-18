// Author: Ryan Vickramasinghe
#include <iostream>

#include "src/lox-compile.h"

using ::loxcompile::LoxCompile;

int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cerr << "Usage: clox []" << std::endl;
        return 1;
    }
    
    LoxCompile compiler;
    if (argc == 2) {
        // Interpret from the provided file.
        compiler.RunFile(argv[1]);
    } else {
        // Opens a command prompt where you can interpret Lox
        // line-by-line.
        compiler.RunPrompt();

        // TODO: Uncomment the below line for testing.
        // compiler.RunFile("var test = \"abc\"//asdas");
    }

    return 0;
}
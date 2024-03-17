// Author: Ryan Vickramasinghe
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cerr << "Usage: clox []" << std::endl;
        return 1;
    } else if (argc == 2) {
        // Interpret from the provided file.
    } else {
        // Open the command prompt interpreter.
    }

    return 0;
}
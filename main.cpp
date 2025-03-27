#include <iostream>
#include <iomanip>
#include <cstring>
#include "ccwc.h"

int main(int argc, char* argv[]) {
    std::string option = "";
    const char* filename = nullptr;
    bool read_from_stdin = false;

    // Argument parsing
    if (argc == 1) {
        // No args: read from stdin, default output
        read_from_stdin = true;
    } else if (argc == 2) {
        if (argv[1][0] == '-') {
            // Option only, read from stdin
            option = argv[1];
            read_from_stdin = true;
        } else {
            // Filename only, default output
            filename = argv[1];
        }
    } else if (argc == 3) {
        // Option + filename
        option = argv[1];
        filename = argv[2];
    } else {
        std::cerr << "Usage:\n"
                  << "  ccwc [option] [filename]\n"
                  << "Options: -c, -l, -w, -m\n";
        return 1;
    }

    ccwc cw;
    FileStats stats;

    try {
        if (read_from_stdin) {
            stats = cw.read_file_stats("", 1);
        } else {
            stats = cw.read_file_stats(filename, 0);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    std::ios_base::fmtflags f(std::cout.flags()); // save format flags
    std::cout << std::setw(8);

    // Output based on option
    if (option == "-c") {
        std::cout << stats.byte_count;
    } else if (option == "-l") {
        std::cout << stats.line_count;
    } else if (option == "-w") {
        std::cout << stats.word_count;
    } else if (option == "-m") {
        std::cout << stats.char_count;
    } else {
        // Default: -l -w -c
        std::cout << std::setw(8) << stats.line_count
                  << std::setw(8) << stats.word_count
                  << std::setw(8) << stats.byte_count;
    }

    std::cout.flags(f); // restore flags

    // Only print filename if reading from file
    if (!read_from_stdin && filename != nullptr) {
        std::cout << " " << filename;
    }

    std::cout << std::endl;
    return 0;
}

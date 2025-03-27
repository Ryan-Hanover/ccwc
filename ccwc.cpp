//
// Created by rhanover on 3/26/25.
//

#include "ccwc.h"
#include <iostream>
#include <fstream>

#include <fstream>
#include <string>
#include <stdexcept>
#include <tuple>


FileStats ccwc::read_file_stats(const char* filename, int ver) {
    std::istream* istream_ptr;
    std::ifstream ifs;

    if (ver == 0) {
        // Open file
        ifs.open(filename, std::ios::in | std::ios::binary);
        if (!ifs.is_open()) {
            throw std::runtime_error("Failed to open file");
        }
        istream_ptr = &ifs;
    } else {
        // Use stdin
        istream_ptr = &std::cin;
    }

    FileStats stats{};
    char c;
    bool in_word = false;

    // Process the stream (counting lines, words, characters, and bytes)
    while (istream_ptr->get(c)) {
        stats.byte_count++;  // Count bytes directly
        stats.char_count++;  // Count characters

        // Count words
        if (std::isspace(static_cast<unsigned char>(c))) {
            if (in_word) {
                stats.word_count++;
                in_word = false;
            }
        } else {
            in_word = true;
        }

        // Count lines
        if (c == '\n') {
            stats.line_count++;
        }
    }

    // Count the last word if the input ends with a character (not a space)
    if (in_word) {
        stats.word_count++;
    }

    return stats;
}












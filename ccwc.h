//
// Created by rhanover on 3/26/25.
//

#ifndef CCWC_H
#define CCWC_H
#include <fstream>

struct FileStats {
    size_t byte_count = 0;
    size_t word_count = 0;
    size_t line_count = 0;
    size_t char_count = 0;
};

class ccwc {
    public:
  FileStats read_file_stats(const char* filename,int ver);

};



#endif //CCWC_H

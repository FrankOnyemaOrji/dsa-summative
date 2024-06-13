#include <stdio.h>
#include "huffman.h"
#include "file_ops.h"

//author: Frank Onyema Orji

int main() {
    const char *filename = "input.txt";
    readFileAndCompress(filename);
    return 0;
}

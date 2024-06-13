#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"
#include "file_ops.h"

//author: Frank Onyema Orji

// Function to get the file size
long getFileSize(FILE *file) {
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

void readFileAndCompress(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    int freq[256] = {0};
    int total_chars = 0;

    long originalSize = getFileSize(file);
    printf("Original file size: %ld bytes\n", originalSize);

    calculateFreq(file, freq, &total_chars);

    char *data = (char *)malloc(total_chars * sizeof(char));
    int *frequency = (int *)malloc(total_chars * sizeof(int));
    int index = 0;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            data[index] = (char)i;
            frequency[index] = freq[i];
            index++;
        }
    }

    printf("Huffman Codes:\n");
    HuffmanCodes(data, frequency, index);

    fclose(file);
    free(data);
    free(frequency);
}

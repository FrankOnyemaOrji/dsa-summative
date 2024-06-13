#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>

//author: Frank Onyema Orji

// Structure for the Huffman tree node
typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

// Structure for the min heap
typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode **array;
} MinHeap;

MinHeapNode* newNode(char data, unsigned freq);
MinHeap* createMinHeap(unsigned capacity);
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b);
void minHeapify(MinHeap* minHeap, int idx);
int isSizeOne(MinHeap* minHeap);
MinHeapNode* extractMin(MinHeap* minHeap);
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode);
void buildMinHeap(MinHeap* minHeap);
void printArr(int arr[], int n);
int isLeaf(MinHeapNode* root);
MinHeap* createAndBuildMinHeap(char data[], int freq[], int size);
MinHeapNode* buildHuffmanTree(char data[], int freq[], int size);
void printCodes(MinHeapNode* root, int arr[], int top);
void HuffmanCodes(char data[], int freq[], int size);
void calculateFreq(FILE *fp, int freq[], int *total_chars);

#endif // HUFFMAN_H

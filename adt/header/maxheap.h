#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct {
    int *elements;
    int size;
} MaxHeap;

MaxHeap createMaxHeap();
void insert(MaxHeap *heap, int key);
int extractMax(MaxHeap *heap);
int getMax(MaxHeap heap);
void heapifyUp(MaxHeap *heap, int index);
void heapifyDown(MaxHeap *heap, int index);
void buildMaxHeap(MaxHeap *heap, int *array, int size);
void printMaxHeap(MaxHeap heap);

#endif

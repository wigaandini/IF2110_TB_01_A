#include "header/maxheap.h"

MaxHeap createMaxHeap() {
    MaxHeap heap;
    heap.elements = (int *)malloc(MAX_HEAP_SIZE * sizeof(int));
    heap.size = 0;
    return heap;
}

void insert(MaxHeap *heap, int key) {
    if (heap->size < MAX_HEAP_SIZE) {
        heap->elements[heap->size] = key;
        heapifyUp(heap, heap->size);
        heap->size++;
        printMaxHeap(*heap);
    } else {
        printf("Heap is full. Cannot insert element.\n");
    }
}

int extractMax(MaxHeap *heap) {
    if (heap->size > 0) {
        int max = heap->elements[0];
        heap->size--;
        heap->elements[0] = heap->elements[heap->size];
        heapifyDown(heap, 0);
        return max;
    } else {
        printf("Heap is empty. Cannot extract maximum.\n");
        return -1;
    }
}

int getMax(MaxHeap heap) {
    if (heap.size > 0) {
        return heap.elements[0];
    } else {
        printf("Heap is empty. Cannot get maximum.\n");
        return -1;
    }
}

void heapifyUp(MaxHeap *heap, int index) {
    while (index > 0 && heap->elements[index] > heap->elements[(index - 1) / 2]) {
        // Swap with parent
        int temp = heap->elements[index];
        heap->elements[index] = heap->elements[(index - 1) / 2];
        heap->elements[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

void heapifyDown(MaxHeap *heap, int index) {
    int maxIndex = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->elements[leftChild] > heap->elements[maxIndex]) {
        maxIndex = leftChild;
    }

    if (rightChild < heap->size && heap->elements[rightChild] > heap->elements[maxIndex]) {
        maxIndex = rightChild;
    }

    if (index != maxIndex) {
        // Swap with the larger child
        int temp = heap->elements[index];
        heap->elements[index] = heap->elements[maxIndex];
        heap->elements[maxIndex] = temp;
        heapifyDown(heap, maxIndex);
    }
}

void buildMaxHeap(MaxHeap *heap, int *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        insert(heap, array[i]);
    }
}

void printMaxHeap(MaxHeap heap) {
    int i;
    for (i = 0; i < heap.size; i++) {
        printf("%d ", heap.elements[i]);
    }
    printf("\n");
}

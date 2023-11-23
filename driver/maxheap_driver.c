#include <stdio.h>
#include "../adt/maxheap.c"

int main() {
    // Membuat heap
    MaxHeap heap = createMaxHeap();

    // Menambahkan elemen
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 5);
    insert(&heap, 15);

    exit(0);

    printf("Max Heap after insertions: ");
    printMaxHeap(heap);

    // Mendapatkan nilai maksimum
    printf("Max Element: %d\n", getMax(heap));

    // Ekstraksi nilai maksimum
    int extractedMax = extractMax(&heap);
    printf("Extracted Max Element: %d\n", extractedMax);

    printf("Max Heap after extraction: ");
    printMaxHeap(heap);

    // Menguji buildMaxHeap
    int array[] = {25, 30, 8, 40, 5};
    int size = sizeof(array) / sizeof(array[0]);

    // Membuat heap dari array
    MaxHeap arrayHeap = createMaxHeap();
    buildMaxHeap(&arrayHeap, array, size);

    printf("Max Heap from array: ");
    printMaxHeap(arrayHeap);

    return 0;
}

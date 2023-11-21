#include <stdio.h>
#include "../adt/prioqueuetime.c"

int main() {
    PrioQueueTime Q;
    infotype X;

    // Inisialisasi Priority Queue
    MakeEmpty(&Q, 5);

    // Menambahkan elemen ke dalam Priority Queue
    X.time = 3;
    X.info = 'A';
    Enqueue(&Q, X);

    X.time = 1;
    X.info = 'B';
    Enqueue(&Q, X);

    X.time = 2;
    X.info = 'C';
    Enqueue(&Q, X);

    X.time = 4;
    X.info = 'D';
    Enqueue(&Q, X);

    // Mencetak isi Priority Queue
    printf("Isi Priority Queue:\n");
    PrintPrioQueueTime(Q);

    // Menghapus elemen dari Priority Queue
    Dequeue(&Q, &X);
    printf("Dequeue: %d %c\n", Time(X), Info(X));

    // Mencetak isi Priority Queue setelah Dequeue
    printf("Isi Priority Queue setelah Dequeue:\n");
    PrintPrioQueueTime(Q);

    // Dealokasi memori
    DeAlokasi(&Q);

    return 0;
}

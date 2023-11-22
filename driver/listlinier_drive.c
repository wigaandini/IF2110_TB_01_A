#include <stdio.h>
#include "../adt/listlinier.c"
#define here printf("here\n");

int main() {
    List l1, l2;
    CreateList(&l1);
    CreateList(&l2);

    // Menambahkan elemen ke dalam list l1
    insertLast(&l1, 10);
    insertLast(&l1, 20);
    insertLast(&l1, 30);

    // Menampilkan isi list l1
    printf("Isi list l1: ");
    displayList(l1);
    printf("\n");

    // Menambahkan elemen ke dalam list l2
    insertLast(&l2, 40);
    insertLast(&l2, 50);
    insertLast(&l2, 60);

    // Menampilkan isi list l2
    printf("Isi list l2: ");
    displayList(l2);
    printf("\n");

    // Menggabungkan list l1 dan l2
    List l3 = concat(l1, l2);
    printf("Isi list setelah penggabungan l1 dan l2: ");
    displayList(l3);
    printf("\n");

    // Mencari nilai maksimum dan minimum dalam list l3
    printf("Nilai maksimum dalam list l3: %d\n", max(l3));
    printf("Nilai minimum dalam list l3: %d\n", min(l3));

    // Mencari rata-rata nilai dalam list l3
    printf("Rata-rata nilai dalam list l3: %.2f\n", average(l3));

    // Membuat salinan dari list l3
    List l4 = fCopyList(l3);
    printf("Isi list l4 (salinan dari l3): ");
    displayList(l4);
    printf("\n");

    // Memutar list l4
    inverseList(&l4);
    printf("Isi list l4 setelah diputar: ");
    displayList(l4);
    printf("\n");

    // Membersihkan list l1, l2, dan l3
    deleteAll(&l1);
    deleteAll(&l2);
    deleteAll(&l3);

    // Menampilkan isi list l1, l2, dan l3
    printf("Isi list l1 setelah dibersihkan: ");
    displayList(l1);
    printf("\n");
    printf("Isi list l2 setelah dibersihkan: ");
    displayList(l2);
    printf("\n");
    printf("Isi list l3 setelah dibersihkan: ");
    displayList(l3);
    printf("\n");

    return 0;
}

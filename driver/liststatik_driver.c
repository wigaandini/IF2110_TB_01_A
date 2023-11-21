#include <stdio.h>
#include "../adt/liststatik.c"

int main() {
    ListStatik l1, l2, l3;
    ElType max, min;

    // Menguji konstruktor dan fungsi-fungsi dasar
    CreateListStatik(&l1);
    CreateListStatik(&l2);

    // Menguji operasi pembacaan dan penulisan list
    printf("Masukkan elemen-elemen untuk list l1:\n");
    readList(&l1);
    printf("List l1: ");
    printList(l1);
    printf("\n");

    printf("Masukkan elemen-elemen untuk list l2:\n");
    readList(&l2);
    printf("List l2: ");
    printList(l2);
    printf("\n");

    // Menguji operasi penjumlahan dan pengurangan list
    l3 = plusMinusList(l1, l2, true);
    printf("Hasil penjumlahan l1 dan l2: ");
    printList(l3);
    printf("\n");

    l3 = plusMinusList(l1, l2, false);
    printf("Hasil pengurangan l1 dan l2: ");
    printList(l3);
    printf("\n");

    // Menguji operasi pembandingan list
    if (isListEqual(l1, l2)) {
        printf("List l1 sama dengan list l2.\n");
    } else {
        printf("List l1 tidak sama dengan list l2.\n");
    }

    // Menguji operasi searching
    ElType valToSearch = 0;
    IdxType idx = indexOf(l1, valToSearch);
    if (idx != IDX_UNDEF) {
        printf("Nilai %d ditemukan pada indeks %d di list l1.\n", valToSearch, idx);
    } else {
        printf("Nilai %d tidak ditemukan di list l1.\n", valToSearch);
    }

    // Menguji operasi nilai ekstrem
    extremeValues(l1, &max, &min);
    printf("Nilai maksimum di list l1: %d\n", max);
    printf("Nilai minimum di list l1: %d\n", min);

    // Menguji operasi penambahan elemen
    ElType newVal = 99;
    insertFirst(&l1, newVal);
    printf("List l1 setelah menambahkan %d di awal: ", newVal);
    printList(l1);
    printf("\n");

    // Menguji operasi penghapusan elemen
    ElType removedVal;
    deleteLast(&l1, &removedVal);
    printf("List l1 setelah menghapus elemen terakhir (%d): ", removedVal);
    printList(l1);
    printf("\n");

    // Menguji operasi sorting
    sortList(&l1, true);
    printf("List l1 setelah diurutkan secara ascending: ");
    printList(l1);
    printf("\n");

    return 0;
}

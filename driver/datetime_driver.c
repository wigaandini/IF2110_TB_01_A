#include <stdio.h>
#include "../adt/datetime.c"
#include "../adt/time.c"

int main() {
    DATETIME dateTime1, dateTime2;

    // Uji fungsi BacaDATETIME
    printf("Uji fungsi BacaDATETIME:\n");
    printf("Masukkan DATETIME 1 (DD MM YYYY hh mm ss): ");
    BacaDATETIME(&dateTime1);
    printf("DATETIME 1: ");
    TulisDATETIME(dateTime1);

    printf("\n\n");

    // Uji fungsi TulisDATETIME
    printf("Uji fungsi TulisDATETIME:\n");
    printf("DATETIME 1: ");
    TulisDATETIME(dateTime1);

    printf("\n\n");

    // Uji fungsi DEQ
    printf("Uji fungsi DEQ:\n");
    printf("Masukkan DATETIME 2 (DD MM YYYY hh mm ss): ");
    BacaDATETIME(&dateTime2);
    printf("DATETIME 1: ");
    TulisDATETIME(dateTime1);
    printf("\nDATETIME 2: ");
    TulisDATETIME(dateTime2);
    if (DEQ(dateTime1, dateTime2)) {
        printf("\nDATETIME 1 sama dengan DATETIME 2\n");
    } else {
        printf("\nDATETIME 1 tidak sama dengan DATETIME 2\n");
    }

    printf("\n\n");

    // Uji fungsi DNEQ
    printf("Uji fungsi DNEQ:\n");
    if (DNEQ(dateTime1, dateTime2)) {
        printf("DATETIME 1 tidak sama dengan DATETIME 2\n");
    } else {
        printf("DATETIME 1 sama dengan DATETIME 2\n");
    }

    printf("\n\n");

    // Uji fungsi DLT
    printf("Uji fungsi DLT:\n");
    if (DLT(dateTime1, dateTime2)) {
        printf("DATETIME 1 kurang dari DATETIME 2\n");
    } else {
        printf("DATETIME 1 tidak kurang dari DATETIME 2\n");
    }

    printf("\n\n");

    // Uji fungsi DGT
    printf("Uji fungsi DGT:\n");
    if (DGT(dateTime1, dateTime2)) {
        printf("DATETIME 1 lebih dari DATETIME 2\n");
    } else {
        printf("DATETIME 1 tidak lebih dari DATETIME 2\n");
    }

    printf("\n\n");

    // Uji fungsi DATETIMENextNDetik
    printf("Uji fungsi DATETIMENextNDetik:\n");
    int detik;
    printf("Masukkan jumlah detik yang ingin ditambahkan: ");
    scanf("%d", &detik);
    DATETIME nextDateTime = DATETIMENextNDetik(dateTime1, detik);
    printf("DATETIME setelah ditambah %d detik: ", detik);
    TulisDATETIME(nextDateTime);

    printf("\n\n");

    // Uji fungsi DATETIMEPrevNDetik
    printf("Uji fungsi DATETIMEPrevNDetik:\n");
    printf("Masukkan jumlah detik yang ingin dikurangkan: ");
    scanf("%d", &detik);
    DATETIME prevDateTime = DATETIMEPrevNDetik(dateTime1, detik);
    printf("DATETIME setelah dikurangkan %d detik: ", detik);
    TulisDATETIME(prevDateTime);

    printf("\n\n");

    // Uji fungsi DATETIMEDurasi
    printf("Uji fungsi DATETIMEDurasi:\n");
    long int durasi = DATETIMEDurasi(dateTime1, dateTime2);
    printf("Durasi antara DATETIME 1 dan DATETIME 2 dalam detik: %ld\n", durasi);

    return 0;
}

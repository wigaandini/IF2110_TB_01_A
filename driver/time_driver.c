#include <stdio.h>
#include "../adt/time.c"

int main() {
    TIME t1, t2;
    int detik;

    printf("Masukkan waktu pertama (HH MM SS): ");
    BacaTIME(&t1);

    printf("Masukkan waktu kedua (HH MM SS): ");
    BacaTIME(&t2);

    printf("\nWaktu pertama: ");
    TulisTIME(t1);

    printf("\nWaktu kedua: ");
    TulisTIME(t2);

    if (TEQ(t1, t2)) {
        printf("\nWaktu pertama sama dengan waktu kedua.\n");
    } else {
        printf("\nWaktu pertama tidak sama dengan waktu kedua.\n");
    }

    if (TNEQ(t1, t2)) {
        printf("Waktu pertama tidak sama dengan waktu kedua.\n");
    } else {
        printf("Waktu pertama sama dengan waktu kedua.\n");
    }

    if (TLT(t1, t2)) {
        printf("Waktu pertama lebih awal dari waktu kedua.\n");
    } else {
        printf("Waktu pertama tidak lebih awal dari waktu kedua.\n");
    }

    if (TGT(t1, t2)) {
        printf("Waktu pertama lebih akhir dari waktu kedua.\n");
    } else {
        printf("Waktu pertama tidak lebih akhir dari waktu kedua.\n");
    }

    printf("\nWaktu setelah 1 detik dari waktu pertama: ");
    TulisTIME(NextDetik(t1));

    printf("\nWaktu setelah 10 detik dari waktu pertama: ");
    TulisTIME(NextNDetik(t1, 10));

    printf("\nWaktu sebelum 1 detik dari waktu pertama: ");
    TulisTIME(PrevDetik(t1));

    printf("\nWaktu sebelum 5 detik dari waktu pertama: ");
    TulisTIME(PrevNDetik(t1, 5));

    detik = Durasi(t1, t2);
    printf("\nDurasi antara dua waktu dalam detik: %d detik\n", detik);

    return 0;
}

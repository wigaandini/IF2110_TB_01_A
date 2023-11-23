#include "../adt/header/listdinkicauan.h"
#include "../adt/header/liststatikuser.h"

// Perintah FYB (For Your BurBir)
// Menampilkan 8 kicauan dengan like terbanyak
void fyb(ListStatikUser userData, ListKicauan listkicau) {
    ListKicauan bestKicau;
    CreateListGlobalKicauan(&bestKicau, listkicau.nEff);
    bestKicau = listkicau;

    if (listkicau.nEff == 0) {
        printf("\nTidak ada kicauan yang dapat ditampilkan\n");
    }
    else {
        int i, j;
        Kicauan temp;
        for (i = 0; i < bestKicau.nEff; i++) {
            for (j = i + 1; j < bestKicau.nEff; j++) {
                if (bestKicau.buffer[i].like < bestKicau.buffer[j].like) {
                    temp = bestKicau.buffer[i];
                    bestKicau.buffer[i] = bestKicau.buffer[j];
                    bestKicau.buffer[j] = temp;
                }
            }
        }

        printf("\nBerikut 8 kicauan dengan like tertinggi di FYB\n");
        for (i = 0; i < 8; i++) {
            if (i < bestKicau.nEff) {
                printf("\nKicauan %d:\n", i + 1);
                // DisplaySatuKicau(userData, bestKicau.buffer[i]);
                printf("| %s\n", userData.data[IDAUTHOR(bestKicau.buffer[i])-1].nama);
                printf("| ");
                TulisDATETIME(WAKTU(bestKicau.buffer[i]));
                printf("\n");
                printf("| ");
                displayWord(TEXT(bestKicau.buffer[i]));
                printf("\n");
                printf("| Disukai: %d\n", LIKE(bestKicau.buffer[i]));
            }
        }
        printf("\n");
    }
}
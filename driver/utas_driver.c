#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../adt/header/boolean.h"
#include "../adt/wordmachine.c"
#include "../adt/listlinierutas.c"
#include "../adt/listdinkicauan.c"
#include "../adt/liststatikuser.c"
#include "../adt/charmachine.c"
#include "../adt/datetime.c"
#include "../adt/friendmatrix.c"
#include "../program/utas.c"
#include "../adt/time.c"
#include "../adt/matrix.c"
#include "../adt/listdin.c"
#include "../adt/pcolor.c"
#include "../program/user.c"

int main() {
    Word w, command, kata;
    ListLinierUtas listUtas;
    ListKicauan listKicau;
    ListStatikUser listUser;
    UtasType u;
    int idUser, idKicau, idUtas, index;

    idUser = 1;
    idKicau = 1;

    do {
        printf(">> ");
        STARTSENTENCE();
        command = currentWord;
        printf("%d\n", countWords(command));

        if (countWords(command) == 1) {
            displayWord(command);
            printf("\n");
            kata = command;
        } else {
            kata = splitCommand(&w, command, 1);
            displayWord(kata);
            printf("\n");
        }

        if (compareString(kata, "UTAS")) {
            idKicau = WordToInt(splitCommand(&w, command, 2));
            printf("kata: ");
            displayWord(kata);
            printf("\n");
            printf("idKicau: %d\n", idKicau);
            BIKIN_UTAS(idKicau, &listKicau, &listUtas, idUser, &u);
        } else if (compareString(kata, "SAMBUNG_UTAS")) {
            idUtas = WordToInt(splitCommand(&w, command, 2));
            index = WordToInt(splitCommand(&w, command, 3));
            printf("kata: ");
            displayWord(kata);
            printf("\n");
            printf("idUtas: %d\n", idUtas);
            printf("index: %d\n", index);
            SAMBUNG_UTAS(idUtas, index, &listUtas, idUser, &u, listKicau);
        } else if (compareString(kata, "HAPUS_UTAS")) {
            idUtas = WordToInt(splitCommand(&w, command, 2));
            index = WordToInt(splitCommand(&w, command, 3));
            printf("kata: ");
            displayWord(kata);
            printf("\n");
            printf("idUtas: %d\n", idUtas);
            printf("index: %d\n", index);
            HAPUS_UTAS(idUtas, index, &listUtas, idUser, &u, listKicau);
        } else if (compareString(kata, "CETAK_UTAS")) {
            idUtas = WordToInt(splitCommand(&w, command, 2));
            printf("kata: ");
            displayWord(kata);
            printf("\n");
            printf("idUtas: %d\n", idUtas);
            CETAK_UTAS(listUser, listUtas, idUser, idUtas, listKicau);
        } else if (compareString(kata, "TUTUP_PROGRAM")) {
            TUTUP_PROGRAM();
        }
    } while (!compareString(kata, "TUTUP_PROGRAM"));
}
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

int main(){
    ListStatikUser l;
    CreateListStatikUser(&l);
    boolean login = false;
    int idUser = 1;

    do {
        printf(">> ");
        STARTSENTENCE();
        displayWord(currentWord);
        printf("\n");

        if (compareString(currentWord, "DAFTAR")) {
            DAFTAR(&l, login);
            printListofUser(l);
        } else if (compareString(currentWord, "KELUAR")) {
            KELUAR(&l, &login, &idUser);
        } else if (compareString(currentWord, "MASUK")) {
            MASUK(&l, &login, &idUser);
        } else if (compareString(currentWord, "TUTUP_PROGRAM")) {
            TUTUP_PROGRAM();
        }
    } while (!compareString(currentWord, "TUTUP_PROGRAM"));

    return 0;
}

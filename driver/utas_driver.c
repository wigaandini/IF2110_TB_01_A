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
    Word w, command, kata;
    ListLinierUtas listUtas;
    ListUtas listUtasGlobal;
    ListKicauan listKicau;
    ListStatikUser listUser;
    UtasType u;
    int idUser, idKicau, idUtas, index;

    CreateListUtasGlobal(&listUtasGlobal, CAPACITYMAXLISTKICAUAN);

    idUser = 1; // sementara, nantinya nyesuaiin sama user yg lagi login
    idKicau = 1; // sementara, nanti disesuaiin pas user login
    do {      
        printf(">> ");
        STARTSENTENCE();
        command = currentWord;
        kata = splitCommand(&w, command, 1);
        displayWord(kata);
        printf("\n");
        
        if(compareString(kata,"UTAS")){
            idKicau = WordToInt(splitCommand(&w, currentWord, 2));
            BIKIN_UTAS(idKicau, &listKicau, &listUtas, &listUtasGlobal, idUser, &u);
        }
        else if(compareString(kata,"SAMBUNG_UTAS")){
            idUtas = WordToInt(splitCommand(&w, currentWord, 2));
            index = WordToInt(splitCommand(&w, currentWord, 3));
            SAMBUNG_UTAS(idUtas, index, &listUtas, &listUtasGlobal, idUser, &u);
        }
        else if(compareString(kata,"HAPUS_UTAS")){
            idUtas = WordToInt(splitCommand(&w, currentWord, 2));
            index = WordToInt(splitCommand(&w, currentWord, 3));
            HAPUS_UTAS(idUtas, index, &listUtas, &listUtasGlobal, idUser, &u);
        }
        else if(compareString(kata,"CETAK_UTAS")){
            idUtas = WordToInt(splitCommand(&w, currentWord, 2));
            CETAK_UTAS(listUser, listUtasGlobal, listUtas, idUser, idUtas);
        }
        else if(compareString(kata, "TUTUP_PROGRAM")){
            TUTUP_PROGRAM();
        }
    } while (!compareString(kata, "TUTUP_PROGRAM"));
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../adt/header/boolean.h"
#include "../adt/wordmachine.c"
#include "../adt/listlinierutas.c"
#include "../adt/listdinkicauan.c"
#include "../adt/liststatikuser.c"
#include "../adt/charmachine.c"


int main(){
    Word w, command;
    ListLinierUtas listUtas;
    ListUtas listUtasGlobal;
    ListKicauan listKicau;
    ListStatikUser listUser;
    UtasType u;
    int idUser, idKicau, idUtas, index;

    CreateListUtasGLobal(&listUtasGlobal, CAPACITYMAXLISTKICAUAN);

    idUser = 1; // sementara, nantinya nyesuaiin sama user yg lagi login
    do {      
        printf(">> ");
        STARTSENTENCE();
        command = splitCommand(&w, currentWord, 1);
        
        if(compareString(command,"UTAS")){
            idKicau = WordToInt(splitCommand(&w, currentWord, 2));
            UTAS(idKicau, &listKicau, &listUtas, &listUtasGlobal, idUser, &u);
        }
        else if(compareString(command,"SAMBUNG_UTAS")){
            idUtas = WordToInt(splitCommand(&w, currentWord, 2));
            index = WordToInt(splitCommand(&w, currentWord, 3));
            SAMBUNG_UTAS(idUtas, index, &listUtas, &listUtasGlobal, idUser, &u);
        }
        else if(compareString(command,"HAPUS_UTAS")){
            idUtas = WordToInt(splitCommand(&w, currentWord, 2));
            index = WordToInt(splitCommand(&w, currentWord, 3));
            HAPUS_UTAS(idUtas, index, &listUtas, &listUtasGlobal, idUser, &u);
        }
        else if(compareString(command,"CETAK_UTAS")){
            idUtas = WordToInt(splitCommand(&w, currentWord, 2));
            CETAK_UTAS(listUser, listUtasGlobal, listUtas, idUser, idUtas);
        }
        
    } while (!compareString(currentWord, "EXIT"));
}

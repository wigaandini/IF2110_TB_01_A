#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../adt/header/boolean.h"
#include "../adt/header/charmachine.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/time.h"
#include "../adt/header/datetime.h"
#include "../adt/header/listdinkicauan.h"
#include "../adt/header/friendmatrix.h"
#include "../adt/header/treebalasan.h"
#include "../program/kicauan.c"
#include "../program/utas.c"
#include "../adt/header/listlinierutas.h"


// gcc -o main driver/kicauan_utas_driver.c adt/wordmachine.c adt/charmachine.c adt/datetime.c adt/listdinkicauan.c adt/time.c adt/friendmatrix.c adt/listlinierutas.c 

int main() {
    Word w, command, kata, kata2;
    ListKicauan k;
    ListStatikUser l;
    Kicauan tweet;
    int idUser, idKicauan, idUtas, index;
    ListLinierUtas listUtas;
    UtasType u;
    FriendMatrix m;

    CreateListGlobalKicauan(&k, CAPACITYMAXLISTKICAUAN);

    idUser = 1; // sementara, nantinya nyesuaiin sama user yg lagi login
    do {      
        printf(">> ");
        STARTSENTENCE();
        command = currentWord;
        kata = splitCommand(&w, command, 1);

        if (command.Length>kata.Length) {
            kata2 = splitCommand(&w, command, 2);
            idKicauan = WordToInt(kata2);
        } 
        
        if(compareString(kata,"KICAU")){
            Berkicau(l, &k, &tweet, idUser);
            printf("id di driver : %d\n", ID(ELMTLISTKICAU(k, 0)));
        }
        else if(compareString(kata,"KICAUAN")){
            DisplayKicauan(l, k, idUser, m);
        }
        else if(compareString(kata,"SUKA_KICAUAN")){
            SUKA_KICAUAN(l, &k, idKicauan, idUser, m);
        }
        else if(compareString(kata,"UBAH_KICAUAN")){
            UBAH_KICAUAN(l, &k, idKicauan, idUser);
        }else if (compareString(kata, "UTAS")) {
            idKicauan = WordToInt(splitCommand(&w, command, 2));
            printf("kata: ");
            displayWord(kata);
            printf("\n");
            printf("idKicauan: %d\n", idKicauan);
            BIKIN_UTAS(idKicauan, &k, &listUtas, idUser, &u);
            printf("count utas : %d\n", countTypeUtas(k));
        } else if (compareString(kata, "SAMBUNG_UTAS")) {
            idUtas = WordToInt(splitCommand(&w, command, 2));
            index = WordToInt(splitCommand(&w, command, 3));
            printf("kata: ");
            displayWord(kata);
            printf("\n");
            printf("idUtas: %d\n", idUtas);
            printf("index: %d\n", index);
            SAMBUNG_UTAS(idUtas, index, &listUtas, idUser, &u, k);
        } else if (compareString(kata, "HAPUS_UTAS")) {
            idUtas = WordToInt(splitCommand(&w, command, 2));
            index = WordToInt(splitCommand(&w, command, 3));
            printf("kata: ");
            displayWord(kata);
            printf("\n");
            printf("idUtas: %d\n", idUtas);
            printf("index: %d\n", index);
            HAPUS_UTAS(idUtas, index, &listUtas, idUser, &u, k);
        } else if (compareString(kata, "CETAK_UTAS")) {
            idUtas = WordToInt(splitCommand(&w, command, 2));
            printf("kata: ");
            displayWord(kata);
            printf("\n");
            printf("idUtas: %d\n", idUtas);
            CETAK_UTAS(l, listUtas, idUser, idUtas, k);
        }

    } while (!compareString(currentWord, "TUTUP_PROGRAM"));
}
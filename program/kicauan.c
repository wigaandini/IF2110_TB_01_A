#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../adt/header/boolean.h"
#include "../adt/charmachine.c"
#include "../adt/wordmachine.c"
#include "../adt/time.c"
#include "../adt/datetime.c"
#include "../adt/listdinkicauan.c"
#include "../adt/friendmatrix.c"

// gcc -o main program/kicauan.c adt/string.c adt/wordmachine.c adt/charmachine.c adt/datetime.c adt/listdinkicauan.c adt/time.c adt/friendmatrix.c 

int main() {
    Word w, command, kata, kata2;
    ListKicauan k;
    ListStatikUser l;
    Kicauan tweet;
    int idUser, idKicauan;
    FriendMatrix m;

    CreateListGlobalKicauan(&k, CAPACITYMAXLISTKICAUAN);

    idUser = 1; // sementara, nantinya nyesuaiin sama user yg lagi login
    do {      
        printf(">> ");
        STARTSENTENCE();
        command = currentWord;
        kata = splitCommand(&w, command, 1);
        displayWord(kata);

        if (command.Length>kata.Length) {
            kata2 = splitCommand(&w, command, 2);
            idKicauan = WordToInt(kata2);
        } 
        
        if(compareString(kata,"KICAU")){
            Berkicau(l, &k, &tweet, idUser);
        }
        else if(compareString(kata,"KICAUAN")){
            DisplayKicauan(l, k, idUser, m);
        }
        else if(compareString(kata,"SUKA_KICAUAN")){
            SUKA_KICAUAN(l, &k, idKicauan, idUser, m);
        }
        else if(compareString(kata,"UBAH_KICAUAN")){
            UBAH_KICAUAN(l, &k, idKicauan, idUser);
        }
        
    } while (!compareString(currentWord, "EXIT"));
    
}
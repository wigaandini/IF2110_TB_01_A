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

// gcc -o main driver/kicauan_driver.c program/kicauan.c adt/wordmachine.c adt/charmachine.c adt/datetime.c adt/listdinkicauan.c adt/time.c adt/friendmatrix.c 

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
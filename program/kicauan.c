#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../adt/header/boolean.h"
#include "../adt/header/charmachine.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/time.h"
#include "../adt/header/datetime.h"
#include "../adt/header/listdinkicauan.h"
#include "../adt/header/string.h"
#include "../adt/header/friendmatrix.h"

int main() {
    Word w, kata, cWord, kata2;
    ListKicauan k;
    ListStatikUser l;
    Kicauan tweet;
    int idUser, idKicauan;
    FriendMatrix m;

    CreateListGlobalKicauan(&k, CAPACITYMAXLISTKICAUAN);

    // sementara
    idUser = 1;
    printf(">> ");
    STARTSENTENCE();
    cWord = currentWord;
    kata = splitCommand(&w, cWord, 1);
    
    if (cWord.Length>kata.Length) {
        kata2 = splitCommand(&w, cWord, 2);
        idKicauan = WordToInt(kata2);
    }

    if(compareString(kata,"KICAU")){
        Berkicau(&k, &tweet, idUser);
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
}
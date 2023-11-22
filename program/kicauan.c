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
#include "../adt/header/listlinierutas.h"

void Berkicau(ListStatikUser U, ListKicauan *l, Kicauan *k, int idauthor){
    int id;
    DATETIME waktu;
    Word text;

    id = NEFFLISTKICAU(*l) + 1;

    time_t current_time;
    time(&current_time);
    current_time+=3600*7;

    struct tm* timeinfo = gmtime(&current_time);

    Year(waktu) = 1900 + timeinfo->tm_year;
    Month(waktu) = timeinfo->tm_mon + 1;
    Day(waktu) = timeinfo->tm_mday;
    Time(waktu) = DetikToTIME(current_time);


    printf("Masukkan kicauan :\n");
    STARTSENTENCE();
    text = currentWord;
    if (isEmptyWord(text)) {
        printf("Kicauan tidak boleh hanya berisi spasi!\n");
    } else {
        CreateKicauan(k, id, text, idauthor, waktu);

        printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
        DisplaySatuKicau(U, *k);
        insertLastKicauan(l, *k);
    }
}

void DisplayKicauan(ListStatikUser l, ListKicauan k, int idUser, FriendMatrix m){
    int idAuthor;
    for (int i = NEFFLISTKICAU(k) - 1 ; i >= 0; i--) {
        idAuthor = IDAUTHOR(ELMTLISTKICAU(k, i));
        if (idAuthor == idUser) {
            DisplaySatuKicau(l, ELMTLISTKICAU(k, i));
        } else {
            if(isFriend(m, idAuthor, idUser)){
                DisplaySatuKicau(l, ELMTLISTKICAU(k, i));
            }
        } 
    }
}

void SUKA_KICAUAN(ListStatikUser l, ListKicauan *k, int idKicauan, int idUser, FriendMatrix m){
    if (!isIdKicauanValid(*k, idKicauan)) {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", idKicauan);
    } else {
        int idAuthor = IDAUTHOR(ELMTLISTKICAU(*k, idKicauan-1));
        if(UserTipe(l, idAuthor-1) == PUBLIK){
            LIKE(ELMTLISTKICAU(*k, idKicauan-1))++;
        }  else {
            if (idAuthor == idUser) {
                LIKE(ELMTLISTKICAU(*k, idKicauan-1))++;
            } else {
                if(isFriend(m, idAuthor, idUser)){
                    LIKE(ELMTLISTKICAU(*k, idKicauan-1))++;
                } else {
                    printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
                }
            }
        }
        DisplaySatuKicau(l, ELMTLISTKICAU(*k,idKicauan-1));
    }
}

void UBAH_KICAUAN(ListStatikUser l, ListKicauan *k, int idKicauan, int idUser){
    Word newText;

    if (isIdKicauanValid(*k, idKicauan)) {
        int idAuthor = IDAUTHOR(ELMTLISTKICAU(*k, idKicauan-1));
        if (idAuthor == idUser) {
            printf("Masukkan kicauan baru : \n");
            STARTSENTENCE();
            newText = currentWord;
            TEXT(ELMTLISTKICAU(*k,idKicauan-1)) = newText;
            DisplaySatuKicau(l, ELMTLISTKICAU(*k, idKicauan-1));
        } else {
            printf("Kicauan dengan ID = %d bukan milikmu!\n", idKicauan);
        }
    } else {
        printf("Tidak ditemukan kicauan dengan ID = %d!\n", idKicauan);
    }
}
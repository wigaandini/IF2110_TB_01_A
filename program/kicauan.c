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
    if (idauthor==-1)
    {
        printf("\nAnda belum masuk. Masuk dulu yuk!\n\n");
    } else {
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


        printf("\nMasukkan kicauan :\n");
        STARTSENTENCE();
        text = currentWord;
        if (isEmptyWord(text)) {
            printf("\nKicauan tidak boleh hanya berisi spasi!\n");
        } else {
            CreateKicauan(k, id, text, idauthor, waktu);

            printf("\nSelamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
            DisplaySatuKicau(U, *k);
            insertLastKicauan(l, *k);
        }
    }
}

void DisplayKicauan(ListStatikUser l, ListKicauan k, int idUser, FriendMatrix m){
    if (idUser==-1)
    {
        printf("\nAnda belum masuk. Masuk dulu yuk!\n\n");
    } else {
        printf("\n");
        int idAuthor;
        for (int i = NEFFLISTKICAU(k) - 1 ; i >= 0; i--) {
            idAuthor = IDAUTHOR(ELMTLISTKICAU(k, i));
            if (idAuthor == idUser) {
                DisplaySatuKicau(l, ELMTLISTKICAU(k, i));
            } else {
                if(isFriend(m, idAuthor-1, idUser-1)){
                    DisplaySatuKicau(l, ELMTLISTKICAU(k, i));
                }
            } 
        }
    }
}

void SUKA_KICAUAN(ListStatikUser l, ListKicauan *k, int idKicauan, int idUser, FriendMatrix m){
    if (idUser==-1)
    {
        printf("\nAnda belum masuk. Masuk dulu yuk!\n\n");
    } else {
        if (!isIdKicauanValid(*k, idKicauan)) {
            printf("\nTidak ditemukan kicauan dengan ID = %d\n", idKicauan);
        } else {
            int idAuthor = IDAUTHOR(ELMTLISTKICAU(*k, idKicauan-1));
            if(UserTipe(l, idAuthor-1) == PUBLIK){
                LIKE(ELMTLISTKICAU(*k, idKicauan-1))++;
                printf("\n");
                DisplaySatuKicau(l, ELMTLISTKICAU(*k,idKicauan-1));
            }  else {
                if (idAuthor == idUser) {
                    LIKE(ELMTLISTKICAU(*k, idKicauan-1))++;
                    printf("\n");
                    DisplaySatuKicau(l, ELMTLISTKICAU(*k,idKicauan-1));
                } else {
                    if(isFriend(m, idAuthor, idUser)){
                        LIKE(ELMTLISTKICAU(*k, idKicauan-1))++;
                        printf("\n");
                        DisplaySatuKicau(l, ELMTLISTKICAU(*k,idKicauan-1));
                    } else {
                        printf("\nWah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
                    }
                }
            }
            
        }
    }
}

void UBAH_KICAUAN(ListStatikUser l, ListKicauan *k, int idKicauan, int idUser){
    if (idUser==-1)
    {
        printf("\nAnda belum masuk. Masuk dulu yuk!\n\n");
    } else {
        Word newText;
        if (isIdKicauanValid(*k, idKicauan)) {
            int idAuthor = IDAUTHOR(ELMTLISTKICAU(*k, idKicauan-1));
            if (idAuthor == idUser) {
                printf("\nMasukkan kicauan baru : \n");
                STARTSENTENCE();
                newText = currentWord;
                TEXT(ELMTLISTKICAU(*k,idKicauan-1)) = newText;
                printf("\n");
                DisplaySatuKicau(l, ELMTLISTKICAU(*k, idKicauan-1));
            } else {
                printf("\nKicauan dengan ID = %d bukan milikmu!\n", idKicauan);
            }
        } else {
            printf("\nTidak ditemukan kicauan dengan ID = %d!\n", idKicauan);
        }
    }
}
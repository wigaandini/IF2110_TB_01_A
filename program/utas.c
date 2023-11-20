#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../adt/header/boolean.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/listlinierutas.h"
#include "../adt/header/listdinkicauan.h"
#include "../adt/header/liststatikuser.h"
#include "../adt/header/charmachine.h"
#include "../adt/header/datetime.h"
#include "../adt/header/friendmatrix.h"

int searchIdKicau(int idUtas, ListKicauan l){
    int count = 0;
    while(UTAS(ELMTLISTKICAU(l, count)) != NULL && idUtas != count){
        count++;
    }
    return ID(ELMTLISTKICAU(l, count));
}

void DisplaySatuUtas(UtasType u, ListStatikUser l){
    printf("    | INDEX = %d\n", idxUtas(u));
    printf("    | ");
    displayString(l.data[idAuthor(u)-1].nama);
    printf("\n    | ");
    TulisDATETIME(Waktu(u));
    printf("\n");
    printf("    | ");
    displayWord(Text(u));
    printf("\n\n");
}

void DisplayUtasPers(ListStatikUser l, ListLinierUtas u, int idUser, int idUtas, ListKicauan listKicau){
    int idAuthor;
    AddressUtas p = FIRST(u);
    int idKicau = searchIdKicau(idUtas, listKicau);
    idAuthor = IDAUTHOR(ELMTLISTKICAU(listKicau, idKicau-1));
    DisplaySatuKicau(l, ELMTLISTKICAU(listKicau, idKicau-1));
    int countUtas = countTypeUtas(listKicau);
    for (int i = countUtas - 1; i >= 0; i--) {
        if (idAuthor == idUser) {
            DisplaySatuUtas(INFOUtas(p), l);
            p = NEXTUtas(p);
        } else {
            if(UserTipe(l, idAuthor-1) == PUBLIK){
                DisplaySatuUtas(INFOUtas(p), l);
                p = NEXTUtas(p);
            }
        } 
    }
}

void BIKIN_UTAS(int idKicau, ListKicauan *listKicau, ListLinierUtas *listUtasPers, int idAuthor, UtasType *u){
    int indexUtas;
    Word text;
    DATETIME waktu;
    if(isIdKicauanValid(*listKicau, ID(ELMTLISTKICAU(*listKicau, idKicau-1)))){
        if(IDAUTHOR(ELMTLISTKICAU(*listKicau, idKicau-1)) == idAuthor){
            printf("Utas berhasil dibuat!\n\n");
            printf("Masukkan kicauan:\n");
            STARTSENTENCE();
            printf("\n");

            text = currentWord;
            indexUtas = length(*listUtasPers) + 1;

            time_t current_time;
            time(&current_time);
            current_time += 3600*7;

            struct tm* timeinfo = gmtime(&current_time);

            Year(waktu) = 1900 + timeinfo->tm_year;
            Month(waktu) = timeinfo->tm_mon + 1;
            Day(waktu) = timeinfo->tm_mday;
            Time(waktu) = DetikToTIME(current_time);

            CreateUtas(u, idAuthor, indexUtas, text, waktu);
            insertLastPers(listUtasPers, *u);
            UTAS(ELMTLISTKICAU(*listKicau, idKicau-1)) = newNode(*u);

            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
            STARTSENTENCE();
            while(compareString(currentWord, "YA")){
                printf("\nMasukkan kicauan:\n");
                STARTSENTENCE();
                printf("\n");
                text = currentWord;

                CreateUtas(u, idAuthor, indexUtas, text, waktu);
                insertLastPers(listUtasPers, *u);

                printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
                STARTSENTENCE();
                if(compareString(currentWord, "TIDAK")){
                    printf("Utas selesai!\n\n");
                }
            }
        }
        else{
            printf("Utas ini bukan milik anda!\n");
        }
    }
    else{
        printf("Kicauan tidak ditemukan!\n");
    }
}

boolean isIdUtasValid(ListKicauan listKicau, int idUtas){
    return (idUtas > 0 && idUtas <= countTypeUtas(listKicau));
}

void SAMBUNG_UTAS(int idUtas, int indexUtas, ListLinierUtas *listUtasPers, int idAuthor, UtasType *u, ListKicauan listKicau){
    Word text;
    DATETIME waktu;
    int idKicau = searchIdKicau(idUtas, listKicau);
    if(isIdUtasValid(listKicau, idUtas)){
        if(IDAUTHOR(ELMTLISTKICAU(listKicau, idKicau-1)) == idAuthor){
            if(indexUtas == getLastIdxUtasPers(*listUtasPers)){
                printf("Masukkan kicauan:\n");
                STARTSENTENCE();
                printf("\n");
                text = currentWord;
                indexUtas = getLastIdxUtasPers(*listUtasPers) + 1;
                time_t current_time;
                time(&current_time);
                current_time += 3600*7;

                struct tm* timeinfo = gmtime(&current_time);

                Year(waktu) = 1900 + timeinfo->tm_year;
                Month(waktu) = timeinfo->tm_mon + 1;
                Day(waktu) = timeinfo->tm_mday;
                Time(waktu) = DetikToTIME(current_time);

                CreateUtas(u, idAuthor, indexUtas, text, waktu);
                insertLastPers(listUtasPers, *u);
            }
            else if(indexUtas > getLastIdxUtasPers(*listUtasPers)){
                printf("Index terlalu tinggi!\n");
            }
            else{
                printf("Index terlalu rendah!\n");
            }
        }
        else{
            printf("Anda tidak bisa menyambung utas ini!\n");
        }
    }
    else{
        printf("Utas tidak ditemukan!\n");
    }   
}


void HAPUS_UTAS(int idUtas, int indexUtas, ListLinierUtas *listUtasPers, int idAuthor, UtasType *u, ListKicauan listKicau){
    Word text;
    DATETIME waktu;
    int idKicau = searchIdKicau(idUtas, listKicau);
    Address p = FIRST(*listUtasPers);
    if(isIdUtasValid(listKicau, idUtas)){
        if(IDAUTHOR(ELMTLISTKICAU(listKicau, idKicau-1)) == idAuthor){
            if(indexUtas == 0){
                printf("Anda tidak bisa menghapus kicauan utama!\n");
            }
            else if (isIdxUtasPersValid(*listUtasPers, indexUtas)){
                printf("Kicauan sambungan berhasil dihapus!\n");
                deleteAtPers(listUtasPers, indexUtas, u);
            }
            else{
                printf("Kicauan sambungan dengan index 3 tidak ditemukan pada utas!\n");
            }
        }
        else{
            printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
        }
    }
    else{
        printf("Utas tidak ditemukan!\n");
    }   
}

void CETAK_UTAS(ListStatikUser l, ListLinierUtas listUtasPers, int idUser, int idUtas, ListKicauan listKicau){
    int idKicau = searchIdKicau(idUtas, listKicau);
    if(isIdUtasValid(listKicau, idUtas)){
        if(UserTipe(l, idUser - 1) == PUBLIK){
            printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
        }
        else{
            DisplayUtasPers(l, listUtasPers, idUser, idUtas, listKicau);
        }
    }
    else{
        printf("Utas tidak ditemukan!\n");
    }
}
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
    int i = 0, count = 0;
    boolean found = false;
    while(!found){
        count++;
        if(ADDRESSUTAS(ELMTLISTKICAU(l, i)) != NULL && count == idUtas){
            found = true;
        }
        else if(ADDRESSUTAS(ELMTLISTKICAU(l, i)) != NULL && count != idUtas){
            found = false;
            i++;
        }
        else{
            found = false;
        }
    }
    if(found){
        return ID(ELMTLISTKICAU(l, i));
    }
}

void DisplaySatuUtas(UtasType u, ListStatikUser l, int index){
    printf("    | INDEX = %d\n", index);
    printf("    | ");
    displayString(l.data[idAuthor(u)-1].nama);
    printf("\n    | ");
    TulisDATETIME(Waktu(u));
    printf("\n");
    printf("    | ");
    displayWord(Text(u));
    printf("\n\n");
}

boolean isIdUtasValid(ListKicauan listKicau, int idUtas){
    return (idUtas > 0 && idUtas <= countTypeUtas(listKicau));
}

void DisplayUtasPers(ListStatikUser l, ListLinierUtas u, int idUser, int idUtas, ListKicauan listKicau){
    int idKicau = searchIdKicau(idUtas, listKicau);
    int idAuthor = IDAUTHOR(ELMTLISTKICAU(listKicau, idKicau-1));
    AddressUtas p = FIRSTUtas(u);
    for (int i = 0; i < length(u); i++) {
        if (idAuthor == idUser) {
            DisplaySatuUtas(INFOUtas(p), l, idxUtas(INFOUtas(p)));
            p = NEXTUtas(p);
        } 
        else {
            if(UserTipe(l, idAuthor-1) == PUBLIK){
                DisplaySatuUtas(INFOUtas(p), l, idxUtas(INFOUtas(p)));
                p = NEXTUtas(p);
            }
        } 
    }
}

void BIKIN_UTAS(int idKicau, ListKicauan *listKicau, ListLinierUtas *listUtasPers, int idAuthor, UtasType *u){
    int indexUtas;
    Word text;
    DATETIME waktu;
    CreateListUtasPers(listUtasPers);
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
            ADDRESSUTAS(ELMTLISTKICAU(*listKicau, idKicau-1)) = newNodeUtas(*u);

            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
            STARTSENTENCE();
            while(compareString(currentWord, "YA")){
                printf("\nMasukkan kicauan:\n");
                STARTSENTENCE();
                printf("\n");
                text = currentWord;
                indexUtas ++;

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

void SAMBUNG_UTAS(int idUtas, int indexUtas, ListLinierUtas *listUtasPers, int idAuthor, UtasType *u, ListKicauan listKicau){
    Word text;
    DATETIME waktu;
    int idKicau = searchIdKicau(idUtas, listKicau);
    if(isIdUtasValid(listKicau, idUtas)){
        if(IDAUTHOR(ELMTLISTKICAU(listKicau, idKicau-1)) == idAuthor){
            if(indexUtas == getLastIdxUtasPers(*listUtasPers) + 1){
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
            else if(indexUtas > getLastIdxUtasPers(*listUtasPers) + 1){
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
    AddressUtas p = FIRSTUtas(*listUtasPers);
    if(isIdUtasValid(listKicau, idUtas)){
        if(IDAUTHOR(ELMTLISTKICAU(listKicau, idKicau-1)) == idAuthor){
            if(indexUtas == 0){
                printf("Anda tidak bisa menghapus kicauan utama!\n");
            }
            else if (isIdxUtasPersValid(*listUtasPers, indexUtas)){
                deleteAtPers(listUtasPers, indexUtas-1, u);
                printf("Kicauan sambungan berhasil dihapus!\n\n");
            }
            else{
                printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!\n\n", indexUtas);
            }
        }
        else{
            printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n\n");
        }
    }
    else{
        printf("Utas tidak ditemukan!\n\n");
    }   
}

void CETAK_UTAS(ListStatikUser l, ListLinierUtas listUtasPers, int idUser, int idUtas, ListKicauan listKicau){
    int idKicau = searchIdKicau(idUtas, listKicau), i;
    AddressUtas p;
    if(isIdUtasValid(listKicau, idUtas)){
        if(IDAUTHOR(ELMTLISTKICAU(listKicau, idKicau-1)) == idUser){
            DisplaySatuKicau(l, ELMTLISTKICAU(listKicau, idKicau-1));
            p = FIRSTUtas(listUtasPers);
            for (i = 0; i < length(listUtasPers); i++) {
                DisplaySatuUtas(INFOUtas(p), l, idxUtas(INFOUtas(p)));
                p = NEXTUtas(p);
            }
        }
        else{
            if(UserTipe(l, idUser - 1) == PRIVAT){
                printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n\n");
            }
            else{
                DisplaySatuKicau(l, ELMTLISTKICAU(listKicau, idKicau-1));
                p = FIRSTUtas(listUtasPers);
                for (i = 0; i < length(listUtasPers); i++) {
                    DisplaySatuUtas(INFOUtas(p), l, idxUtas(INFOUtas(p)));
                    p = NEXTUtas(p);
                }
            }
        }
    }
    else{
        printf("Utas tidak ditemukan!\n\n");
    }
}
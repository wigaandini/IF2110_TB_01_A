#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../adt/header/boolean.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/listlinierutas.h"
#include "../adt/header/listdinkicauan.h"


void UTAS(int idKicau, ListKicauan *listKicau, ListLinierUtas *listUtasPers, ListUtas *listUtasGlobal, int idAuthor, UtasType *u){
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
            indexUtas = length(*listUtas) + 1;

            time_t current_time;
            time(&current_time);
            current_time += 3600*7;

            struct tm* timeinfo = gmtime(&current_time);

            Year(waktu) = 1900 + timeinfo->tm_year;
            Month(waktu) = timeinfo->tm_mon + 1;
            Day(waktu) = timeinfo->tm_mday;
            Time(waktu) = DetikToTIME(current_time);

            CreateUtas(u, idKicau, idAuthor, indexUtas, text, waktu);
            insertLastGlobal(listUtasGlobal, ELMTLISTKICAU(*listKicau, idKicau-1));
            insertLastPers(listUtasPers, u);

            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
            STARTSENTENCE();
            while(compareString(currentWord, "YA")){
                printf("\nMasukkan kicauan:\n");
                STARTSENTENCE();
                printf("\n");

                CreateUtas(u, idKicau, idAuthor, indexUtas, text, waktu);
                insertLastPers(listUtasPers, u);

                printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
                STARTSENTENCE();
                if(compareString(currentWord, "TIDAK")){
                    printf("Utas selesai!\n\n");
                }
            }
            UTAS(ELMTLISTKICAU(*listKicau, idKicau-1)) = u;
        }
        else{
            printf("Utas ini bukan milik anda!\n");
        }
    }
    else{
        printf("Kicauan tidak ditemukan!\n");
    }
}


void SAMBUNG_UTAS(int idUtas, int indexUtas, ListLinierUtas *listUtasPers, ListUtas *listUtasGlobal, int idAuthor, UtasType *u){
    Word text;
    DATETIME waktu;
    int indexUtas;
    if(isIdUtasGlobalValid(idUtas)){
        if(IDAUTHOR(ELMTLISTKICAU(*listKicau, idKicau-1)) == idAuthor){
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

                CreateUtas(u, idKicau, idAuthor, indexUtas, text, waktu);
                insertLastPers(listUtasPers, u);
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


void HAPUS_UTAS(int idUtas, int indexUtas, ListLinierUtas *listUtasPers, ListUtas *listUtasGlobal, int idAuthor, UtasType *u){
    Word text;
    DATETIME waktu;
    int indexUtas;
    Address p = FIRST(*listUtasPers);
    if(isIdUtasGlobalValid(idUtas)){
        if(IDAUTHOR(ELMTLISTKICAU(*listKicau, idKicau-1)) == idAuthor){
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


void CETAK_UTAS(ListStatikUser l, ListUtas k, ListLinierUtas u, int idUser, int idUtas){
    if(isIdUtasGlobalValid(idUtas)){
        if(UserTipe(l, idAuthor-1) == PUBLIK){
            printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
        }
        else{
            DisplayUtasPers(l, k, u, idUser, idUtas);
        }
    }
    else{
        printf("Utas tidak ditemukan!\n");
    }
}



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

// int main(){
//     Word w;
//     Word utasWord = splitCommand(&w, word, 1);
//     // displayWord(utas);
//     Word idWord = splitCommand(&w, word, 2);
//     int idInt = WordToInt(idWord);
//     char* idStr = WordToString(idWord);
//     char* utasStr = MergeString("UTAS", idStr);
//     // printf("%s", utasStr);
//     // if (compareString(word, utasStr)){
//         printf("\nUtas berhasil dibuat!\n\n");
//         printf("Masukkan kicauan:\n");
//         STARTSENTENCE();
//         printf("\n");
//         printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
//         STARTSENTENCE();
//         while(compareString(currentWord, "YA")){
//             printf("\nMasukkan kicauan:\n");
//             STARTSENTENCE();
//             printf("\n");
//             printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
//             STARTSENTENCE();
//             if(compareString(currentWord, "TIDAK")){
//                 printf("Utas selesai!\n\n");
//             }
//         }
//     // }
//     // printf("\n");
//     // displayWord(id);





//     Word w;
//     Word sambungWord = splitCommand(&w, word, 1);
//     // displayWord(utas);
//     Word idUtas = splitCommand(&w, word, 2);
//     Word idSambung = splitCommand(&w, word, 3);
//     int idUtasInt = WordToInt(idUtas);
//     int idSambungInt = WordToInt(idSambung);
//     char* idUtasStr = WordToString(idUtas);
//     char* idSambungStr = WordToString(idSambung);
//     char* utasStr = MergeString("SAMBUNG_UTAS", idUtasStr);
//     char* sambungStr = MergeString(utasStr, idSambungStr);
//     printf("\nMasukkan kicauan:\n");
//     STARTSENTENCE();
//     printf("\n");






//     Word w, kata, cWord;
//     printf(">> ");
//     STARTSENTENCE();
//     // UTAS(currentWord);
//     cWord = currentWord;
//     kata = splitCommand(&w, cWord, 1);
//     displayWord(kata);
//     if(compareString(kata,"UTAS")){
//         UTAS(currentWord);
//     }
//     else if(compareString(kata,"SAMBUNG_UTAS")){
//         SAMBUNG_UTAS(currentWord);
//     }
// }
//     Word idW;
//     int i = 0;
//     while(currentChar != MARK && currentChar != BLANK && currentChar != LineMARK && i < 4){
//         currentWord.TabWord[i] = currentChar;
//         ADV();
//         i ++;
//     }

//     int j = 0;
//     while(currentChar != MARK && currentChar != BLANK && currentChar != LineMARK){
//         idW.TabWord[j] = currentChar;
//         ADV();
//         j ++;
//         idW.Length = j;
//     }

//     int id = WordToInt(idW);
//     printf("%d\n", id);
//     char* idStr = WordToString(idW);
//     // char* utasStr = "UTAS " + idStr;
//     // if (compareString(currentWord, utasStr)){
//     //     printf("Utas berhasil dibuat!\n\n");
//     //     printf("Masukkan kicauan:\n");
//     //     STARTSENTENCE();
//     //     printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
//     //     STARTSENTENCE();
//     //     while(compareString(currentWord, "YA")){
//     //         printf("Masukkan kicauan:\n");
//     //         STARTSENTENCE();
//     //     }
//     //     if(compareString(currentWord, "TIDAK")){
//     //         printf("Utas selesai!\n\n");
//     //     }
//     // }
// }
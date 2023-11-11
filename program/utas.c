#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../adt/header/boolean.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/listlinierutas.h"
#include "../adt/header/listdinkicauan.h"


void UTAS(int idKicau, ListKicauan *listKicau, ListLinierUtas *listUtas, int idAuthor, UtasType *u){
    int indexUtas;
    Word text;
    DATETIME waktu;
    if(IDAUTHOR(ELMTLISTKICAU(*listKicau, idKicau-1)) == idAuthor);
        printf("Utas berhasil dibuat!\n\n");
        printf("Masukkan kicauan:\n");
        STARTSENTENCE();
        printf("\n");

        text = currentWord;
        indexUtas = length(*listUtas) + 1;

        time_t current_time;
        time(&current_time);
        current_time+=3600*7;

        struct tm* timeinfo = gmtime(&current_time);

        Year(waktu) = 1900 + timeinfo->tm_year;
        Month(waktu) = timeinfo->tm_mon + 1;
        Day(waktu) = timeinfo->tm_mday;
        Time(waktu) = DetikToTIME(current_time);

        CreateUtas(u, idKicau, idAuthor, indexUtas, text, waktu);
        insertLast(listUtas, u);
        printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
        STARTSENTENCE();
        while(compareString(currentWord, "YA")){
            printf("\nMasukkan kicauan:\n");
            STARTSENTENCE();
            printf("\n");
            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
            STARTSENTENCE();
            if(compareString(currentWord, "TIDAK")){
                printf("Utas selesai!\n\n");
            }
        }
        UTAS(ELMTLISTKICAU(*listKicau, idKicau-1)) = u;
    }
    else{
        printf("Anda tidak dapat membuat utas pada kicauan orang lain!\n");
    }
    Word w;
    Word utasWord = splitCommand(&w, word, 1);
    // displayWord(utas);
    Word idWord = splitCommand(&w, word, 2);
    int idInt = WordToInt(idWord);
    char* idStr = WordToString(idWord);
    char* utasStr = MergeString("UTAS", idStr);
    // printf("%s", utasStr);
    // if (compareString(word, utasStr)){
        printf("\nUtas berhasil dibuat!\n\n");
        printf("Masukkan kicauan:\n");
        STARTSENTENCE();
        printf("\n");
        printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
        STARTSENTENCE();
        while(compareString(currentWord, "YA")){
            printf("\nMasukkan kicauan:\n");
            STARTSENTENCE();
            printf("\n");
            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
            STARTSENTENCE();
            if(compareString(currentWord, "TIDAK")){
                printf("Utas selesai!\n\n");
            }
        }
    // }
    // printf("\n");
    // displayWord(id);
}

void SAMBUNG_UTAS(Word word){
    Word w;
    Word sambungWord = splitCommand(&w, word, 1);
    // displayWord(utas);
    Word idUtas = splitCommand(&w, word, 2);
    Word idSambung = splitCommand(&w, word, 3);
    int idUtasInt = WordToInt(idUtas);
    int idSambungInt = WordToInt(idSambung);
    char* idUtasStr = WordToString(idUtas);
    char* idSambungStr = WordToString(idSambung);
    char* utasStr = MergeString("SAMBUNG_UTAS", idUtasStr);
    char* sambungStr = MergeString(utasStr, idSambungStr);
    printf("\nMasukkan kicauan:\n");
    STARTSENTENCE();
    printf("\n");
}


int main(){
    Word w, kata, cWord;
    printf(">> ");
    STARTSENTENCE();
    // UTAS(currentWord);
    cWord = currentWord;
    kata = splitCommand(&w, cWord, 1);
    displayWord(kata);
    if(compareString(kata,"UTAS")){
        UTAS(currentWord);
    }
    else if(compareString(kata,"SAMBUNG_UTAS")){
        SAMBUNG_UTAS(currentWord);
    }
}
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
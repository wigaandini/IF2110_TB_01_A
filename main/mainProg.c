#include "mainProg.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Enter Command\n");
    STARTSENTENCE();
    Word idW;
    int i = 0;
    while(currentChar != MARK && currentChar != BLANK && currentChar != LineMARK && i < 4){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i ++;
    }

    int j = 0;
    while(currentChar != MARK && currentChar != BLANK && currentChar != LineMARK){
        idW.TabWord[j] = currentChar;
        ADV();
        j ++;
        idW.Length = j;
    }

    int id = WordToInt(idW);
    char* idStr = WordToString(idW);
    if (compareString(currentWord, "UTAS " + idStr)){
        printf("Utas berhasil dibuat!\n\n");
        printf("Masukkan kicauan:\n");
        STARTSENTENCE();
        printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
        STARTSENTENCE();
        while(compareString(currentWord, "YA")){
            printf("Masukkan kicauan:\n");
            STARTSENTENCE();
        }
        if(compareString(currentWord, "TIDAK")){
            printf("Utas selesai!\n\n");
        }
    }
}
#include <stdio.h>
#include "../adt/header/configmachine.h"
#include "../adt/header/charmachine.h"
#include <stdlib.h>
#include "../adt/header/listdinkicauan.h"
#include "../adt/header/treebalasan.h"
#include "balasan.c"

void readOneNum(int *num, Word bacaan){
    int iteru;
    int n = 0;
    for(iteru = 0; iteru < bacaan.Length; ++iteru){
        n = n * 10 + bacaan.TabWord[iteru] - '0';
    }
    *num = n;
}

void readTwoNum(int *num1, int *num2, Word bacaan){
    int iter = 0;
    int n1 = 0;
    int sign = 1;
    for(iter = 0; iter < bacaan.Length && bacaan.TabWord[iter] != ' '; ++iter){
        if(bacaan.TabWord[iter] == '-'){
            sign *= -1;
        }else{
            n1 = n1 * 10 + bacaan.TabWord[iter] - '0';
        }
    }
    n1 *= sign;
    iter++;
    int n2 = 0;
    for(; iter < bacaan.Length; ++iter){
        n2 = n2 * 10 + bacaan.TabWord[iter] - '0';
    }
    *num1 = n1;
    *num2 = n2;
}

void readDateTime(DATETIME *res, Word bacaan){
    int day = 0;
    int month = 0;
    int year = 0;
    int hour = 0;
    int minutes = 0;
    int seconds = 0;
    int iter = 0;
    for(; iter < bacaan.Length && bacaan.TabWord[iter] != '/'; ++iter){
        day = day * 10 + bacaan.TabWord[iter] - '0';
    }
    iter++;
    for(; iter < bacaan.Length && bacaan.TabWord[iter] != '/'; ++iter){
        month = month * 10 + bacaan.TabWord[iter] - '0';
    }
    iter++;
    for(; iter < bacaan.Length && bacaan.TabWord[iter] != ' '; ++iter){
        year = year * 10 + bacaan.TabWord[iter] - '0';
    }
    iter++;
    for(; iter < bacaan.Length && bacaan.TabWord[iter] != ':'; ++iter){
        hour = hour * 10 + bacaan.TabWord[iter] - '0';
    }
    iter++;
    for(; iter < bacaan.Length && bacaan.TabWord[iter] != ':'; ++iter){
        minutes = minutes * 10 + bacaan.TabWord[iter] - '0';
    }
    iter++;
    for(; iter < bacaan.Length; ++iter){
        seconds = seconds * 10 + bacaan.TabWord[iter] - '0';
    }
    res->DD = day;
    res->MM = month;
    res->YYYY = year;
    res->T.HH = hour;
    res->T.MM = minutes;
    res->T.SS = seconds;
}

void copyWord(Word *w1, Word w2){
    int i;
    w1->Length = w2.Length;
    for(i = 0; i < w2.Length; ++i){
        w1->TabWord[i] = w2.TabWord[i];
    }
    w1->TabWord[w2.Length + 1] = '\0';
}

void readbalasan(ListStatikUser *lsu, ListKicauan *lk,char *path){
    char realpath[200];
    concatenate(realpath, path, "/balasan.config");
    STARTconfig(realpath);
    Word bacaanStart;
    bacaanStart.Length = 0;
    int iterStart = 0;
    while (currentChar != '\n') {
        bacaanStart.TabWord[iterStart] = currentChar;
        iterStart++;
        ADVconfig();
        bacaanStart.Length++;
    }
    bacaanStart.TabWord[iterStart] = '\0';
    ADVconfig();
    int n;
    readOneNum(&n, bacaanStart);
    int i;
    for(i = 0; i < n; ++i){
        Word bacaanID;
        int iterID = 0;
        bacaanID.Length = 0;
        while (currentChar != '\n') {
            bacaanID.TabWord[iterID] = currentChar;
            iterID++;
            ADVconfig();
            bacaanID.Length++;
        }
        bacaanID.TabWord[iterID] = '\0';
        ADVconfig();

        int idKicau;
        readOneNum(&idKicau, bacaanID);
        int j;
        Word numOfBalasan;
        int iterNum = 0;
        numOfBalasan.Length = 0;
        while (currentChar != '\n') {
            numOfBalasan.TabWord[iterNum] = currentChar;
            iterNum++;
            ADVconfig();
            numOfBalasan.Length++;
        }
        numOfBalasan.TabWord[iterNum] = '\0';
        ADVconfig();

        int num;
        readOneNum(&num, numOfBalasan);
        for(j = 0; j < num; ++j){
            Word bacaan;
            int k = 0;
            bacaan.Length = 0;
            while (currentChar != '\n') {
                bacaan.TabWord[k] = currentChar;
                k++;
                ADVconfig();
                bacaan.Length++;
            }
            bacaan.TabWord[k] = '\0';
            ADVconfig();

            int idPar, idCur;
            readTwoNum(&idPar, &idCur, bacaan);
            k = 0;
            bacaan.Length = 0;
            while (currentChar != '\n') {
                bacaan.TabWord[k] = currentChar;
                k++;
                ADVconfig();
                bacaan.Length++;
            }
            bacaan.TabWord[k] = '\0';
            ADVconfig();

            Word textInput;
            copyWord(&textInput, bacaan);
            k = 0;
            bacaan.Length = 0;
            while (currentChar != '\n') {
                bacaan.TabWord[k] = currentChar;
                k++;
                ADVconfig();
                bacaan.Length++;
            }
            bacaan.TabWord[k] = '\0';
            ADVconfig();

            Word namaWriter;
            copyWord(&namaWriter, bacaan);
            k = 0;
            bacaan.Length = 0;
            while (currentChar != '\n') {
                bacaan.TabWord[k] = currentChar;
                k++;
                ADVconfig();
                bacaan.Length++;
            }
            bacaan.TabWord[k] = '\0';
            ADVconfig();

            DATETIME d;
            readDateTime(&d, bacaan);
            int userId = getIdOfName(*lsu, bacaan);
            idCur--;
            langsungAddBalasan(lk, textInput, d, idKicau, idPar, userId, &idCur);
        }
    }
}
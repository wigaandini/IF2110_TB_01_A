#include <stdio.h>
#include "header/draf.h"

void LihatDraf(Stack S){
    if (IsEmpty(S))
    {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    }
    else
    {
        Draf temp = InfoTop(S);
        printf("Ini draf terakhir anda:\n");
        printf("| ");
        TulisDATETIME(temp.Waktu);
        printf("\n");
        int j;
        printf("| ");
        for (j = 0; j < temp.Text.Length; j++) {
            printf("%c", temp.Text.TabWord[j]);
        }
        printf("\n");   
    }

}

void AddDraf(Stack * S,Word word){
    time_t current_time;
    time(&current_time);
    current_time+=3600*7;
    DATETIME D;

    struct tm* timeinfo = gmtime(&current_time);

    Year(D) = 1900 + timeinfo->tm_year;
    Month(D) = timeinfo->tm_mon + 1;
    Day(D) = timeinfo->tm_mday;
    Time(D)=DetikToTIME(current_time);

    Draf Draf;
    Draf.Waktu=D;
    Draf.Text=word;

    Push(S,Draf);
}

void EditDraf(Stack * S,Word word){
    Draf temp;
    Pop(S, &temp);

    time_t current_time;
    time(&current_time);
    current_time+=3600*7;
    DATETIME D;

    struct tm* timeinfo = gmtime(&current_time);

    Year(D) = 1900 + timeinfo->tm_year;
    Month(D) = timeinfo->tm_mon + 1;
    Day(D) = timeinfo->tm_mday;
    Time(D)=DetikToTIME(current_time);

    Draf Draf;
    Draf.Waktu=D;
    Draf.Text=word;

    Push(S,Draf);
}

void DeleteDraf(Stack *S,Draf *Out){
    Pop(S,Out);
}

void PostDraf(){

}

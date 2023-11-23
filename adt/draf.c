#include <stdio.h>
#include "header/draf.h"

void LihatDraf(DrafStack S){
    infotypeDraf X;
    // while (!IsEmptyStack(S))
    // {
    if(!IsEmptyStack(S)){
        Pop(&S,&X);
        int i;
        printf("\nIni draf terakhir anda:\n");
        printf("| ");
        for ( i = 0; i < X.Text.Length; i++)
        {
            printf("%c",X.Text.TabWord[i]);
        }
        printf("\n");
        printf("| ");
        TulisDATETIME(X.Waktu);
        printf("\n");
    }
    else{
        printf("\nYah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    }

}

void AddDraf(DrafStack * S,Word word){
    time_t current_time;
    time(&current_time);
    current_time+=3600*10+7*60;
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

void EditDraf(DrafStack * S,Word word){
    Draf temp;
    Pop(S, &temp);

    time_t current_time;
    time(&current_time);
    current_time+=3600*10+7*60;
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

void DeleteDraf(DrafStack *S,Draf *Out){
    Pop(S,Out);
}
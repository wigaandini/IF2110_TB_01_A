#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../adt/header/boolean.h"
#include "../adt/header/charmachine.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/time.h"
#include "../adt/header/datetime.h"
#include "../adt/header/liststatikuser.h"
#include "../adt/header/listdinkicauan.h"
#include "../adt/header/draf.h"
#include "../adt/header/stack.h"
void BUAT_DRAF(ListStatikUser *l,ListKicauan *k,int iduser){
    if (iduser==-1)
    {
        printf("\nAnda belum masuk. Masuk dulu yuk!\n\n");
    }
    else{
        Word text,action;
        printf("\nMasukkan draf : \n");
        STARTSENTENCE();
        text = currentWord;
        printf("\nApakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
        STARTSENTENCE();
        action = currentWord;
        if(compareString(action,"SIMPAN")){
            AddDraf(&(l->data[iduser-1].drafuser), text);
            printf("\nDraf telah berhasil disimpan!\n");
        } else if (compareString(action,"TERBIT")) {
            DATETIME waktu;
            time_t current_time;
            Kicauan tweet;
            time(&current_time);
            current_time+=3600*10+7*60;
            struct tm* timeinfo = gmtime(&current_time);
            Year(waktu) = 1900 + timeinfo->tm_year;
            Month(waktu) = timeinfo->tm_mon + 1;
            Day(waktu) = timeinfo->tm_mday;
            Time(waktu) = DetikToTIME(current_time);
            CreateKicauan(&tweet, NEFFLISTKICAU(*k)+1, text, iduser, waktu);
            printf("\nSelamat! Draf kicauan telah diterbitkan!\n");
            DisplaySatuKicau(*l, tweet);
            insertLastKicauan(k, tweet);
        } else if (compareString(action,"HAPUS")) {
            printf("\nDraf telah berhasil dihapus!\n");
        }
    }
}
void LIHAT_DRAF(ListStatikUser *l, ListKicauan *k,int iduser){
    if (iduser==-1)
    {
        printf("\nAnda belum masuk. Masuk dulu yuk!\n\n");
    }
    else{
        LihatDraf(l->data[iduser-1].drafuser);
        if (!IsEmptyStack(l->data[iduser-1].drafuser)){
            Word text,action,action2;
            printf("\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
            STARTSENTENCE();
            action = currentWord;
            if(compareString(action,"UBAH")){
                printf("\nMasukkan draf yang baru: \n");
                STARTSENTENCE();
                text = currentWord;
                // EditDraf(&(l->data[iduser-1].drafuser), text);
                printf("\nApakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
                STARTSENTENCE();
                action2 = currentWord;
                if(compareString(action2,"SIMPAN")){
                    EditDraf(&(l->data[iduser-1].drafuser), text);
                    printf("\nDraf telah berhasil disimpan!\n");
                } else if (compareString(action2,"TERBIT")){
                    DATETIME waktu;
                    Kicauan tweet;
                    time_t current_time;
                    time(&current_time);
                    current_time+=3600*10+7*60;
                    struct tm* timeinfo = gmtime(&current_time);
                    Year(waktu) = 1900 + timeinfo->tm_year;
                    Month(waktu) = timeinfo->tm_mon + 1;
                    Day(waktu) = timeinfo->tm_mday;
                    Time(waktu) = DetikToTIME(current_time);
                    
                    CreateKicauan(&tweet, NEFFLISTKICAU(*k)+1, text, iduser, waktu);
                    printf("\nSelamat! Draf kicauan telah diterbitkan!\n");
                    DisplaySatuKicau(*l, tweet);
                    insertLastKicauan(k, tweet);
                    Draf poppedDraf;
                    DeleteDraf(&(l->data[iduser-1].drafuser), &poppedDraf);
                } else if (compareString(action2,"HAPUS")) {
                    Draf poppedDraf;
                    DeleteDraf(&(l->data[iduser-1].drafuser), &poppedDraf);
                    printf("\nDraf telah berhasil dihapus!\n");
                }
            } else if (compareString(action,"TERBIT")) {
                DATETIME waktu;
                Kicauan tweet;
                time_t current_time;
                time(&current_time);
                current_time+=3600*10+7*60;
                struct tm* timeinfo = gmtime(&current_time);
                Year(waktu) = 1900 + timeinfo->tm_year;
                Month(waktu) = timeinfo->tm_mon + 1;
                Day(waktu) = timeinfo->tm_mday;
                Time(waktu) = DetikToTIME(current_time);
                CreateKicauan(&tweet, NEFFLISTKICAU(*k)+1, DrafText(InfoTop(l->data[iduser-1].drafuser)), iduser, waktu);
                printf("\nSelamat! Draf kicauan telah diterbitkan!\n");
                DisplaySatuKicau(*l, tweet);
                insertLastKicauan(k, tweet);
                Draf poppedDraf;
                DeleteDraf(&(l->data[iduser-1].drafuser), &poppedDraf);
            } else if (compareString(action,"HAPUS")) {
                Draf poppedDraf;
                DeleteDraf(&(l->data[iduser-1].drafuser), &poppedDraf);
                printf("\nDraf telah berhasil dihapus!\n");
            } else if (compareString(action2,"KEMBALI")) {
                return ;
            }
        }
        else{
            return ;
        }
    }
}
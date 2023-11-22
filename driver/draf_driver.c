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
#include "../adt/header/listdin.h"
#include "../adt/header/draf.h"
#include "../adt/header/stack.h"
#include "../adt/header/matrix.h"
#include "../adt/header/pcolor.h"
// gcc -o draf driver/draf_driver.c adt/charmachine.c adt/wordmachine.c adt/time.c adt/datetime.c adt/liststatikuser.c adt/listdinkicauan.c adt/draf.c adt/stack.c adt/listdin.c adt/matrix.c adt/pcolor.c

int main() {
    ListStatikUser U;
    ListKicauan l;
    Kicauan tweet;
    Word w, command, action, action2, kata, kata2, text;
    DrafStack S;
    int idUser;
    DATETIME waktu;
    Draf poppedDraf;

    CreateEmptyStack(&S);
    CreateListGlobalKicauan(&l, CAPACITYMAXLISTKICAUAN);

    do{
        printf(">> ");
        STARTSENTENCE();
        command = currentWord;

        if(compareString(command,"BUAT_DRAF")){
            printf("Masukkan draf : \n");
            STARTSENTENCE();
            text = currentWord;
            printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");

            STARTSENTENCE();
            action = currentWord;
            if(compareString(action,"SIMPAN")){
                AddDraf(&S, text);
            } else if (compareString(action,"TERBIT")) {
                time_t current_time;
                time(&current_time);
                current_time+=3600*7;

                struct tm* timeinfo = gmtime(&current_time);

                Year(waktu) = 1900 + timeinfo->tm_year;
                Month(waktu) = timeinfo->tm_mon + 1;
                Day(waktu) = timeinfo->tm_mday;
                Time(waktu) = DetikToTIME(current_time);

                CreateKicauan(&tweet, NEFFLISTKICAU(l)+1, text, idUser, waktu);
                printf("Selamat! Draf kicauan telah diterbitkan!\n");
                DisplaySatuKicau(U, tweet);
                insertLastKicauan(&l, tweet);

                DeleteDraf(&S, &poppedDraf);
            } else if (compareString(action,"HAPUS")) {
                printf("Draf telah berhasil dihapus!\n");
            }

        } else if (compareString(command,"LIHAT_DRAF")) {
            if (!IsEmptyStack(S)) {
                LihatDraf(S);

                printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
                STARTSENTENCE();
                action = currentWord;
                if(compareString(action,"UBAH")){
                    printf("Masukkan draf yang baru: \n");
                    STARTSENTENCE();
                    text = currentWord;
                    EditDraf(&S, text);

                    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
                    STARTSENTENCE();
                    action2 = currentWord;
                    if(compareString(action2,"SIMPAN")){
                        AddDraf(&S, text);
                    } else if (compareString(action2,"TERBIT")) {
                        time_t current_time;
                        time(&current_time);
                        current_time+=3600*7;

                        struct tm* timeinfo = gmtime(&current_time);

                        Year(waktu) = 1900 + timeinfo->tm_year;
                        Month(waktu) = timeinfo->tm_mon + 1;
                        Day(waktu) = timeinfo->tm_mday;
                        Time(waktu) = DetikToTIME(current_time);
                        
                        CreateKicauan(&tweet, NEFFLISTKICAU(l)+1, DrafText(InfoTop(S)), idUser, waktu);
                        printf("Selamat! Draf kicauan telah diterbitkan!\n");
                        DisplaySatuKicau(U, tweet);
                        insertLastKicauan(&l, tweet);

                        DeleteDraf(&S, &poppedDraf);
                    } else if (compareString(action2,"HAPUS")) {
                        DeleteDraf(&S, &poppedDraf);
                        printf("Draf telah berhasil dihapus!\n");
                    }
                } else if (compareString(action,"TERBIT")) {
                    time_t current_time;
                    time(&current_time);
                    current_time+=3600*7;

                    struct tm* timeinfo = gmtime(&current_time);

                    Year(waktu) = 1900 + timeinfo->tm_year;
                    Month(waktu) = timeinfo->tm_mon + 1;
                    Day(waktu) = timeinfo->tm_mday;
                    Time(waktu) = DetikToTIME(current_time);

                    CreateKicauan(&tweet, NEFFLISTKICAU(l)+1, DrafText(InfoTop(S)), idUser, waktu);
                    printf("Selamat! Draf kicauan telah diterbitkan!\n");
                    DisplaySatuKicau(U, tweet);
                    insertLastKicauan(&l, tweet);
                    DeleteDraf(&S, &poppedDraf);
                } else if (compareString(action,"HAPUS")) {
                    DeleteDraf(&S, &poppedDraf);
                    printf("Draf telah berhasil dihapus!\n");
                } else if (compareString(action,"KEMBALI")) {
                    break;
                }
            } else {
                printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
            }
        }
    } while (!compareString(currentWord, "EXIT"));
}
#include <stdio.h>
#include <stdlib.h>
#include "../adt/header/treebalasan.h"
#include "../adt/header/liststatikuser.h"
#include "../adt/header/friendmatrix.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/listdinkicauan.h"

void langsungAddBalasan(ListKicauan *l, Word textBalasan, DATETIME curTime, int idKicau, int idBalasan, int curUserId, int *curIdBalasan){
    if(idBalasan == -1){
        ELMTLISTKICAU(*l, idKicau - 1).balasan = insertBalasan(ELMTLISTKICAU(*l, idKicau - 1).balasan, textBalasan, ++(*curIdBalasan), -1, curTime);
    }else{
        AddressBalasan curBalasan = searchAddressBalasan(ELMTLISTKICAU(*l, idKicau - 1).balasan, idBalasan);
        if(curBalasan == NIL){
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
            return;
        }
        CHILDBALASAN(*curBalasan) = insertBalasan(CHILDBALASAN(*curBalasan), textBalasan, ++(*curIdBalasan), curUserId, curTime);
    }
}

void BALASAN(ListKicauan *l, FriendMatrix *fh, ListStatikUser *lsu, int idKicau, int curUserId){
    if(idKicau >= NEFFLISTKICAU(*l)){
        printf("Tidak terdapat kicauan dengan id tersebut!\n");
        return;
    }
    if(UserTipe(*lsu, ELMTLISTKICAU(*l, idKicau - 1).idauthor - 1) == PRIVAT && !isFriend(*fh, curUserId, ELMTLISTKICAU(*l, idKicau - 1).idauthor - 1)){ // isFriend masih belum ada (4/11)
        printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
        return;
    }
    if(ELMTLISTKICAU(*l, idKicau - 1).balasan == NULL){
        printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
        return;
    }
    displaySemuaBalasan(ELMTLISTKICAU(*l, idKicau - 1).balasan, fh, lsu, curUserId, 0);
}

void BALAS(ListKicauan *l, FriendMatrix *fh, ListStatikUser *lsu, int idKicau, int idBalasan, int curUserId, int *curIdBalasan){
    if(idKicau >= NEFFLISTKICAU(*l)){ // banyakKicau belum terdefinisi
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        return;
    }
    if(UserTipe(*lsu, ELMTLISTKICAU(*l, idKicau - 1).idauthor - 1) == PRIVAT && !isFriend(*fh, curUserId, ELMTLISTKICAU(*l, idKicau - 1).idauthor - 1)){ // isFriend masih belum ada (4/11)
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
        return;
    }
    if(idBalasan == -1){
        Word textBalasan;
        printf("Masukkan balasan:\n");
        STARTSENTENCE();

        DATETIME curTime;
        time_t current_time;
        time(&current_time);
        current_time+=3600*7;
        struct tm* timeinfo = gmtime(&current_time);
        Year(curTime) = 1900 + timeinfo->tm_year;
        Month(curTime) = timeinfo->tm_mon + 1;
        Day(curTime) = timeinfo->tm_mday;
        Time(curTime) = DetikToTIME(current_time);

        textBalasan = currentWord;
        ELMTLISTKICAU(*l, idKicau - 1).balasan = insertBalasan(ELMTLISTKICAU(*l, idKicau - 1).balasan, textBalasan, ++(*curIdBalasan), curUserId, curTime);
    }else{
        AddressBalasan curBalasan = searchAddressBalasan(ELMTLISTKICAU(*l, idKicau - 1).balasan, idBalasan);
        if(curBalasan == NIL){
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
            return;
        }
        Word textBalasan;
        printf("Masukkan balasan:\n");
        STARTSENTENCE();

        DATETIME curTime;
        time_t current_time;
        time(&current_time);
        current_time+=3600*7;
        struct tm* timeinfo = gmtime(&current_time);
        Year(curTime) = 1900 + timeinfo->tm_year;
        Month(curTime) = timeinfo->tm_mon + 1;
        Day(curTime) = timeinfo->tm_mday;
        Time(curTime) = DetikToTIME(current_time);

        textBalasan = currentWord;


        CHILDBALASAN(*curBalasan) = insertBalasan(CHILDBALASAN(*curBalasan), textBalasan, ++(*curIdBalasan), curUserId, curTime);
    }
    printf("Selamat! balasan telah diterbitkan!\nDetil balasan:\n");
    AddressBalasan resBalasan = searchAddressBalasan(ELMTLISTKICAU(*l, idKicau - 1).balasan, (*curIdBalasan));
    // assert(resBalasan != NULL);
    displayUnitBalasan(resBalasan, lsu, true, 0);
}

void HAPUS_BALASAN(ListKicauan *l, int curUserId, int idKicau, int idBalasan){
    if(idKicau >= NEFFLISTKICAU(*l)){ // banyakKicau belum terdefinisi
        printf("Wah, tidak terdapat kicauan yang ingin Anda hapus!\n");
        return;
    }
    AddressBalasan resBalasan = searchAddressBalasan(ELMTLISTKICAU(*l, idKicau - 1).balasan, idBalasan);
    if(resBalasan == NIL){
        printf("Balasan tidak ditemukan\n");
        return;
    }
    if(IDPENULISBALASAN(*resBalasan) != curUserId){
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
        return;
    }
    boolean fd = false;
    AddressBalasan prev = findPrev(ELMTLISTKICAU(*l, idKicau - 1).balasan, NULL, &fd, idBalasan);
    AddressBalasan nxt = SIBLINGBALASAN(*resBalasan);
    hapusHelper(CHILDBALASAN(*resBalasan));
    free(resBalasan);
    if(prev == NIL){
        ELMTLISTKICAU(*l, idKicau - 1).balasan = nxt;
    }else{
        SIBLINGBALASAN(*prev) = nxt;
    }
}
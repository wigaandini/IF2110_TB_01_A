#include <stdio.h>
#include <stdlib.h>
#include "header/treebalasan.h"
#include "header/liststatikuser.h"
#include "header/friendmatrix.h"
#include "header/wordmachine.h"
#include "header/listdinkicauan.h"

void BALASAN(ListKicauan *l, FriendMatrix *fh, ListStatikUser *lsu, int idKicau, int curUserId){
    if(idKicau >= NEFFLISTKICAU(*l)){
        printf("Tidak terdapat kicauan dengan id tersebut!\n");
        return;
    }
    if(UserTipe(*lsu, ELMTLISTKICAU(*l, idKicau).idauthor) == PRIVAT && !isFriend(*fh, curUserId, ELMTLISTKICAU(*l, idKicau).idauthor)){ // isFriend masih belum ada (4/11)
        printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
        return;
    }
    if(ELMTLISTKICAU(*l, idKicau).balasan == NULL){
        printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
        return;
    }
    displaySemuaBalasan(ELMTLISTKICAU(*l, idKicau).balasan, fh, lsu, curUserId, 0);
}

void BALAS(ListKicauan *l, FriendMatrix *fh, ListStatikUser *lsu, Word textBalasan, DATETIME curTime, int idKicau, int idBalasan, int curUserId, int *curIdBalasan){
    if(idKicau >= NEFFLISTKICAU(*l)){ // banyakKicau belum terdefinisi
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        return;
    }
    if(UserTipe(*lsu, ELMTLISTKICAU(*l, idKicau).idauthor) == PRIVAT && !isFriend(*fh, curUserId, ELMTLISTKICAU(*l, idKicau).idauthor)){ // isFriend masih belum ada (4/11)
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
        return;
    }
    if(idBalasan == -1){
        ELMTLISTKICAU(*l, idKicau).balasan = insertBalasan(ELMTLISTKICAU(*l, idKicau).balasan, textBalasan, ++(*curIdBalasan), curUserId, curTime);
    }else{
        AddressBalasan curBalasan = searchAddressBalasan(ELMTLISTKICAU(*l, idKicau).balasan, idBalasan);
        if(curBalasan == NIL){
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
            return;
        }
        CHILDBALASAN(*curBalasan) = insertBalasan(CHILDBALASAN(*curBalasan), textBalasan, ++(*curIdBalasan), curUserId, curTime);
    }
    printf("Selamat! balasan telah diterbitkan!\nDetil balasan:\n");
    AddressBalasan resBalasan = searchAddressBalasan(ELMTLISTKICAU(*l, idKicau).balasan, (*curIdBalasan));
    assert(resBalasan != NULL);
    displayUnitBalasan(resBalasan, lsu, true);
}

void HAPUS_BALASAN(ListKicauan *l, int curUserId, int idKicau, int idBalasan){
    if(idKicau >= NEFFLISTKICAU(*l)){ // banyakKicau belum terdefinisi
        printf("Wah, tidak terdapat kicauan yang ingin Anda hapus!\n");
        return;
    }
    AddressBalasan resBalasan = searchAddressBalasan(ELMTLISTKICAU(*l, idKicau).balasan, idBalasan);
    if(resBalasan == NIL){
        printf("Balasan tidak ditemukan\n");
        return;
    }
    if(IDPENULISBALASAN(*resBalasan) != curUserId){
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
        return;
    }
    boolean fd = false;
    AddressBalasan prev = findPrev(ELMTLISTKICAU(*l, idKicau).balasan, NULL, &fd, idBalasan);
    AddressBalasan nxt = SIBLINGBALASAN(*resBalasan);
    hapusHelper(CHILDBALASAN(*resBalasan));
    free(resBalasan);
    if(prev == NIL){
        ELMTLISTKICAU(*l, idKicau).balasan = nxt;
    }else{
        SIBLINGBALASAN(*prev) = nxt;
    }
}
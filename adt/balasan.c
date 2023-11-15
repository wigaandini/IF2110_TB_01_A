#include <stdio.h>
#include <stdlib.h>
#include "balasan.h"
#include "header/liststatikuser.h"
#include "header/friendmatrix.h"
#include "header/listdinkicauan.h"
#include "header/wordmachine.h"

// ALERT !!! ListDinKicauan deklarasinya masih rada error

AddressBalasan newBalasan(int id, Word teks, int idPenulis, DATETIME waktu){
    AddressBalasan p = (AddressBalasan)malloc(sizeof(Balasan));
    if(p){ // p != NULL
        IDBALASAN(*p) = id;
        TEKSBALASAN(*p) = teks;
        IDPENULISBALASAN(*p) = idPenulis;
        WAKTUBALASAN(*p) = waktu;
        CHILDBALASAN(*p) = NIL;
    }
    return p; 
}

AddressBalasan searchAddressBalasan(AddressBalasan a, int idBalasan){
    if(a == NIL){
        return NIL;
    }
    if(IDBALASAN(*a) == idBalasan){
        return a;
    }
    AddressBalasan res = searchAddressBalasan(SIBLINGBALASAN(*a), idBalasan);
    if(res != NIL){
        return res;
    }
    return searchAddressBalasan(CHILDBALASAN(*a), idBalasan);
}

AddressBalasan insertBalasan(AddressBalasan a, Word text, int curIdBalasan, int curUserId, DATETIME waktu){
    if(a == NIL){
        return newBalasan(curIdBalasan, text, curUserId, waktu);
    }
    SIBLINGBALASAN(*a) = insertBalasan(SIBLINGBALASAN(*a), text, curIdBalasan, curUserId, waktu);
    return a;
}

void displayUnitBalasan(AddressBalasan a, ListStatikUser *lsu, boolean friend){
    if(!friend){
        printf("| %d\n", IDBALASAN(*a));
        printf("| PRIVAT\n");
        printf("| PRIVAT\n");
        printf("| PRIVAT\n");
    }else{
        printf("| %d\n", IDBALASAN(*a));
        printf("| ");
        int i = 0;
        while(UserName(*lsu, IDPENULISBALASAN(*a), i) != '\0'){
            printf("%c", UserName(*lsu, IDPENULISBALASAN(*a), i));
            i++;
        }
        printf("\n");
        printf("| ");
        TulisDATETIME(WAKTUBALASAN(*a));
        printf("\n");
        printf("| ");
        displayWord(TEKSBALASAN(*a));
        printf("\n");
    }
}

void displaySemuaBalasan(AddressBalasan a, FriendMatrix *fh, ListStatikUser *lsu, int curUserId, int indent){
    if(a == NIL){
        return;
    }
    int i;
    for(i = 0; i < indent; ++i){
        printf(" ");
    }
    printf("\n");
    boolean friend = (UserTipe(*lsu, IDPENULISBALASAN(*a)) == PRIVAT) && isFriend(*fh, curUserId, IDPENULISBALASAN(*a));
    friend = !friend;
    displayUnitBalasan(a, lsu, friend);
    displaySemuaBalasan(CHILDBALASAN(*a), fh, lsu, curUserId, indent + 3);
    displaySemuaBalasan(SIBLINGBALASAN(*a), fh, lsu, curUserId, indent);
}

void BALASAN(ListDinKicauan *l, FriendMatrix *fh, ListStatikUser *lsu, int idKicau, int curUserId){
    if(idKicau >= listLength(*l)){
        printf("Tidak terdapat kicauan dengan id tersebut!\n");
        return;
    }
    if(UserTipe(*lsu, ELMT(*l, idKicau).idAuthor) == PRIVAT && !isFriend(*fh, curUserId, ELMT(*l, idKicau).idAuthor)){ // isFriend masih belum ada (4/11)
        printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
        return;
    }
    if(ELMT(*l, idKicau).balasan == NULL){
        printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
        return;
    }
    displaySemuaBalasan(ELMT(*l, idKicau).balasan, fh, lsu, curUserId, 0);
}

void BALAS(ListDinKicauan *l, FriendMatrix *fh, ListStatikUser *lsu, Word textBalasan, DATETIME curTime, int idKicau, int idBalasan, int curUserId, int *curIdBalasan){
    if(idKicau >= listLength(*l)){ // banyakKicau belum terdefinisi
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        return;
    }
    if(UserTipe(*lsu, ELMT(*l, idKicau).idAuthor) == PRIVAT && !isFriend(*fh, curUserId, ELMT(*l, idKicau).idAuthor)){ // isFriend masih belum ada (4/11)
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
        return;
    }
    if(idBalasan == -1){
        ELMT(*l, idKicau).balasan = insertBalasan(ELMT(*l, idKicau).balasan, textBalasan, ++(*curIdBalasan), curUserId, curTime);
    }else{
        AddressBalasan curBalasan = searchAddressBalasan(ELMT(*l, idKicau).balasan, idBalasan);
        if(curBalasan == NIL){
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
            return;
        }
        CHILDBALASAN(*curBalasan) = insertBalasan(CHILDBALASAN(*curBalasan), textBalasan, ++(*curIdBalasan), curUserId, curTime);
    }
    printf("Selamat! balasan telah diterbitkan!\nDetil balasan:\n");
    AddressBalasan resBalasan = searchAddressBalasan(ELMT(*l, idKicau).balasan, (*curIdBalasan));
    assert(resBalasan != NULL);
    displayUnitBalasan(resBalasan, lsu, true);
}

AddressBalasan findPrev(AddressBalasan a, AddressBalasan prev, boolean *fd, int idBalasan){
    if(IDBALASAN(*a) == idBalasan){
        *fd = true;
        return prev;
    }
    AddressBalasan a1 = findPrev(SIBLINGBALASAN(*a), a, fd, idBalasan);
    if(*fd == true){
        return a1;
    }
    return findPrev(CHILDBALASAN(*a), a, fd, idBalasan);
}

void hapusHelper(AddressBalasan cur){
    if(cur == NULL){
        return;
    }
    hapusHelper(SIBLINGBALASAN(*cur));
    hapusHelper(CHILDBALASAN(*cur));
    free(cur);
}

void HAPUS_BALASAN(ListDinKicauan *l, int curUserId, int idKicau, int idBalasan){
    if(idKicau >= listLength(*l)){ // banyakKicau belum terdefinisi
        printf("Wah, tidak terdapat kicauan yang ingin Anda hapus!\n");
        return;
    }
    AddressBalasan resBalasan = searchAddressBalasan(ELMT(*l, idKicau).balasan, idBalasan);
    if(resBalasan == NIL){
        printf("Balasan tidak ditemukan\n");
        return;
    }
    if(IDPENULISBALASAN(*resBalasan) != curUserId){
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
        return;
    }
    boolean fd = false;
    AddressBalasan prev = findPrev(ELMT(*l, idKicau).balasan, NULL, &fd, idBalasan);
    AddressBalasan nxt = SIBLINGBALASAN(*resBalasan);
    hapusHelper(CHILDBALASAN(*resBalasan));
    free(resBalasan);
    if(prev == NIL){
        ELMT(*l, idKicau).balasan = nxt;
    }else{
        SIBLINGBALASAN(*prev) = nxt;
    }
}
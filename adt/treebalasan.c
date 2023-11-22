#include <stdio.h>
#include <stdlib.h>
#include "header/treebalasan.h"
#include "header/liststatikuser.h"
#include "header/friendmatrix.h"
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

int numBalasan(AddressBalasan a){
    if(a == NULL){
        return 0;
    }
    return (1 + numBalasan(SIBLINGBALASAN(*a)) + numBalasan(CHILDBALASAN(*a)));
}

void hapusHelper(AddressBalasan cur){
    if(cur == NULL){
        return;
    }
    hapusHelper(SIBLINGBALASAN(*cur));
    hapusHelper(CHILDBALASAN(*cur));
    free(cur);
}
#include <stdio.h>
#include <stdlib.h>
#include "../adt/header/configmachine.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/prioreqfollinked.h"
#include "../adt/header/friendmatrix.h"
#include "../adt/header/liststatikuser.h" //Ini perlu gak yah


void DAFTAR_TEMAN(int idlogin, ListStatikUser l){
    FriendMatrix m; 
    int ifriend = 0; 
    int i = 0;
    char namafriend = l.data[idlogin-1].nama;
    int nfriend = howMuchFriend(m, idlogin);
    if(nfriend!=0){
        printf("%s memiliki %d\n", namafriend, nfriend);
        printf("Daftar teman %s", namafriend);
        while(i<nfriend){
            if(isFriend(m, idlogin, ifriend)){
                printf("| %s\n", l.data[ifriend-1].nama);
                i++;
            }
            ifriend ++;
        }
    }
    else{
        printf("%s belum mempunyai teman\n", namafriend);
    }
}

void HAPUS_TEMAN(int idlogin, ListStatikUser l, FriendMatrix *m){
    Word friendname, keputusan;
    int ifol; 
    printf("Masukkan nama pengguna:\n");
    STARTSENTENCE();
    friendname = currentWord;
    while(!checkUserExist(l,friendname)){
        printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
        printf("Masukkan nama:\n");
        STARTSENTENCE();
        friendname = currentWord;
        printf("\n");
    }

    if(!isFriend(*m, idlogin, getIdOfName(l, friendname)-1)){
        printf("%s bukan teman Anda.\n", friendname);
    }
    else{
        printf("Apakah anda yakin ingin menghapus %s dari daftar teman anda:\n", friendname);
        STARTSENTENCE();
        keputusan = currentWord;

        while((compareString(keputusan, "YA"))&&(compareString(keputusan, "TIDAK"))){
            printf("Masukan anda tidak valid:\n");
            printf("Apakah anda yakin ingin menghapus %s dari daftar teman anda:\n");
            STARTSENTENCE();
            keputusan = currentWord;
        }

        if(compareString(keputusan, "YA")){
            deleteFriend(&m, idlogin, getIdOfName(l, friendname) - 1);
            printf("%s berhasil dihapus dari daftar teman anda\n", friendname);
        }
        else{
            printf("%s tidak jadi dihapus dari daftar teman anda\n", friendname);    
        }
    }
    
    
    
}


#include <stdio.h>
#include <stdlib.h>
#include "../adt/header/configmachine.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/prioreqfollinked.h"
#include "../adt/header/friendmatrix.h"
#include "../adt/header/liststatikuser.h" //Ini perlu gak yah


void DAFTAR_TEMAN(){
    FriendMatrix m; //NANTI DIHAPUS
    int idus; //PERLU PARAMETER
    int nfriend = howMuchFriend(m, idus); //PERLU VAR GLOBAL MATRIX
    if(nfriend!=0){
        //display nama user from id
        displayFriend(m, idus);
    }
    else{
        //display nama yg login
        //printf("Belum mempunyai teman")
    }
}

void HAPUS_TEMAN(){
    ListStatikUser l; //Nanti diganti
    FriendMatrix m; //Perlu var global
    Word friendname, keputusan;
    int idus, ifol; //Perlu diinisialisasi
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

    printf("Apakah anda yakin ingin menghapus %s dari daftar teman anda:\n");
    STARTSENTENCE();
    keputusan = currentWord;

    while((compareString(keputusan, "YA"))&&(compareString(keputusan, "TIDAK"))){
        printf("Masukan anda tidak valid:\n");
        printf("Apakah anda yakin ingin menghapus %s dari daftar teman anda:\n");
        STARTSENTENCE();
        keputusan = currentWord;
    }

    if(compareString(keputusan, "YA")){
        deleteFriend(&m, idus, ifol);
        printf("%s berhasil dihapus dari daftar teman anda\n", friendname);
    }
    else{
        printf("%s tidak jadi dihapus dari daftar teman anda\n", friendname);    
    }
    
}


int main(){
    boolean isLoggedIn = true;
    do{
        printf(">> ");
        STARTSENTENCE();
        printf("\n");
        if(compareString(currentWord, "DAFTAR_TEMAN")){
            DAFTAR_TEMAN();
        }
        else if(compareString(currentWord, "HAPUS_TEMAN")){
            HAPUS_TEMAN();
            isLoggedIn = true;
        }
        else if(compareString(currentWord, "KELUAR")){
            KELUAR();
            isLoggedIn = false;
        }
        else if(compareString(currentWord, "TUTUP_PROGRAM")){
            TUTUP_PROGRAM();
        }
    } while (!compareString(currentWord, "TUTUP PROGRAM"));
    // STARTSENTENCE();
    // displayWord(currentWord);
    // printf("\n");
    // boolean check = compareString(currentWord, "DAFTAR");
    // printf("%d\n", check);
    return 0;
}
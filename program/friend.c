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
    int nfriend = howMuchFriend(m, idlogin-1);
    if(nfriend!=0){
        printf("%s memiliki %d\n", namafriend, nfriend);
        printf("Daftar teman %s", namafriend);
        while(i<nfriend){
            if(isFriend(m, idlogin-1, ifriend-1)){
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

    if(!isFriend(*m, idlogin-1, getIdOfName(l, friendname)-1)){
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
            deleteFriend(&m, idlogin-1, getIdOfName(l, friendname) - 1);
            printf("%s berhasil dihapus dari daftar teman anda\n", friendname);
        }
        else{
            printf("%s tidak jadi dihapus dari daftar teman anda\n", friendname);    
        }
    }
}



void TAMBAH_TEMAN(int idlogin, ListStatikUser l, FriendMatrix m, Prioreqfol q){
    int idfriend;
    Word friendname;
    if(isEmptyReqFol(q)){
        //1. Nama harus valid
        //2. Nama tidak boleh sudah diajukan
        //3. kalo belom, pesannya beda
        printf("Masukkan nama pengguna:\n");
        STARTSENTENCE();
        friendname = currentWord;
        while(!checkUserExist(l,friendname)){
            printf("Pengguna bernama %s tidak ditemukan\n", friendname);
            printf("Masukkan nama:\n");
            STARTSENTENCE();
            friendname = currentWord;
            printf("\n");
        }

        idfriend = getIdOfName(l, friendname);
        //Nama sudah valid
        if(isFriend(m, idlogin-1, idfriend-1)){
            printf("Anda sudah berteman dengan %s!\n", friendname);
        }
        else if(isXRequestToY(l.data[idfriend-1].userReq, idlogin-1)){
            printf("Anda sudah mengirimkan permintaan pertemanan kepada %s. Silakan tunggu hingga permintaan Anda disetujui.\n", friendname);
        }
        else{
            sendReqFol(&(l.data[idfriend-1].userReq), m, idlogin-1, idfriend-1);
            printf("Permintaan pertemanan kepada %s telah dikirim. Tunggu beberapa saat hingga permintaan anda disetujui.", friendname);
        }
    }
    else{ //Prioreqfol masih ada isinya
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }
    
}

void DAFTAR_PERMINTAAN_PERTEMANAN(int idlogin ,FriendMatrix m, Prioreqfol myQ, ListStatikUser l){
    int nfriend = howMuchFriend(m, idlogin);
    Address p = ADDR_HEAD(myQ);
    if(isEmptyReqFol(myQ)){
        printf("Tidak ada permintaan pertemanan.\n");       
    }
    else{
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n", nfriend);
        printf("\n");

        while(p!=NULL){
            printf("| %s\n", l.data[IDUSER(p)].nama);
            printf("Jumlah teman: %d\n", NFRIENDUSER(p));
            printf("\n");
            NEXT(p);
        }
        
    }
}

void SETUJUI_PERTEMANAN(int idlogin, FriendMatrix m, Prioreqfol myQ, ListStatikUser l){    Word friendname, keputusan;
    Address p = ADDR_HEAD(myQ);
    if(isEmptyReqFol(myQ)){
        printf("Tidak ada permintaan pertemanan untuk Anda saat ini.\n");
    }
    else{
        char* friendname = l.data[IDUSER(p)].nama;
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
            deleteFriend(&m, idlogin, IDUSER(p));
            printf("%s berhasil dihapus dari daftar teman anda\n", friendname);
        }
        else{
            printf("%s tidak jadi dihapus dari daftar teman anda\n", friendname);    
        }

    }
        
}




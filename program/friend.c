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
    char namafriend[21];
    for(i = 0; i<21; i++){
        namafriend[i] = l.data[idlogin-1].nama[i];
    
    }
    i = 0;    
    int nfriend = howMuchFriend(m, idlogin-1);
    if(nfriend!=0){
        printf("%s memiliki %d\n", namafriend, nfriend);
        printf("Daftar teman %s", namafriend);
        while((i<nfriend)&&(ifriend<20)){
            if(isFriend(m, idlogin-1, ifriend)){
                printf("| %s\n", l.data[ifriend].nama);
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
        displayWord(friendname);
        printf(" bukan teman Anda.\n");
    }
    else{
        printf("Apakah anda yakin ingin menghapus ");
        displayWord(friendname);
        printf(" dari daftar teman anda:\n");
        STARTSENTENCE();
        keputusan = currentWord;

        while((compareString(keputusan, "YA"))&&(compareString(keputusan, "TIDAK"))){
            printf("Masukan anda tidak valid:\n");
            printf("Apakah anda yakin ingin menghapus ");
            displayWord(friendname);
            printf(" dari daftar teman anda:\n");
            STARTSENTENCE();
            keputusan = currentWord;
        }

        if(compareString(keputusan, "YA")){
            deleteFriend(m, idlogin-1, getIdOfName(l, friendname) - 1);
            displayWord(friendname);
            printf(" berhasil dihapus dari daftar teman anda\n");
        }
        else{
            displayWord(friendname);
            printf(" tidak jadi dihapus dari daftar teman anda\n");    
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
            printf("Pengguna bernama ");
            displayWord(friendname);
            printf(" tidak ditemukan\n");
            printf("Masukkan nama:\n");
            STARTSENTENCE();
            friendname = currentWord;
            printf("\n");
        }

        idfriend = getIdOfName(l, friendname);
        //Nama sudah valid
        if(isFriend(m, idlogin-1, idfriend-1)){
            printf("Anda sudah berteman dengan ");
            displayWord(friendname);
            printf(".\n");
        }
        else if(isXRequestToY(l.data[idfriend-1].userReq, idlogin-1)){
            printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
            displayWord(friendname);
            printf(". Silakan tunggu hingga permintaan Anda disetujui.\n");
        }
        else{
            sendReqFol(&(l.data[idfriend-1].userReq), m, idlogin-1, idfriend-1);
            printf("Permintaan pertemanan kepada ");
            displayWord(friendname);
            printf(" telah dikirim. Tunggu beberapa saat hingga permintaan anda disetujui.");
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
            printf("| ");
            char friendname[21];
            int i = 0;
            for(i = 0; i<21; i++){
                friendname[i] = l.data[IDUSER(p)].nama[i];
            }
            i = 0;  
            printf("%s \n", friendname);
            printf("Jumlah teman: %d\n", NFRIENDUSER(p));
            printf("\n");
            p = NEXT(p);
        }
        
    }
}

void SETUJUI_PERTEMANAN(int idlogin, FriendMatrix m, Prioreqfol myQ, ListStatikUser l){    
    char friendname[21];
    Word keputusan;
    Address p = ADDR_HEAD(myQ);
    if(isEmptyReqFol(myQ)){
        printf("Tidak ada permintaan pertemanan untuk Anda saat ini.\n");
    }
    else{
        
        int i = 0;
        for(i = 0; i<21; i++){
            friendname[i] = l.data[IDUSER(p)].nama[i];
        }
        i = 0;   
        printf("Apakah anda yakin ingin menghapus %s dari daftar teman anda:\n", friendname);
        STARTSENTENCE();
        keputusan = currentWord;

        while((compareString(keputusan, "YA"))&&(compareString(keputusan, "TIDAK"))){
            printf("Masukan anda tidak valid:\n");
            printf("Apakah anda yakin ingin menghapus %s dari daftar teman anda:\n", friendname);
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




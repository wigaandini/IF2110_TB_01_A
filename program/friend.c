#include <stdio.h>
#include <stdlib.h>
#include "../adt/header/configmachine.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/prioreqfollinked.h"
#include "../adt/header/friendmatrix.h"
#include "../adt/header/liststatikuser.h" //Ini perlu gak yah


void DAFTAR_TEMAN(int idlogin, ListStatikUser l,FriendMatrix m){
    int ifriend = 0; 
    int i = 0;
    char namafriend[21];
    for(i = 0; (l.data[idlogin-1].nama[i]!='\0'); i++){
        namafriend[i] = l.data[idlogin-1].nama[i];
    }
    namafriend[i]='\0' ;
    int nfriend = howMuchFriend(m, idlogin-1);
    i=0;
    if(nfriend!=0){
        printf("\n%s memiliki %d teman\n", namafriend, nfriend);
        printf("Daftar teman %s\n", namafriend);
        while((i<nfriend)&&(ifriend<20)){
            if(isFriend(m, idlogin-1, ifriend-1)){
                
                printf("| %s\n", l.data[ifriend-1].nama);
                i++;
            }
            ifriend ++;
        }
    }
    else{
        printf("\n%s belum mempunyai teman\n", namafriend);
    }
}

void HAPUS_TEMAN(int idlogin, ListStatikUser l, FriendMatrix *m){
    Word friendname, keputusan;
    printf("\nMasukkan nama pengguna:\n");
    STARTSENTENCE();
    friendname = currentWord;
    while(!checkUserExist(l,friendname)){
        printf("\nWah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
        printf("\nMasukkan nama:\n");
        STARTSENTENCE();
        friendname = currentWord;
        printf("\n");
    }

    if(!isFriend(*m, idlogin-1, getIdOfName(l, friendname)-1)){
        printf("\n");
        displayWord(friendname);
        printf(" bukan teman Anda.\n");
    }
    else{
        printf("\nApakah anda yakin ingin menghapus ");
        displayWord(friendname);
        printf(" dari daftar teman anda? (YA/TIDAK)\n");

        do{
            STARTSENTENCE();
            keputusan = currentWord;
            if (!compareString(keputusan, "YA")&&!compareString(keputusan, "TIDAK"))
            {
                printf("\nMasukan anda tidak valid:\n");
                printf("Apakah anda yakin ingin menghapus ");
                displayWord(friendname);
                printf(" dari daftar teman anda? (YA/TIDAK)\n");
            }
        }while((!compareString(keputusan, "YA"))&&(!compareString(keputusan, "TIDAK")));

        if(compareString(keputusan, "YA")){
            deleteFriend(m, idlogin-1, getIdOfName(l, friendname) - 1);
            printf("\n");
            displayWord(friendname);
            printf(" berhasil dihapus dari daftar teman anda\n");
        }
        else{
            printf("\n");
            displayWord(friendname);
            printf(" tidak jadi dihapus dari daftar teman anda\n");    
        }
    }
}

void TAMBAH_TEMAN(int idlogin, ListStatikUser *l, FriendMatrix m, Prioreqfol q){
    int idfriend;
    Word friendname;
    if(isEmptyReqFol(q)){
        //1. Nama harus valid
        //2. Nama tidak boleh sudah diajukan
        //3. kalo belom, pesannya beda
        printf("\nMasukkan nama pengguna:\n");
        STARTSENTENCE();
        friendname = currentWord;
        while(!checkUserExist(*l,friendname)){
            printf("\nPengguna bernama ");
            displayWord(friendname);
            printf(" tidak ditemukan.\n");
            printf("\nMasukkan nama pengguna:\n");
            STARTSENTENCE();
            friendname = currentWord;
            printf("\n");
        }

        idfriend = getIdOfName(*l, friendname);
        //Nama sudah valid
        if(isFriend(m, idlogin-1, idfriend-1)){
            printf("\nAnda sudah berteman dengan ");
            displayWord(friendname);
            printf(".\n");
        }
        else if(isXRequestToY((*l).data[idfriend-1].userReq, idlogin)){
            printf("\nAnda sudah mengirimkan permintaan pertemanan kepada ");
            displayWord(friendname);
            printf(". Silakan tunggu hingga permintaan Anda disetujui.\n");
        }
        else{
            sendReqFol(&((*l).data[idfriend-1].userReq), m, idlogin, idfriend,howMuchFriend(m,idlogin-1));
            printf("\nPermintaan pertemanan kepada ");
            displayWord(friendname);
            printf(" telah dikirim. Tunggu beberapa saat hingga permintaan anda disetujui.\n");
        }
    }
    else{ //Prioreqfol masih ada isinya
        printf("\nTerdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }
    
}

void DAFTAR_PERMINTAAN_PERTEMANAN(int idlogin ,FriendMatrix m, Prioreqfol myQ, ListStatikUser l){
    int nfriend = howMuchFriend(m, idlogin);
    Address p = ADDR_HEAD(myQ);
    if(isEmptyReqFol(myQ)){
        printf("\nTidak ada permintaan pertemanan.\n");       
    }
    else{
        Address p = ADDR_HEAD(myQ);
        int count=0;
        while (p!=NULL)
        {
            count++;
            p=NEXT(p);
        }
        printf("\nTerdapat %d permintaan pertemanan untuk Anda.\n", count);
        p=ADDR_HEAD(myQ);
        printf("\n");

        while(p!=NULL){
            char friendname[21];
            int i = 0;
            for(i = 0; i<21; i++){
                friendname[i] = l.data[IDUSER(p)-1].nama[i];
            }
            i = 0;  
            printf("| %s \n", friendname);
            printf("| Jumlah teman: %d\n", NFRIENDUSER(p));
            printf("\n");
            p = NEXT(p);
        }
        
    }
}
// #define here printf("here\n");
void SETUJUI_PERTEMANAN(int idlogin, FriendMatrix *m, Prioreqfol *myQ, ListStatikUser l){    
    char friendname[21];
    Word keputusan;
    Address p = ADDR_HEAD(*myQ);
    if(isEmptyReqFol(*myQ)){
        printf("\nTidak ada permintaan pertemanan untuk Anda saat ini.\n");
    }
    else{
        
        int i = 0;
        for(i = 0; i<20; i++){
            friendname[i] = l.data[IDUSER(p)-1].nama[i];
        }
        // i = 0;   
        // here

        printf("\nPermintaan pertemanan teratas dari %s\n",l.data[IDUSER(p)-1].nama);
        printf("| %s\n", l.data[IDUSER(p)-1].nama);
        printf("| Jumlah teman: %d\n", NFRIENDUSER(p));
        
        printf("\nApakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK)\n");
        STARTSENTENCE();
        keputusan = currentWord;

        while((!compareString(keputusan, "YA")) && (!compareString(keputusan, "TIDAK"))){
            printf("Masukan anda tidak valid:\n");
            printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK)  ", friendname);
            STARTSENTENCE();
            keputusan = currentWord;
        }

        if(compareString(keputusan, "YA")){
            addFriend(m, idlogin-1, IDUSER(p)-1);
            ElTypeReq x;
            dequeueReqFol(myQ,&x);
            printf("\nPermintaan pertemanan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.\n", friendname,friendname);
        }
        else{
            ElTypeReq x;
            dequeueReqFol(myQ,&x);
            printf("\nPermintaan pertemanana dari %s berhasil ditolak\n", friendname);    
        }
    }
}
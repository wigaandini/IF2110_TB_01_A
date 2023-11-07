#include <stdio.h>
#include <stdlib.h>
#include "../adt/header/configmachine.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/liststatikuser.h"
#include "../adt/header/friendmatrix.h"
#include "../adt/header/stack.h"
#include "../adt/header/matrix.h"
#include "../adt/header/listdin.h"

void DAFTAR(){
    ListStatikUser l;
    boolean isLoggedIn;
    Word nama, pass;
    CreateListStatikUser(&l);
    if(!isLoggedIn){
        if(isUserDataEmpty(l)){
            printf("Masukkan nama:\n");
            STARTSENTENCE();
            nama = currentWord;
            // displayWord(nama);
            printf("\n");
            printf("Masukkan kata sandi:\n");
            STARTSENTENCE();
            pass = currentWord;
            // displayWord(pass);
            printf("\n");
            addUser(&l, nama, pass);
            printListofUser(l);
            printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
        }
        else{
            printf("Masukkan nama:\n");
            STARTSENTENCE();
            printf("\n");
            nama = currentWord;
            while(!checkUserExist(l, nama)){
                printf("Wah, sayang sekali nama tersebut telah diambil.\n");
                printf("Masukkan kata sandi:\n");
                STARTSENTENCE();
                pass = currentWord;
                // displayWord(pass);
                printf("\n");
                addUser(&l, nama, pass);
                printListofUser(l);
                printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n\n");
            }
        }
    }
    else{
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    }
}

void MASUK(){
    boolean isLoggedIn = false;
    ListStatikUser l;
    Word nama, pass;
    printf("Masukkan nama:\n");
    STARTSENTENCE();
    nama = currentWord;
    printf("\n");
    while(!checkUserExist(l,nama)){
        printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
        printf("Masukkan nama:\n");
        STARTSENTENCE();
        nama = currentWord;
        printf("\n");
    }
    printf("Masukkan kata sandi:\n");
    STARTSENTENCE();
    pass = currentWord;
    printf("\n");
    while(!checkPass(l, nama, pass)){
        printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
        printf("Masukkan kata sandi:\n");
        STARTSENTENCE();
        pass = currentWord;
        printf("\n");
        if(checkPass(l, nama, pass)){
            isLoggedIn = true;
        }
    }
}

void KELUAR(){
    boolean isLoggedIn;
    if(!isLoggedIn){
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan Burbir.\n");
    }
    else{
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
    }
}

void TUTUP_PROGRAM(){
    printf("Anda telah keluar dari program Burbir. Sampai jumpa di pertemuan berikutnya!\n");
    exit(0);
}

int main(){
    boolean isLoggedIn = false;
    do{
        printf(">> ");
        STARTSENTENCE();
        printf("\n");
        if(compareString(currentWord, "DAFTAR")){
            DAFTAR();
        }
        else if(compareString(currentWord, "KELUAR")){
            KELUAR();
            isLoggedIn = false;
        }
        else if(compareString(currentWord, "MASUK")){
            MASUK();
            isLoggedIn = true;
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
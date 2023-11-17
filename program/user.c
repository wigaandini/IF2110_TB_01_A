#include <stdio.h>
#include <stdlib.h>
#include "../adt/header/configmachine.h"
#include "../adt/header/charmachine.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/liststatikuser.h"
#include "../adt/header/friendmatrix.h"
#include "../adt/header/stack.h"
#include "../adt/header/matrix.h"
#include "../adt/header/listdin.h"

void DAFTAR(ListStatikUser *l, boolean isLoggedIn){
    Word nama, pass;
    if(!isLoggedIn){
        if(isUserDataEmpty(*l)){
            printf("Masukkan nama:\n");
            STARTSENTENCE();
            while (currentWord.Length > 20 || checkUserExist(*l, currentWord)) {        // error handling
                if (currentWord.Length > 20) {
                    printf("\nNama yang Anda masukkan terlalu panjang. Silakan masukkan nama lain!\n");
                }
                else {
                    printf("\nWah, sayang sekali nama tersebut telah diambil.\n");
                }
                printf("\nMasukkan nama:\n");
                STARTSENTENCE();
            }
            nama = currentWord;

            // Kata Sandi
            printf("\nMasukkan kata sandi:\n");
            STARTSENTENCE();
            while (currentWord.Length > 20) {           // error handling
                printf("\nKata sandi yang Anda masukkan terlalu panjang. Silakan masukkan kata sandi lain!\n");
                printf("\nMasukkan kata sandi:\n");
                STARTSENTENCE();
            }
            pass = currentWord;

            // Menambahkan user baru ke dalam list
            addUser(l, nama, pass);
            printf("\nPengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n\n");
        }
        else {      // Kondisi User Data telah full oleh 20 user
            printf("\nJumlah pengguna telah mencapai batas maksimal. Silakan coba lagi nanti.\n\n");
        }
    }
    else{
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    }
}

void MASUK(ListStatikUser *l, boolean *isLoggedIn){
    Word nama, pass;
    printf("Masukkan nama:\n");
    STARTSENTENCE();
    nama = currentWord;
    printf("\n");
    if(!isLoggedIn){
        while(!checkUserExist(*l,nama)){
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
        while(!checkPass(*l, nama, pass)){
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            printf("Masukkan kata sandi:\n");
            STARTSENTENCE();
            pass = currentWord;
            printf("\n");
            if(checkPass(*l, nama, pass)){
                *isLoggedIn = true;
            }
        }
    }
    else{
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
    }
}

void KELUAR(boolean *isLoggedIn){
    if(!isLoggedIn){
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan Burbir.\n");
    }
    else{
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
        *isLoggedIn = false;
    }
}

void TUTUP_PROGRAM(){
    printf("\nAnda telah keluar dari program Burbir. Sampai jumpa di pertemuan berikutnya!\n");
    exit(0);
}

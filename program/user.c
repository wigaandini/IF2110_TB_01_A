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
        if(!isUserDataFull(*l)){
            // Nama
            printf("\nMasukkan nama:\n");
            STARTSENTENCE();
            while (currentWord.Length > 20 || checkUserExist(*l, currentWord)) {        // error handling
                if (currentWord.Length > 20) {
                    printf("\nNama yang Anda masukkan melebihi 20 karakter. Silakan masukkan nama lain!\n");
                }
                else if (checkUserExist(*l, currentWord)) {
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
                printf("\nKata sandi yang Anda masukkan melebihi 20 karakter. Silakan masukkan kata sandi lain!\n");
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
    else{    // Kondisi sudah login
        printf("\nAnda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n\n");
    }
}

void MASUK(ListStatikUser *l, boolean *isLoggedIn, int *id_login){      // belum selesai
    Word nama, pass;
    if(*isLoggedIn){
        printf("\nWah Anda sudah masuk. Keluar dulu yuk!\n\n");
    }
    else{
        printf("\nMasukkan nama:\n");
        STARTSENTENCE();
        while (currentWord.Length > 20 || !checkUserExist(*l, currentWord)) {
            if (currentWord.Length > 20) {
                printf("\nNama yang Anda masukkan melebihi 20 karakter. Silakan masukkan nama lain!\n");
            }
            else if (!checkUserExist(*l, currentWord)){
                printf("\nWah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
            }
            printf("\nMasukkan nama:\n");
            STARTSENTENCE();
        }
        nama = currentWord;

        printf("\nMasukkan kata sandi:\n");
        STARTSENTENCE();
        pass = currentWord;
        while(!checkPass(*l, nama, pass)){
            printf("\nWah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            printf("\nMasukkan kata sandi:\n");
            STARTSENTENCE();
            pass = currentWord;
            printf("\n");
           
        }
        *isLoggedIn = true;
        *id_login = getIdOfName(*l, nama);

        printf("\nAnda telah berhasil masuk dengan nama pengguna Tuan Bri. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n\n");
    }
}

void KELUAR(ListStatikUser *l, boolean *isLoggedIn, int *id_login){
    if(!*isLoggedIn){
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan Burbir.\n\n");
    }
    else{
        // Update status login dan id login
        *isLoggedIn = false;
        *id_login = -1;
        printf("\nAnda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n\n");
    }
}

void TUTUP_PROGRAM(){
    printf("\nAnda telah keluar dari program Burbir. Sampai jumpa di pertemuan berikutnya!\n");
    exit(0);
}

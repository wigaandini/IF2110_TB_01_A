#include "../adt/header/liststatikuser.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/charmachine.h"
#include "../adt/header/matrix.h"
#include <stdio.h>

// Prosedur print nama, bio, noHP, dan weton
void print_profil(ListStatikUser UserData, int id_login) {
    printf("\n| Nama\t\t: %s\n", UserData.data[id_login-1].nama);
    printf("| Bio Akun\t: %s\n", UserData.data[id_login-1].bio);
    printf("| No HP\t\t: ");
    for (int i = 0; i < UserNoHPNeff(UserData, id_login-1); i++) {
        printf("%c", UserNoHP(UserData, id_login-1, i));
    }
    printf("\n");
    printf("| Weton\t\t: ");
    switch (UserWeton(UserData, id_login-1)) 
    {
    case EMPTYWETON:
        printf("\n");
        break;
    case PAHING:
        printf("Pahing\n");
        break;
    case KLIWON:
        printf("Kliwon\n");
        break;
    case WAGE:
        printf("Wage\n");
        break;
    case PON:
        printf("Pon\n");
        break;
    case LEGI:
        printf("Legi\n");
        break;    
    default:
        break;
    }
}

// Perintah GANTI_PROFIL
void ganti_profil(ListStatikUser *UserData, int id_login) {
    // Print nama, bio, noHP, dan weton
    print_profil(*UserData, id_login);

    // Meminta masukkan Bio Akun
    printf("\nMasukkan Bio Akun: \n");
    STARTSENTENCE();
    while (currentWord.Length > 135)
    {
        printf("\nBio Akun terlalu panjang! Maksimal 135 karakter.\n\n");
        printf("Masukkan Bio Akun: \n");
        STARTSENTENCE();
    }
    printf("\n");
    // Perbarui Bio Akun
    for (int i = 0; i < 135; i++) {
        if (i < currentWord.Length) {
            UserBio(*UserData, id_login-1, i) = currentWord.TabWord[i];
        } else { // Jika currentWord.Length < 135, maka sisanya diisi dengan '\0'
            UserBio(*UserData, id_login-1, i) = '\0';
        }
    }

    // Meminta masukkan noHP
    printf("Masukkan No HP: \n");
    STARTSENTENCE();
    boolean valid = true;
    for (int i = 0; i<currentWord.Length; i++) {        // Cek valid
        if (currentWord.TabWord[i] < '0' || currentWord.TabWord[i] > '9') {
            valid = false;
        }
    }
    while (!valid) {
        printf("\nNo HP tidak valid. Masukkan lagi yuk!\n\n");
        printf("Masukkan No HP: \n");
        STARTSENTENCE();
        valid = true;
        for (int i = 0; i<currentWord.Length; i++) {        // Cek valid
            if (currentWord.TabWord[i] < '0' || currentWord.TabWord[i] > '9') {
                valid = false;
            }
        }
    }
    
    // Mengosongkan data noHP sebelumnya
    char buang;
    while (!isEmpty((*UserData).data[id_login-1].noHP)) {
        deleteLast(&(*UserData).data[id_login-1].noHP, &buang);
    }

    // Perbarui No HP
    for (int i = 0; i < currentWord.Length; i++) {
        insertLast(&(*UserData).data[id_login-1].noHP, currentWord.TabWord[i]);
        printList((*UserData).data[id_login-1].noHP);
    }

    // Meminta masukkan Weton
    printf("\nMasukkan Weton: \n");
    STARTSENTENCE();
    LowerCase();        // Ini fungsinya udah bisa dipake belom???
    while (!compareString(currentWord, "pahing") && !compareString(currentWord, "kliwon") 
    && !compareString(currentWord, "wage") && !compareString(currentWord, "pon") 
    && !compareString(currentWord, "legi") && !compareString(currentWord, "")) {
        printf("\nWeton yang dimasukkan tidak valid!\n\n");
        printf("Masukkan Weton: \n");
        STARTSENTENCE();
        LowerCase();
    }
    printf("\n");
    // Perbarui Weton
    if (compareString(currentWord, "pahing")) {
        UserWeton(*UserData, id_login-1) = PAHING;
    } else if (compareString(currentWord, "kliwon")) {
        UserWeton(*UserData, id_login-1) = KLIWON;
    } else if (compareString(currentWord, "wage")) {
        UserWeton(*UserData, id_login-1) = WAGE;
    } else if (compareString(currentWord, "pon")) {
        UserWeton(*UserData, id_login-1) = PON;
    } else if (compareString(currentWord, "legi")) {
        UserWeton(*UserData, id_login-1) = LEGI;
    } else if (compareString(currentWord, "")) { 
        UserWeton(*UserData, id_login-1) = EMPTYWETON;
    }

    // Akhirnya selese
    printf("\nProfil Anda sudah berhasil diperbarui!\n");
}


// Perintah LIHAT_PROFIL [NAMA]
void lihat_profil(ListStatikUser DataUser, Word nama) {       // Masukkan nya dalam bentuk list of char atau apa nih
    
    if (nama.Length > 20) {  // Jika nama lebih dari 20 karakter
        printf("\nNama yang Anda masukkan melebihi 20 karakter. Silakan ulangi dan masukkan nama lain!\n\n");
        return;
    }

    // Cari ID dari nama
    int id = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (j < nama.Length) {
                if (nama.TabWord[j] != UserName(DataUser, i, j)) {
                    break;
                }
            }
            if (j > nama.Length-1 && UserName(DataUser, i, j) != '\0') {
                break;
            }
            if (j == 19) {
                id = i+1;
            }
        }
    }

    if (id == 0) {  // Jika nama tidak ditemukan
        printf("\nNama tidak ditemukan!\n\n");
        return;
    }

    if (UserTipe(DataUser, id-1) != PUBLIK) {   // Jika akun privat
        printf("\nWah, akun %s diprivat nih. Ikuti dulu yuk untuk bisa melihat profil %s!\n\n", nama, nama);
        return;
    }

    // Print nama, bio, noHP, dan weton
    print_profil(DataUser, id);

    // Print foto profil
    printf("Foto profil akun %s\n", nama);
    displayMatrixFoto(UserFoto(DataUser, id-1), UserWarnaFoto(DataUser, id-1));
    printf("\n");
}


// Perintah ATUR_JENIS_AKUN
void atur_jenis_akun(ListStatikUser *DataUser, int id_login) {
    // Print nama, bio, noHP, dan weton
    print_profil(*DataUser, id_login);

    // Print jenis akun saat ini
    if (UserTipe(*DataUser, id_login-1) == PUBLIK) {
        printf("\nSaat ini, akun Anda adalah akun Publik.\nIngin mengubah ke akun Privat?\n(YA/TIDAK) ");
    } else {
        printf("\nSaat ini, akun Anda adalah akun Privat.\nIngin mengubah ke akun Publik?\n(YA/TIDAK) ");
    }
    STARTSENTENCE();
    printf("\n");
    // Handle masukkan ga sesuai YA/TIDAK
    while (!compareString(currentWord, "YA") && !compareString(currentWord, "TIDAK")) {
        printf("Masukkan tidak valid! Silakan masukkan YA atau TIDAK.\n");
        printf("(YA/TIDAK) ");
        STARTSENTENCE();
        printf("\n");
    }

    // Memperbarui jenis akun jika YA
    if (compareString(currentWord, "YA") && UserTipe(*DataUser, id_login-1) == PUBLIK) {
        printf("Akun anda sudah diubah menjadi akun Privat.\n");
        UserTipe(*DataUser, id_login-1) = PRIVAT;
    } else if (compareString(currentWord, "YA") && UserTipe(*DataUser, id_login-1) == PRIVAT) {
        printf("Akun anda sudah diubah menjadi akun Publik.\n");
        UserTipe(*DataUser, id_login-1) = PUBLIK;
    }
    printf("\n");
}


// Perintah UBAH_FOTO_PROFIL
void ubah_foto_profil(ListStatikUser DataUser, int id_login) {
    // Print foto profil saat ini
    printf("Foto profil Anda saat ini adalah\n");
    displayMatrixFoto(UserFoto(DataUser, id_login-1), UserWarnaFoto(DataUser, id_login-1));
    printf("\n");

    // Meminta masukkan foto profil
    printf("Masukkan foto profil yang baru\n");
    STARTSENTENCE();                            // Masukkan diasumsikan selalu valid den
    printf("\n");

    // Perbarui foto profil
    int kolom = 0, baris = 0;         
    for (int j = 0; j < currentWord.Length; j++) {  // Masih salah // Length sudah pasti 99
        if (currentWord.TabWord[j] == 'R' || currentWord.TabWord[j] == 'G' || currentWord.TabWord[j] == 'B') {
            UserWarnaFoto(DataUser, id_login-1).mem[baris][kolom] = currentWord.TabWord[j];
            UserFoto(DataUser, id_login-1).mem[baris][kolom] = currentWord.TabWord[j+2];
            kolom++;
        }
        if (kolom == 5) {
            kolom = 0;
            baris++;
        }
    }

    printf("\nFoto profil Anda sudah berhasil diganti!\n\n");
}
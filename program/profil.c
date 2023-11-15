#include "../adt/header/liststatikuser.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/charmachine.h"
#include "../adt/header/matrix.h"
#include <stdio.h>

// Prosedur print nama, bio, noHP, dan weton
void print_profil(ListStatikUser UserData, int id_login) {
    printf("| Nama\t: %s\n", UserData.data[id_login-1].nama);
    printf("| Bio Akun\t: %s\n", UserData.data[id_login-1].bio);
    printf("| No HP\t: ");
    for (int i = 0; i < UserNoHPNeff(UserData, id_login-1); i++) {
        printf("%c", UserNoHP(UserData, id_login-1, i));
    }
    printf("\n");
    printf("| Weton\t: ");
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
void ganti_profil(ListStatikUser UserData, int id_login) {
    // Print nama, bio, noHP, dan weton
    print_profil(UserData, id_login);

    // Meminta masukkan Bio Akun
    printf("Masukkan Bio Akun: \n");
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
            UserBio(UserData, id_login-1, i) = currentWord.TabWord[i];
        } else { // Jika currentWord.Length < 135
            UserBio(UserData, id_login-1, i) = '\0';
        }
    }

    // Meminta masukkan noHP
    printf("Masukkan No HP: \n");
    STARTSENTENCE();
    boolean valid = true;
    for (int i = 0; i<currentWord.Length; i++) {
        if (currentWord.TabWord[i] < '0' || currentWord.TabWord[i] > '9') {
            valid = false;
        }
    }
    while (!valid) {
        printf("\nNo HP hanya boleh berisi angka!\n\n");
        printf("Masukkan No HP: \n");
        STARTSENTENCE();
        valid = true;
        for (int i = 0; i<currentWord.Length; i++) {
            if (currentWord.TabWord[i] < '0' || currentWord.TabWord[i] > '9') {
                valid = false;
            }
        }
    }
    printf("\n");
    // Perbarui No HP
    for (int i = 0; i < 20; i++) {
        if (i < currentWord.Length) {
            UserNoHP(UserData, id_login-1, i) = currentWord.TabWord[i];
        } else { // Jika currentWord.Length < 20
            UserNoHP(UserData, id_login-1, i) = '\0';
        }
    }
    UserNoHPNeff(UserData, id_login-1) = currentWord.Length;

    // Meminta masukkan Weton
    printf("Masukkan Weton: \n");
    STARTSENTENCE();
    // LowerCase();        // Ini fungsinya blm jadi
    while (!compareString(currentWord, "pahing") && !compareString(currentWord, "kliwon") && !compareString(currentWord, "wage") && !compareString(currentWord, "pon") && !compareString(currentWord, "legi") && !compareString(currentWord, "")) {
        printf("\nWeton yang dimasukkan tidak valid!\n\n");
        printf("Masukkan Weton: \n");
        STARTSENTENCE();
        // LowerCase();
    }
    printf("\n");
    // Perbarui Weton
    if (compareString(currentWord, "pahing")) {
        UserWeton(UserData, id_login-1) = PAHING;
    } else if (compareString(currentWord, "kliwon")) {
        UserWeton(UserData, id_login-1) = KLIWON;
    } else if (compareString(currentWord, "wage")) {
        UserWeton(UserData, id_login-1) = WAGE;
    } else if (compareString(currentWord, "pon")) {
        UserWeton(UserData, id_login-1) = PON;
    } else if (compareString(currentWord, "legi")) {
        UserWeton(UserData, id_login-1) = LEGI;
    } else if (compareString(currentWord, "")) {        // Pastiin kalo fungsi compareString udah nge handle kasus string kosong
        UserWeton(UserData, id_login-1) = EMPTYWETON;
    }

    // Akhirnya selese
    printf("Profil Anda sudah berhasil diperbarui!\n");
}


// Perintah LIHAT_PROFIL [NAMA]
void lihat_profil(ListStatikUser DataUser, char nama[]) {       // Masukkan nya dalam bentuk list of char atau apa nih
    // Mengetahui panjang array of char nama[]
    int namaLength = 0;
    for (int i = 0; i < 20; i++) {
        if (nama[i] != '\0') {
            namaLength++;
        }
    }

    // Cari ID dari nama
    int id = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (j < namaLength) {
                if (nama[j] != UserName(DataUser, i, j)) {
                    break;
                }
            }
            if (j > namaLength-1 && UserName(DataUser, i, j) != '\0') {
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
        printf("Wah, akun %s diprivat nih. Ikuti dulu yuk untuk bisa melihat profil %s!\n\n", nama, nama);
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
void atur_jenis_akun(ListStatikUser DataUser, int id_login) {
    // Print nama, bio, noHP, dan weton
    print_profil(DataUser, id_login);

    // Print jenis akun saat ini
    if (UserTipe(DataUser, id_login-1) == PUBLIK) {
        printf("Saat ini, akun Anda adalah akun Publik.\nIngin mengubah ke akun Privat?\n(YA/TIDAK)");
    } else {
        printf("Saat ini, akun Anda adalah akun Privat.\nIngin mengubah ke akun Publik?\n(YA/TIDAK) ");
    }
    STARTSENTENCE();
    printf("\n\n");
    // Memperbarui jenis akun jika YA
    if (compareString(currentWord, "YA") && UserTipe(DataUser, id_login-1) == PUBLIK) {
        printf("Akun anda sudah diubah menjadi akun Privat.\n");
        UserTipe(DataUser, id_login-1) = PRIVAT;
    } else if (compareString(currentWord, "YA") && UserTipe(DataUser, id_login-1) == PRIVAT) {
        printf("Akun anda sudah diubah menjadi akun Publik.\n");
        UserTipe(DataUser, id_login-1) = PUBLIK;
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
    STARTSENTENCE();                            // Masukkan diasumsikan selalu valid
    printf("\n");

    // Perbarui foto profil (i : baris, j : kolom)
    int kolom = 0, baris = 0;         // kolom : sebagai idx
    for (int j = 0; j < currentWord.Length; j++) {  // Masih salah // Length sudah pasti 99
        if (currentWord.TabWord[j] == 'R' || currentWord.TabWord[j] == 'G' || currentWord.TabWord[j] == 'B') {
            UserWarnaFoto(DataUser, id_login-1).mem[baris][kolom] = currentWord.TabWord[j];
        }
        else if (currentWord.TabWord[j] != ' ' && currentWord.TabWord[j] != '\n') {
            UserFoto(DataUser, id_login-1).mem[baris][kolom] = currentWord.TabWord[j];
            kolom++;
        }
        if (kolom == 5) {
            kolom = 0;
            baris++;
        }
    }

    printf("\nFoto profil Anda sudah berhasil diganti!\n\n");
}
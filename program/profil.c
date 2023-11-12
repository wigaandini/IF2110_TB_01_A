#include "../adt/header/liststatikuser.h"
#include <stdio.h>

void ganti_profil(ListStatikUser UserData, int id_login) {
    // Print nama, bio, noHP, dan weton
    printf("| Nama\t: %s\n", UserData.data[id_login-1].nama);
    printf("| Bio Akun\t: %s\n", UserData.data[id_login-1].bio);
    printf("| No HP\t: ");
    for (int i = 0; i < UserNoHPLength(UserData, id_login-1); i++) {
        printf("%c", UserNoHP(UserData, id_login-1, i));
    }
    printf("\n");
    printf("| Weton\t: ");
    switch (UserWeton(UserData, id_login-1)) 
    {
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

    // Meminta masukkan Bio Akun

    // Meminta masukkan noHP

    // Meminta masukkan Weton

    // Akhirnya selese
    printf("Profil Anda sudah berhasil diperbarui!\n");
}
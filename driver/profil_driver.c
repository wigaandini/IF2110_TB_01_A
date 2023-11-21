#include <stdio.h>
#include "../program/profil.c"
#include "../adt/liststatikuser.c"
#include "../adt/wordmachine.c"
#include "../adt/charmachine.c"
#include "../adt/pcolor.c"
#include "../adt/matrix.c"
#include "../adt/listdin.c"
#include "../program/user.c"

int main() {
    // Inisialisasi data pengguna dan ID login
    ListStatikUser userData;
    boolean isLogin = false;
    int idLogin = 0; // Ganti dengan ID login yang sesuai

    // Inisialisasi data pengguna sesuai dengan kebutuhan program Anda
    CreateListStatikUser(&userData);
    DAFTAR(&userData, isLogin);
    DAFTAR(&userData, isLogin);
    DAFTAR(&userData, isLogin);

    // LOGIN
    printf("\nLOGIN:\n");
    MASUK(&userData, &isLogin, &idLogin);
    printf("id login = %d\n", idLogin);

    // Uji fungsi ganti_profil
    printf("\nUji fungsi ganti_profil:\n");
    ganti_profil(&userData, idLogin);
    printListofUser(userData);

    // Uji fungsi lihat_profil
    printf("\nUji fungsi lihat_profil:\n");
    char nama[] = "nama1"; // Ganti dengan nama yang sesuai
    lihat_profil(userData, nama);
    printListofUser(userData);

    // Uji fungsi atur_jenis_akun
    printf("\nUji fungsi atur_jenis_akun:\n");
    atur_jenis_akun(&userData, idLogin);
    printListofUser(userData);

    // Uji fungsi ubah_foto_profil
    printf("\nUji fungsi ubah_foto_profil:\n");
    ubah_foto_profil(userData, idLogin);
    printListofUser(userData);

    return 0;
}

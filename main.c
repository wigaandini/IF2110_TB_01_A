#include <stdio.h>
#include <stdlib.h>
#include "program/readpengguna.c"
#include "program/readkicauan.c"
#include "program/readdraf.c"
#include "program/readutas.c"
#include "program/user.c"
#include "program/profil.c"
#include <sys/stat.h>

// gcc main.c adt/configmachine.c adt/charmachine.c adt/liststatikuser.c adt/listdin.c adt/Matrix.c adt/friendmatrix.c adt/pcolor.c adt/prioreqfollinked.c adt/listdinkicauan.c adt/datetime.c adt/time.c adt/wordmachine.c -o tes

boolean is_directory(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
        return 0;
    return S_ISDIR(statbuf.st_mode);
}


int main(){
    ListStatikUser l;
    ListKicauan k;
    FriendMatrix F;

    system("clear");
    printf(".______    __    __  .______      .______    __  .______\n");
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\\n");
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |\n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      / \n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n");
    printf("\n");

    printf("Selamat datang di BurBir.\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");

    boolean jalan=false;
    char fullPath[200];
    char *dirName;
    do
    {
        printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
        Word config;
        STARTSENTENCE();

        config = currentWord;
        dirName = WordToString(config);
        concatenate(fullPath, "config/", dirName);
        if (!is_directory(fullPath)){
            printf("\nFolder config dengan nama '%s' tidak ditemukan\n\n", dirName);
        } else{
            ReadUser(&l,&F,fullPath);
            ReadKicauan(&k,l,F,fullPath);
            ReadDraf(&l,fullPath);
            ReadUtas(&k,l,fullPath);

            // printListofUser(l);
            // DisplayAllKicauan(l,k);
            printf("\n");
            printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
            jalan=true; 
        }
        
    } while (!is_directory(fullPath));
    free(dirName);

    // int currentuser=0;

    if (jalan)
    {
        boolean selesai=false, isLoggedIn=false;
        int id_login=-1;        // id_login = -1 berarti belum login. id_login yang digunakan [1..banyakUser]
        Word w, command, kata;
        while (!selesai){
            printf("\n>> ");
            STARTSENTENCE();
            command = currentWord;

        if (countWords(command) == 1) {
            kata = command;
        } else {
            kata = splitCommand(&w, command, 1);
        }
        // BAGIAN PERINTAH (PENGGUNA)
        
        if (compareString(kata,"DAFTAR")){ //DAFTAR
            DAFTAR(&l, isLoggedIn);
        }

        else if (compareString(kata,"MASUK")){ //MASUK
            MASUK(&l, &isLoggedIn, &id_login);
        }

        else if (compareString(kata,"KELUAR")){ //KELUAR
            KELUAR(&l, &isLoggedIn, &id_login);
        }

        else if (compareString(kata,"TUTUP_PROGRAM")){ //TUTUP
            // printf("\nAnda telah keluar dari program BurBir.\nSampai jumpa di penjelajahan berikutnya.\n");
            // selesai=true;
            TUTUP_PROGRAM();
        }

        // BAGIAN PERINTAH (PROFIL)
        else if (compareString(kata,"GANTI_PROFIL")){ //GANTI_PROFIL
            ganti_profil(&l, id_login);
        }

        else if (compareString(kata,"LIHAT_PROFIL")){ //LIHAT_PROFIL
            Word nama = splitCommand(&w, command, 2);
            displayWord(nama);
            printf("\n");
            lihat_profil(l, nama, isLoggedIn);
        }

        else if (compareString(kata,"ATUR_JENIS_AKUN")){ //ATUR_JENIS_AKUN
            atur_jenis_akun(&l, id_login, isLoggedIn);
        }

        else if (compareString(kata,"UBAH_FOTO_PROFIL")){ //UBAH_FOTO_PROFIL
            ubah_foto_profil(&l, id_login);
        }

        // BAGIAN PERINTAH (TEMAN)
        else if (compareString(kata,"DAFTAR_TEMAN")){ //DAFTAR_TEMAN
            printf("\ndaftarteman\n");
        }

        else if (compareString(kata,"HAPUS_TEMAN")){ //HAPUS_TEMAN
            printf("\nHAPUSteman\n");
        }

        // BAGIAN PERINTAH (PERMINTAAN TEMAN)
        else if (compareString(kata,"TAMBAH_TEMAN")){ //TAMBAH_TEMAN
            printf("\nTAMBAHTEMAN\n");
        }

        else if (compareString(kata,"DAFTAR_PERMINTAAN_TEMAN")){ //DAFTAR_PERMINTAAN
            printf("\nLISTteman\n");
        }
        else if (compareString(kata,"SETUJUI_PERTEMANAN")){ //SETUJUI_PERTEMANAN
            printf("\nSETUJUteman\n");
        }

        // BAGIAN PERINTAH (KICAUAN)
        else if (compareString(kata,"KICAU")){ //KICAU
            printf("\nKICAU\n");
        }

        else if (compareString(kata,"KICAUAN")){ //KICAUAN
            printf("\nKICAUAN\n");
        }

        else if (compareString(kata,"SUKA_KICAUAN")){ //SUKA_KICAUAN
            printf("\nSUKAKICAU\n");
        }
        else if (compareString(kata,"UBAH_KICAUAN")){ //UBAH_KICAUAN
            printf("\nUBAHKICAU\n");
        }

        // BAGIAN PERINTAH (BALASAN)
        else if (compareString(kata,"BALAS")){ //BALAS
            printf("\nBALAS\n");
        }

        else if (compareString(kata,"BALASAN")){ //BALASAN
            printf("\nBALASAN\n");
        }

        else if (compareString(kata,"HAPUS_BALASAN")){ //HAPUSBALAS
            printf("\nHAPUSBALASAN\n");
        }

        // BAGIAN PERINTAH (DRAF KICAUAN)
        else if (compareString(kata,"BUAT_DRAF")){ //BUAT_DRAF
            printf("\nBUATDRAF\n");
        }
        else if (compareString(kata,"LIHAT_DRAF")){ //LIHAT_DRAF
            printf("\nLIHATDRAF\n");
        }

        // BAGIAN PERINTAH (UTAS)
        else if (compareString(kata,"UTAS")){ //UTAS
            printf("\nUTAS\n");
        }

        else if (compareString(kata,"SAMBUNG_UTAS")){ //SAMBUNG_UTAS
            printf("\nSAMBUNGUTAS\n");
        }

        else if (compareString(kata,"HAPUS_UTAS")){ //HAPUS_UTAS
            printf("\nHAPUSUTAS\n");
        }

        else if (compareString(kata,"CETAK_UTAS")){ //CETAK_UTAS
            printf("\nCETAKUTAS\n");
        }

        // BAGIAN PERINTAH (SIMPAN & MUAT)
        else if (compareString(kata,"SIMPAN")){ //SIMPAN
            printf("\nSIMPAN\n");
        }

        else if (compareString(kata,"MUAT")){ //MUAT
            printf("\nMUAT\n");
        }

        ADVWORD();
        // }
        // printf("ter:%s\n",Terminal.TabWord);
        // printf("cr:%s\n",currentWord.TabWord);
    }
    }
    
    return 0;
}

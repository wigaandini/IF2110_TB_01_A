#include <stdio.h>
#include <stdlib.h>
#include "program/readpengguna.c"
#include "program/readkicauan.c"
#include "program/readdraf.c"

// gcc main.c adt/configmachine.c adt/charmachine.c adt/liststatikuser.c adt/listdin.c adt/Matrix.c adt/friendmatrix.c adt/pcolor.c adt/prioreqfollinked.c adt/listdinkicauan.c adt/datetime.c adt/time.c adt/wordmachine.c -o tes

int main(){
    ListStatikUser l;
    ListKicauan k;
    FriendMatrix F;

    ReadUser(&l,&F);
    ReadKicauan(&k,l,F);
    ReadDraf(&l);

    printListofUser(l);
    DisplayAllKicauan(l,k);
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
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    // Word Load;
    // STARTWORD();
    // while (!EndWord){
    //     ADVWORD();
    // }
    printf("\n");
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");

    // int currentuser=0;

    boolean selesai=false;
    while (!selesai)
    {
        printf("\n>> ");
        STARTSENTENCE();
        if (!EndWord){
            ADVWORD();
            // BAGIAN PERINTAH (PENGGUNA)
            // boolean masukanbenar=true;
            
            if (compareString(currentWord,"DAFTAR")){ //DAFTAR
                printf("\nYADAFTAR\n");
            }

            else if (compareString(currentWord,"MASUK")){ //MASUK
                printf("\nYAMASUK\n");
            }

            else if (compareString(currentWord,"KELUAR")){ //KELUAR
                printf("\nYAKELUAR\n");
            }

            else if (compareString(currentWord,"TUTUP_PROGRAM")){ //TUTUP
                printf("\nAnda telah keluar dari program BurBir.\nSampai jumpa di penjelajahan berikutnya.\n");
                selesai=true;
            }

            // BAGIAN PERINTAH (PROFIL)
            else if (compareString(currentWord,"GANTI_PROFIL")){ //GANTI_PROFIL
                printf("\ngantiprofil\n");
            }

            else if (compareString(currentWord,"LIHAT_PROFIL")){ //LIHAT_PROFIL
                printf("\nlihatprofil\n");
            }

            else if (compareString(currentWord,"ATUR_JENIS_AKUN")){ //ATUR_JENIS_AKUN
                printf("\njenisakun\n");
            }

            else if (compareString(currentWord,"UBAH_FOTO_PROFIL")){ //UBAH_FOTO_PROFIL
                printf("\nUBAHPROFIL\n");
            }

            // BAGIAN PERINTAH (TEMAN)
            else if (compareString(currentWord,"DAFTAR_TEMAN")){ //DAFTAR_TEMAN
                printf("\ndaftarteman\n");
            }

            else if (compareString(currentWord,"HAPUS_TEMAN")){ //HAPUS_TEMAN
                printf("\nHAPUSteman\n");
            }

            // BAGIAN PERINTAH (PERMINTAAN TEMAN)
            else if (compareString(currentWord,"TAMBAH_TEMAN")){ //TAMBAH_TEMAN
                printf("\nTAMBAHTEMAN\n");
            }

            else if (compareString(currentWord,"DAFTAR_PERMINTAAN_TEMAN")){ //DAFTAR_PERMINTAAN
                printf("\nLISTteman\n");
            }
            else if (compareString(currentWord,"SETUJUI_PERTEMANAN")){ //SETUJUI_PERTEMANAN
                printf("\nSETUJUteman\n");
            }

            // BAGIAN PERINTAH (KICAUAN)
            else if (compareString(currentWord,"KICAU")){ //KICAU
                printf("\nKICAU\n");
            }

            else if (compareString(currentWord,"KICAUAN")){ //KICAUAN
                printf("\nKICAUAN\n");
            }

            else if (compareString(currentWord,"SUKA_KICAUAN")){ //SUKA_KICAUAN
                printf("\nSUKAKICAU\n");
            }
            else if (compareString(currentWord,"UBAH_KICAUAN")){ //UBAH_KICAUAN
                printf("\nUBAHKICAU\n");
            }

            // BAGIAN PERINTAH (BALASAN)
            else if (compareString(currentWord,"BALAS")){ //BALAS
                printf("\nBALAS\n");
            }

            else if (compareString(currentWord,"BALASAN")){ //BALASAN
                printf("\nBALASAN\n");
            }

            else if (compareString(currentWord,"HAPUS_BALASAN")){ //HAPUSBALAS
                printf("\nHAPUSBALASAN\n");
            }

            // BAGIAN PERINTAH (DRAF KICAUAN)
            else if (compareString(currentWord,"BUAT_DRAF")){ //BUAT_DRAF
                printf("\nBUATDRAF\n");
            }
            else if (compareString(currentWord,"LIHAT_DRAF")){ //LIHAT_DRAF
                printf("\nLIHATDRAF\n");
            }

            // BAGIAN PERINTAH (UTAS)
            else if (compareString(currentWord,"UTAS")){ //UTAS
                printf("\nUTAS\n");
            }

            else if (compareString(currentWord,"SAMBUNG_UTAS")){ //SAMBUNG_UTAS
                printf("\nSAMBUNGUTAS\n");
            }

            else if (compareString(currentWord,"HAPUS_UTAS")){ //HAPUS_UTAS
                printf("\nHAPUSUTAS\n");
            }

            else if (compareString(currentWord,"CETAK_UTAS")){ //CETAK_UTAS
                printf("\nCETAKUTAS\n");
            }

            // BAGIAN PERINTAH (SIMPAN & MUAT)
            else if (compareString(currentWord,"SIMPAN")){ //SIMPAN
                printf("\nSIMPAN\n");
            }

            else if (compareString(currentWord,"MUAT")){ //MUAT
                printf("\nMUAT\n");
            }

            ADVWORD();
        }
        // printf("ter:%s\n",Terminal.TabWord);
        // printf("cr:%s\n",currentWord.TabWord);
    }

    return 0;
}

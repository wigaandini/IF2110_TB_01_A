#include <stdio.h>
#include <stdlib.h>
#include "program/readpengguna.c"
#include "program/readkicauan.c"

// gcc main.c adt/configmachine.c adt/charmachine.c adt/liststatikuser.c adt/listdin.c adt/Matrix.c adt/friendmatrix.c adt/pcolor.c adt/prioreqfollinked.c adt/listdinkicauan.c adt/datetime.c adt/time.c adt/wordmachine.c -o tes

int main(){
    ListStatikUser l;
    ListKicauan k;
    FriendMatrix F;

    ReadUser(&l,&F);
    ReadKicauan(&k,l,F);

    // printListofUser(l);
    // DisplayKicauan(l,k,3,F);
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

    int currentuser=0;

    boolean selesai=false;
    while (!selesai)
    {
        printf("\n>> ");
        STARTWORD();
        if (!EndWord){
            ADVWORD();
            // BAGIAN PERINTAH (PENGGUNA)
            boolean masukanbenar=true;
            if (currentWord.TabWord[0] == 'D' && currentWord.TabWord[1] == 'A'
            && currentWord.TabWord[2] == 'F' && currentWord.TabWord[3] == 'T'
            && currentWord.TabWord[4] == 'A' && currentWord.TabWord[5] == 'R'
            && currentWord.Length==6){ //DAFTAR
                printf("\nYADAFTAR\n");
            }

            else if (currentWord.TabWord[0] == 'M' && currentWord.TabWord[1] == 'A'
            && currentWord.TabWord[2] == 'S' && currentWord.TabWord[3] == 'U'
            && currentWord.TabWord[4] == 'K'){ //MASUK
                printf("\nYAMASUK\n");
            }

            else if (currentWord.TabWord[0] == 'K' && currentWord.TabWord[1] == 'E'
            && currentWord.TabWord[2] == 'L' && currentWord.TabWord[3] == 'U'
            && currentWord.TabWord[4] == 'A' && currentWord.TabWord[5] == 'R'){ //KELUAR
                printf("\nYAKELUAR\n");
            }

            else if (currentWord.TabWord[0] == 'T' && currentWord.TabWord[1] == 'U'
            && currentWord.TabWord[2] == 'T' && currentWord.TabWord[3] == 'U'
            && currentWord.TabWord[4] == 'P' && currentWord.TabWord[5] == '_'
            && currentWord.TabWord[6] == 'P' && currentWord.TabWord[7] == 'R'
            && currentWord.TabWord[8] == 'O' && currentWord.TabWord[9] == 'G'
            && currentWord.TabWord[10] == 'R' && currentWord.TabWord[11] == 'A'
            && currentWord.TabWord[12] == 'M'){ //TUTUP
                printf("\nAnda telah keluar dari program BurBir.\nSampai jumpa di penjelajahan berikutnya.\n");
                selesai=true;
            }

            // BAGIAN PERINTAH (PROFIL)
            else if (currentWord.TabWord[0] == 'G' && currentWord.TabWord[1] == 'A'
            && currentWord.TabWord[2] == 'N' && currentWord.TabWord[3] == 'T'
            && currentWord.TabWord[4] == 'I' && currentWord.TabWord[5] == '_'
            && currentWord.TabWord[6] == 'P' && currentWord.TabWord[7] == 'R'
            && currentWord.TabWord[8] == 'O' && currentWord.TabWord[9] == 'F'
            && currentWord.TabWord[10] == 'I' && currentWord.TabWord[11] == 'L'){ //GANTI_PROFIL
                printf("\ngantiprofil\n");
            }

            else if (currentWord.TabWord[0] == 'L' && currentWord.TabWord[1] == 'I'
            && currentWord.TabWord[2] == 'H' && currentWord.TabWord[3] == 'A'
            && currentWord.TabWord[4] == 'T' && currentWord.TabWord[5] == '_'
            && currentWord.TabWord[6] == 'P' && currentWord.TabWord[7] == 'R'
            && currentWord.TabWord[8] == 'O' && currentWord.TabWord[9] == 'F'
            && currentWord.TabWord[10] == 'I' && currentWord.TabWord[11] == 'L'){ //LIHAT_PROFIL
                printf("\nlihatprofil\n");
            }

            else if (currentWord.TabWord[0] == 'A' && currentWord.TabWord[1] == 'T'
            && currentWord.TabWord[2] == 'U' && currentWord.TabWord[3] == 'R'
            && currentWord.TabWord[4] == '_' && currentWord.TabWord[5] == 'J'
            && currentWord.TabWord[6] == 'E' && currentWord.TabWord[7] == 'N'
            && currentWord.TabWord[8] == 'I' && currentWord.TabWord[9] == 'S'
            && currentWord.TabWord[10] == '_' && currentWord.TabWord[11] == 'A'
            && currentWord.TabWord[12] == 'K' && currentWord.TabWord[13] == 'U'
            && currentWord.TabWord[14] == 'N'){ //ATUR_JENIS_AKUN
                printf("\njenisakun\n");
            }

            else if (currentWord.TabWord[0] == 'U' && currentWord.TabWord[1] == 'B'
            && currentWord.TabWord[2] == 'A' && currentWord.TabWord[3] == 'H'
            && currentWord.TabWord[4] == '_' && currentWord.TabWord[5] == 'F'
            && currentWord.TabWord[6] == 'O' && currentWord.TabWord[7] == 'T'
            && currentWord.TabWord[8] == 'O' && currentWord.TabWord[9] == '_'
            && currentWord.TabWord[10] == 'P' && currentWord.TabWord[11] == 'R'
            && currentWord.TabWord[12] == 'O' && currentWord.TabWord[13] == 'F'
            && currentWord.TabWord[14] == 'I' && currentWord.TabWord[15] == 'L'){ //UBAH_FOTO_PROFIL
                printf("\nUBAHPROFIL\n");
            }

            // BAGIAN PERINTAH (TEMAN)
            else if (currentWord.TabWord[0] == 'D' && currentWord.TabWord[1] == 'A'
            && currentWord.TabWord[2] == 'F' && currentWord.TabWord[3] == 'T'
            && currentWord.TabWord[4] == 'A' && currentWord.TabWord[5] == 'R'
            && currentWord.TabWord[6] == '_' && currentWord.TabWord[7] == 'T'
            && currentWord.TabWord[8] == 'E' && currentWord.TabWord[9] == 'M'
            && currentWord.TabWord[10] == 'A' && currentWord.TabWord[11] == 'N'){ //DAFTAR_TEMAN
                printf("\ndaftarteman\n");
            }

            else if (currentWord.TabWord[0] == 'H' && currentWord.TabWord[1] == 'A'
            && currentWord.TabWord[2] == 'P' && currentWord.TabWord[3] == 'U'
            && currentWord.TabWord[4] == 'S' && currentWord.TabWord[5] == '_' 
            && currentWord.TabWord[6] == 'T' && currentWord.TabWord[7] == 'E' 
            && currentWord.TabWord[8] == 'M' && currentWord.TabWord[9] == 'A' 
            && currentWord.TabWord[10] == 'N'){ //HAPUS_TEMAN
                printf("\nHAPUSteman\n");
            }

            // BAGIAN PERINTAH (PERMINTAAN TEMAN)
            else if (currentWord.TabWord[0] == 'T' && currentWord.TabWord[1] == 'A'
            && currentWord.TabWord[2] == 'M' && currentWord.TabWord[3] == 'B'
            && currentWord.TabWord[4] == 'A' && currentWord.TabWord[5] == 'H'
            && currentWord.TabWord[6] == '_' && currentWord.TabWord[7] == 'T'
            && currentWord.TabWord[8] == 'E' && currentWord.TabWord[9] == 'M'
            && currentWord.TabWord[10] == 'A' && currentWord.TabWord[11] == 'N'){ //TAMBAH_TEMAN
                printf("\nTAMBAHTEMAN\n");
            }

            else if (currentWord.TabWord[0] == 'D' && currentWord.TabWord[1] == 'A'
            && currentWord.TabWord[2] == 'F' && currentWord.TabWord[3] == 'T'
            && currentWord.TabWord[4] == 'A' && currentWord.TabWord[5] == 'R'
            && currentWord.TabWord[6] == '_' && currentWord.TabWord[7] == 'P'
            && currentWord.TabWord[8] == 'E' && currentWord.TabWord[9] == 'R'
            && currentWord.TabWord[10] == 'M' && currentWord.TabWord[11] == 'I'
            && currentWord.TabWord[12] == 'N' && currentWord.TabWord[13] == 'T'
            && currentWord.TabWord[14] == 'A' && currentWord.TabWord[15] == 'A'
            && currentWord.TabWord[16] == 'N' && currentWord.TabWord[17] == '_'
            && currentWord.TabWord[18] == 'T' && currentWord.TabWord[19] == 'E'
            && currentWord.TabWord[20] == 'M' && currentWord.TabWord[21] == 'A'
            && currentWord.TabWord[22] == 'N'){ //DAFTAR_PERMINTAAN
                printf("\nLISTteman\n");
            }
            else if (currentWord.TabWord[0] == 'S' && currentWord.TabWord[1] == 'E'
            && currentWord.TabWord[2] == 'T' && currentWord.TabWord[3] == 'U'
            && currentWord.TabWord[4] == 'J' && currentWord.TabWord[5] == 'U'
            && currentWord.TabWord[6] == 'I' && currentWord.TabWord[7] == '_'
            && currentWord.TabWord[8] == 'P' && currentWord.TabWord[9] == 'E'
            && currentWord.TabWord[10] == 'R' && currentWord.TabWord[11] == 'T'
            && currentWord.TabWord[12] == 'E' && currentWord.TabWord[13] == 'M'
            && currentWord.TabWord[14] == 'A' && currentWord.TabWord[15] == 'N'
            && currentWord.TabWord[16] == 'A' && currentWord.TabWord[17] == 'N'){ //SETUJUI_PERTEMANAN
                printf("\nSETUJUteman\n");
            }

            // BAGIAN PERINTAH (KICAUAN)
            else if (currentWord.TabWord[0] == 'K' && currentWord.TabWord[1] == 'I'
            && currentWord.TabWord[2] == 'C' && currentWord.TabWord[3] == 'A'
            && currentWord.TabWord[4] == 'U' && currentWord.Length==5){ //KICAU
                printf("\nKICAU\n");
            }

            else if (currentWord.TabWord[0] == 'K' && currentWord.TabWord[1] == 'I'
            && currentWord.TabWord[2] == 'C' && currentWord.TabWord[3] == 'A'
            && currentWord.TabWord[4] == 'U' && currentWord.TabWord[5] == 'A'
            && currentWord.TabWord[6] == 'N'){ //KICAUAN
                printf("\nKICAUAN\n");
            }

            else if (currentWord.TabWord[0] == 'S' && currentWord.TabWord[1] == 'U'
            && currentWord.TabWord[2] == 'K' && currentWord.TabWord[3] == 'A'
            && currentWord.TabWord[4] == '_' && currentWord.TabWord[5] == 'K'
            && currentWord.TabWord[6] == 'I' && currentWord.TabWord[7] == 'C'
            && currentWord.TabWord[8] == 'A' && currentWord.TabWord[9] == 'U'
            && currentWord.TabWord[10] == 'A' && currentWord.TabWord[11] == 'N'){ //SUKA_KICAUAN
                printf("\nSUKAKICAU\n");
            }
            else if (currentWord.TabWord[0] == 'U' && currentWord.TabWord[1] == 'B'
            && currentWord.TabWord[2] == 'A' && currentWord.TabWord[3] == 'H'
            && currentWord.TabWord[4] == '_' && currentWord.TabWord[5] == 'K'
            && currentWord.TabWord[6] == 'I' && currentWord.TabWord[7] == 'C'
            && currentWord.TabWord[8] == 'A' && currentWord.TabWord[9] == 'U'
            && currentWord.TabWord[10] == 'A' && currentWord.TabWord[11] == 'N'){ //UBAH_KICAUAN
                printf("\nUBAHKICAU\n");
            }

            // BAGIAN PERINTAH (BALASAN)
            else if (currentWord.TabWord[0] == 'B' && currentWord.TabWord[1] == 'A'
            && currentWord.TabWord[2] == 'L' && currentWord.TabWord[3] == 'A'
            && currentWord.TabWord[4] == 'S' && currentWord.Length==5){ //BALAS
                printf("\nBALAS\n");
            }

            else if (currentWord.TabWord[0] == 'B' && currentWord.TabWord[1] == 'A'
            && currentWord.TabWord[2] == 'L' && currentWord.TabWord[3] == 'A'
            && currentWord.TabWord[4] == 'S' && currentWord.TabWord[5] == 'A'
            && currentWord.TabWord[6] == 'N'){ //BALASAN
                printf("\nBALASAN\n");
            }

            else if (currentWord.TabWord[0] == 'H' && currentWord.TabWord[1] == 'A'
            && currentWord.TabWord[2] == 'P' && currentWord.TabWord[3] == 'U'
            && currentWord.TabWord[4] == 'S' && currentWord.TabWord[5] == '_'
            && currentWord.TabWord[6] == 'B' && currentWord.TabWord[7] == 'A'
            && currentWord.TabWord[8] == 'L' && currentWord.TabWord[9] == 'A'
            && currentWord.TabWord[10] == 'S' && currentWord.TabWord[11] == 'A'
            && currentWord.TabWord[12] == 'N'){ //HAPUSBALAS
                printf("\nHAPUSBALASAN\n");
            }

            // BAGIAN PERINTAH (DRAF KICAUAN)
            else if (currentWord.TabWord[0] == 'B' && currentWord.TabWord[1] == 'U'
            && currentWord.TabWord[2] == 'A' && currentWord.TabWord[3] == 'T'
            && currentWord.TabWord[4] == '_' && currentWord.TabWord[5] == 'D'
            && currentWord.TabWord[6] == 'R' && currentWord.TabWord[7] == 'A'
            && currentWord.TabWord[8] == 'F'){ //BUAT_DRAF
                printf("\nBUATDRAF\n");
            }
            else if (currentWord.TabWord[0] == 'L' && currentWord.TabWord[1] == 'I'
            && currentWord.TabWord[2] == 'H' && currentWord.TabWord[3] == 'A'
            && currentWord.TabWord[4] == 'T' && currentWord.TabWord[5] == '_' 
            && currentWord.TabWord[6] == 'D' && currentWord.TabWord[7] == 'R' 
            && currentWord.TabWord[8] == 'A' && currentWord.TabWord[9] == 'F'){ //LIHAT_DRAF
                printf("\nLIHATDRAF\n");
            }

            // BAGIAN PERINTAH (UTAS)
            else if (currentWord.TabWord[0] == 'U' && currentWord.TabWord[1] == 'T'
            && currentWord.TabWord[2] == 'A' && currentWord.TabWord[3] == 'S'
            && currentWord.Length==4){ //UTAS
                printf("\nUTAS\n");
            }

            else if (currentWord.TabWord[0] == 'S' && currentWord.TabWord[1] == 'A'
            && currentWord.TabWord[2] == 'M' && currentWord.TabWord[3] == 'B'
            && currentWord.TabWord[4] == 'U' && currentWord.TabWord[5] == 'N'
            && currentWord.TabWord[6] == 'G' && currentWord.TabWord[7] == '_'
            && currentWord.TabWord[8] == 'U' && currentWord.TabWord[9] == 'T'
            && currentWord.TabWord[10] == 'A' && currentWord.TabWord[11] == 'S'){ //SAMBUNG_UTAS
                printf("\nSAMBUNGUTAS\n");
            }

            else if (currentWord.TabWord[0] == 'H' && currentWord.TabWord[1] == 'A'
            && currentWord.TabWord[2] == 'P' && currentWord.TabWord[3] == 'U'
            && currentWord.TabWord[4] == 'S' && currentWord.TabWord[5] == '_'
            && currentWord.TabWord[6] == 'U' && currentWord.TabWord[7] == 'T'
            && currentWord.TabWord[8] == 'A' && currentWord.TabWord[9] == 'S'){ //HAPUS_UTAS
                printf("\nHAPUSUTAS\n");
            }

            else if (currentWord.TabWord[0] == 'C' && currentWord.TabWord[1] == 'E'
            && currentWord.TabWord[2] == 'T' && currentWord.TabWord[3] == 'A'
            && currentWord.TabWord[4] == 'K' && currentWord.TabWord[5] == '_'
            && currentWord.TabWord[6] == 'U' && currentWord.TabWord[7] == 'T'
            && currentWord.TabWord[8] == 'A' && currentWord.TabWord[9] == 'S'){ //CETAK_UTAS
                printf("\nCETAKUTAS\n");
            }

            // BAGIAN PERINTAH (SIMPAN & MUAT)
            else if (currentWord.TabWord[0] == 'S' && currentWord.TabWord[1] == 'I'
            && currentWord.TabWord[2] == 'M' && currentWord.TabWord[3] == 'P'
            && currentWord.TabWord[4] == 'A' && currentWord.TabWord[5] == 'N'
            && currentWord.Length==6){ //SIMPAN
                printf("\nSIMPAN\n");
            }

            else if (currentWord.TabWord[0] == 'M' && currentWord.TabWord[1] == 'U'
            && currentWord.TabWord[2] == 'A' && currentWord.TabWord[3] == 'T'
            && currentWord.Length==4){ //MUAT
                printf("\nMUAT\n");
            }

            ADVWORD();
        }
        // printf("ter:%s\n",Terminal.TabWord);
        // printf("cr:%s\n",currentWord.TabWord);
    }

    return 0;
}

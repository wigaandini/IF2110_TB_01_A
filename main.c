#include <stdio.h>
#include <stdlib.h>
#include "program/user.c"
#include "program/profil.c"
#include "program/utas.c"
#include "program/draf_fitur.c"
#include "program/kicauan.c"
#include "program/fyb.c"
#include "program/muatsimpan.c"
#include "program/friend.c"
#include <sys/stat.h>

// gcc main.c adt/configmachine.c adt/charmachine.c adt/liststatikuser.c adt/listdin.c adt/Matrix.c adt/friendmatrix.c adt/pcolor.c adt/prioreqfollinked.c adt/listdinkicauan.c adt/datetime.c adt/time.c adt/wordmachine.c -o tes

int main(){
    ListStatikUser l;
    ListKicauan listKicau;
    FriendMatrix F;
    int idUtas;

    int curIdBalasan = 0;

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

    CreateListGlobalKicauan(&listKicau, CAPACITYMAXLISTKICAUAN);

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
            //printFile(fullPath);
            //return 0;
            ReadUser(&l,&F,fullPath);

            

            ReadKicauan(&listKicau,l,F,fullPath);
            readbalasan(&l,&listKicau,fullPath, &curIdBalasan);
            ReadDraf(&l,fullPath);
            ReadUtas(&listKicau,l,fullPath);

            //printListofUser(l);
            //DisplayAllKicauan(l,listKicau);
            //displaySemuaBalasan(listKicau.buffer[3].balasan, &F, &l, 3, 0);
            //printf("\n");
            printf("\nFile konfigurasi berhasil dimuat! Selamat berkicau!\n");
            jalan=true; 
        }
        
    } while (!is_directory(fullPath));
    free(dirName);

    if (jalan)
    {
        boolean selesai=false, isLoggedIn=false;
        int id_login=-1;        // id_login = -1 berarti belum login. id_login yang digunakan [1..banyakUser]
        Word w, command, kata;
        int idKicauan, indexUtas;
        ListLinierUtas listUtas;
        UtasType u;
        Kicauan tweet;
        while (!selesai){
            printf("\n>> ");
            STARTSENTENCE();
            command = currentWord;
            if(countWords(command) == 1){
                kata = command;
            }
            else{
                kata = splitCommand(&w, command, 1);
            }
            boolean benar = false;
            while(!benar){
                if ((compareString(kata,"LIHAT_PROFIL")||compareString(kata,"GANTI_PROFIL")||
                compareString(kata,"ATUR_JENIS_AKUN")||compareString(kata,"UBAH_FOTO_PROFIL")||
                compareString(kata,"DAFTAR_TEMAN")||compareString(kata,"HAPUS_TEMAN")||
                compareString(kata,"TAMBAH_TEMAN")||compareString(kata,"DAFTAR_PERMINTAAN_PERTEMANAN")||
                compareString(kata,"SETUJUI_PERTEMANAN")||compareString(kata,"KICAU")||
                compareString(kata,"KICAUAN")||
                compareString(kata,"BUAT_DRAF")||compareString(kata,"LIHAT_DRAF")||
                compareString(kata,"FYB")||compareString(kata,"MASUK")||compareString(kata,"KELUAR")||compareString(kata,"TUTUP_PROGRAM")||compareString(kata,"DAFTAR")||compareString(kata, "CETAK_UTAS"))&&
                countWords(command)!=1){
                printf("Masukan tidak valid. Harap input kembali dengan format yang benar. \n\n");
                printf(">> ");
                STARTSENTENCE();
                command = currentWord;
                kata = splitCommand(&w, command, 1);
                }
                else if((compareString(kata,"SUKA_KICAUAN")||compareString(kata,"UBAH_KICAUAN")||compareString(kata,"BALASAN")||compareString(kata,"UTAS")||compareString(kata,"CETAK_UTAS")) && countWords(currentWord) != 2){
                    printf("Masukan tidak valid. Harap input kembali dengan format yang benar.\n\n");
                    printf(">> ");
                    STARTSENTENCE();
                    command = currentWord;
                    kata = splitCommand(&w, command, 1);
                }
                else if((compareString(kata, "BALAS")||compareString(kata, "HAPUS_BALASAN")||compareString(kata, "SAMBUNG_UTAS")||compareString(kata, "HAPUS_UTAS")) && countWords(currentWord) != 3){
                    printf("Masukan tidak valid. Harap input kembali dengan format yang benar.\n\n");
                    printf(">> ");
                    STARTSENTENCE();
                    command = currentWord;
                    kata = splitCommand(&w, command, 1);
                }
                else{
                    benar = true;
                }
            }
        // BAGIAN PERINTAH (PENGGUNA)
        
        if (compareString(kata,"DAFTAR")){ //DAFTAR
            DAFTAR(&l,&F ,isLoggedIn);
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
            selesai=true;
        }

        else if((compareString(kata,"LIHAT_PROFIL")||compareString(kata,"GANTI_PROFIL")||
        compareString(kata,"ATUR_JENIS_AKUN")||compareString(kata,"UBAH_FOTO_PROFIL")||
        compareString(kata,"DAFTAR_TEMAN")||compareString(kata,"HAPUS_TEMAN")||
        compareString(kata,"TAMBAH_TEMAN")||compareString(kata,"DAFTAR_PERMINTAAN_PERTEMANAN")||
        compareString(kata,"SETUJUI_PERTEMANAN")||compareString(kata,"KICAU")||
        compareString(kata,"KICAUAN")||compareString(kata,"SUKA_KICAUAN")||
        compareString(kata,"UBAH_KICAUAN")||compareString(kata,"BALAS")||
        compareString(kata,"BALASAN")||compareString(kata,"HAPUS_BALASAN")||
        compareString(kata,"BUAT_DRAF")||compareString(kata,"LIHAT_DRAF")||
        compareString(kata,"UTAS")||compareString(kata,"SAMBUNG_UTAS")||
        compareString(kata,"HAPUS_UTAS")||compareString(kata,"CETAK_UTAS")||
        compareString(kata,"FYB")) && 
        !isLoggedIn){
            printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan Burbir.\n\n");
        }

        // BAGIAN PERINTAH (PROFIL)
        else if (compareString(kata,"GANTI_PROFIL")&&isLoggedIn){ //GANTI_PROFIL
            ganti_profil(&l, id_login);
        }

        else if (compareString(kata,"LIHAT_PROFIL")&&isLoggedIn){ //LIHAT_PROFIL
            // Ambil Word nama dari command dan asumsikan masukkan command selalu benar sesuai struktur: LIHAT_PROFIL <nama>
            Word nama;
            int firstIDX = 0;
            for (int i=13; i<command.Length; i++){      // Mencari indeks command pertama dari nama. Misal LIHAT_PROFIL Farel, maka firstIDX = 13
                if (command.TabWord[i] != ' '){
                    firstIDX = i;
                    break;
                }
            }
            nama.Length = command.Length - firstIDX;
            for (int i=0; i<nama.Length; i++) {
                nama.TabWord[i] = command.TabWord[firstIDX+i];
            }
            lihat_profil(l, nama, isLoggedIn);
        }

        else if (compareString(kata,"ATUR_JENIS_AKUN")&&isLoggedIn){ //ATUR_JENIS_AKUN
            atur_jenis_akun(&l, id_login, isLoggedIn);
        }

        else if (compareString(kata,"UBAH_FOTO_PROFIL")&&isLoggedIn){ //UBAH_FOTO_PROFIL
            ubah_foto_profil(&l, id_login);
        }

        // BAGIAN PERINTAH (TEMAN)
        else if (compareString(kata,"DAFTAR_TEMAN")&&isLoggedIn){ //DAFTAR_TEMAN
            DAFTAR_TEMAN(id_login, l,F);
        }

        else if (compareString(kata,"HAPUS_TEMAN")&&isLoggedIn){ //HAPUS_TEMAN
            HAPUS_TEMAN(id_login, l, &F);
        }

        // BAGIAN PERINTAH (PERMINTAAN TEMAN)
        else if (compareString(kata,"TAMBAH_TEMAN")&&isLoggedIn){ //TAMBAH_TEMAN
            TAMBAH_TEMAN(id_login, &l, F, l.data[id_login-1].userReq);
        }

        else if (compareString(kata,"DAFTAR_PERMINTAAN_PERTEMANAN")&&isLoggedIn){ //DAFTAR_PERMINTAAN
            DAFTAR_PERMINTAAN_PERTEMANAN(id_login, F, l.data[id_login-1].userReq, l);
        }
        else if (compareString(kata,"SETUJUI_PERTEMANAN")&&isLoggedIn){ //SETUJUI_PERTEMANAN
            SETUJUI_PERTEMANAN(id_login, &F, &(l.data[id_login-1].userReq), l);
        }

        // BAGIAN PERINTAH (KICAUAN)
        else if (compareString(kata,"KICAU")&&isLoggedIn){ //KICAU
            Berkicau(l, &listKicau, &tweet, id_login);
        }

        else if (compareString(kata,"KICAUAN")&&isLoggedIn){ //KICAUAN
            DisplayKicauan(l, listKicau, id_login, F);
        }

        else if (compareString(kata,"SUKA_KICAUAN")&&isLoggedIn){ //SUKA_KICAUAN
            idKicauan = WordToInt(splitCommand(&w, command, 2));
            SUKA_KICAUAN(l, &listKicau, idKicauan, id_login, F);
        }
        else if (compareString(kata,"UBAH_KICAUAN")&&isLoggedIn){ //UBAH_KICAUAN
            idKicauan = WordToInt(splitCommand(&w, command, 2));
            UBAH_KICAUAN(l, &listKicau, idKicauan, id_login);
        }

        // BAGIAN PERINTAH (BALASAN)
        else if (compareString(kata,"BALAS")&&isLoggedIn){ //BALAS
            int idKicauanBalas = WordToInt(splitCommand(&w, command, 2));
            int idBalasanBalas;
            readOneNum(&idBalasanBalas, splitCommand(&w, command, 3));

            BALAS(&listKicau, &F, &l, idKicauanBalas, idBalasanBalas, id_login, &curIdBalasan);
            //printf("\nBALAS\n");
        }

        else if (compareString(kata,"BALASAN")&&isLoggedIn){ //BALASAN
            int idBalasanBalas = WordToInt(splitCommand(&w, command, 2));
            
            BALASAN(&listKicau, &F, &l, idBalasanBalas, id_login);
        }

        else if (compareString(kata,"HAPUS_BALASAN")&&isLoggedIn){ //HAPUSBALAS
            int idKicauanBalas = WordToInt(splitCommand(&w, command, 2));
            int idBalasanBalas = WordToInt(splitCommand(&w, command, 3));

            HAPUS_BALASAN(&listKicau, id_login, idKicauanBalas, idBalasanBalas);
            //printf("\nHAPUSBALASAN\n");
        }

        // BAGIAN PERINTAH (DRAF KICAUAN)
        else if (compareString(kata,"BUAT_DRAF")&&isLoggedIn){ //BUAT_DRAF
            BUAT_DRAF(&l,&listKicau,id_login);
        }
        else if (compareString(kata,"LIHAT_DRAF")&&isLoggedIn){ //LIHAT_DRAF
            LIHAT_DRAF(&l,&listKicau,id_login);
        }

        // BAGIAN PERINTAH (UTAS)
        else if (compareString(kata,"UTAS")&&isLoggedIn){ //UTAS
            printf("count utas : %d\n", countTypeUtas(listKicau));
            idKicauan = WordToInt(splitCommand(&w, command, 2));
            BIKIN_UTAS(idKicauan, &listKicau, &listUtas, id_login, &u);
            idUtas = idUtas(INFOUtas(ADDRESSUTAS(ELMTLISTKICAU(listKicau, idKicauan-1))));
            printf("id utas : %d\n", idUtas);
            printf("count utas : %d\n", countTypeUtas(listKicau));
            // idUtas ++;
        }

        else if (compareString(kata,"SAMBUNG_UTAS")&&isLoggedIn){ //SAMBUNG_UTAS
            idUtas = WordToInt(splitCommand(&w, command, 2));
            indexUtas = WordToInt(splitCommand(&w, command, 3));
            SAMBUNG_UTAS(idUtas, indexUtas, &listUtas, id_login, &u, listKicau);
        }

        else if (compareString(kata,"HAPUS_UTAS")&&isLoggedIn){ //HAPUS_UTAS
            idUtas = WordToInt(splitCommand(&w, command, 2));
            indexUtas = WordToInt(splitCommand(&w, command, 3));
            HAPUS_UTAS(idUtas, indexUtas, &listUtas, id_login, &u, listKicau);
        }

        else if (compareString(kata,"CETAK_UTAS")&&isLoggedIn){ //CETAK_UTAS
            idUtas = WordToInt(splitCommand(&w, command, 2));
            printf("id utas : %d\n", idUtas);
            printf("id kicau %d\n", searchIdKicau(idUtas, listKicau));
            CETAK_UTAS(l, listUtas, id_login, idUtas, listKicau);
        }

        // BAGIAN PERINTAH (SIMPAN & MUAT)
        else if (compareString(kata,"SIMPAN")){ //SIMPAN
            SIMPAN(l,listKicau,F);
        }

        else if (compareString(kata,"MUAT")){ //MUAT
            if (!isLoggedIn){
                MUAT(&l,&listKicau,&F, &curIdBalasan);
            } else{
                printf("\nAnda harus keluar terlebih dahulu untuk melakukan pemuatan.\n");
            }
        }

        // BAGIAN PERINTAH BONUSSSSS KIW KIW CUKURUKUK
        else if (compareString(kata,"FYB")) {   // FYB
            fyb(l, listKicau);
        }

        ADVWORD();
        // }
        // printf("ter:%s\n",Terminal.TabWord);
        // printf("cr:%s\n",currentWord.TabWord);
    }
    }
    
    return 0;
}
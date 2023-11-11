#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header/boolean.h"
#include "header/listdin.h"
#include "header/charmachine.h"
#include "header/wordmachine.h"
#include "header/time.h"
#include "header/datetime.h"
#include "header/adtkicauan.h"

void CreateKicauan(Kicauan *k, int id, String text, int like, int idauthor, DATETIME waktu){
    ID(*k) = id;
    TEXT(*k) = text;
    LIKE(*k) = 0;
    IDAUTHOR(*k) = like;
    WAKTU(*k) = waktu;
    UTAS(*k) = NULL;
    //BALASAN(*k) = 0;
}

void DisplaySatuKicau(Kicauan k){
    printf("| ID = %d\n", ID(k));
    //printf("| %s", getauthornamefromidauthor);
    TulisDATETIME(WAKTU(k));
    printf("\n");

    printf("| ");
    //bikin displayString untuk text
    printf("| Disukai: %d\n", LIKE(k));
}

void KICAU(Kicauan *k){
    int id, idauthor;
    DATETIME waktu;
    String text;
    //id dilihat dari data id yang sudah ada di konfigurasi
    //fread(config/kicauan.config);  cara ngambil dari filenya gimana ya? apakah mau spesifik berulang untuk baris dengan pola sekian untuk id kicauan
    //id = baris sekian dari config yang menyatakan id kicauan

    //idauthor  = diambil dari data pengguna yang sedang masuk
    //waktu = baca waktu pake library time

    printf("Masukkan kicauan :\n");
    //bikin readString untuk terima input text
    //bikin kondisi kalau diterima inputnya hanya spasi lalu tbtb diakhiri mark untuk tidak valid dan diulang lagi

    /*if(isFull(text)){
        text = hasil input yang diassign tapi cuma sampe karakter ke-280;
    }*/ 
  
    CreateKicauan(k, id, text, 0, idauthor, waktu);

    //bikin getAuthorNamefromID buat ngedisplay nama author dari data id

    printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
    DisplayKicau(*k);
}

void DisplayKicauan(){
   //ngestore list seluruh kicauan kan pake prioqueue time based,
   //bikin mekanisme print seluruh isi kicauan.config dengan kondisi
   //jika nilai pertemanan idauthor adalah true dengan idauthor yang sudah
   //melakukan kicauan atau bila idauthor kicauan akunnya bersifat publik, kicauan didisplay
}

boolean isKicauFull(String text){
    /* Mengirimkan true jika text kicauan penuh, yaitu jika panjang string mencapai 280,
    mengirimkan false jika tidak penuh*/
}

void SUKA_KICAUAN(Kicauan *k){
    /*jumlah like dari suatu kicauan diincrement jika kicauan valid dan isBerteman dengan idauthor
    bernilai true atau idauthor publik*/
}

void UBAH_KICAUAN(Kicauan *k){
    /*Isi text kicauan berubah sesuai dengan perubahan yang dilakukan pengguna*/
}
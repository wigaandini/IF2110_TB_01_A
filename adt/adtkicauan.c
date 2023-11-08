#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header/boolean.h"
#include "header/charmachine.h"
#include "header/wordmachine.h"
#include "header/time.h"
#include "header/datetime.h"
#include "header/adtkicauan.h"
#include "header/string.h"
#include "header/friendmatrix.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */

/* *** Konstruktor: Membentuk sebuah  List Kicauan dari komponen-komponennya *** */

void CreateListGlobalKicauan(ListKicauan *l, int capacity){
    /* Menyimpan seluruh kicauan yang telah dibuat */
    /* Prekondisi : list kosong */

    BUFFERLISTKICAU(*l) = (Kicauan*) malloc(capacity*sizeof(Kicauan));
    CAPACITYKICAU(*l) = CAPACITYMAXLISTKICAUAN;
    NEFFLISTKICAU(*l) = 0;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdKicauanValid(ListKicauan l, int id){
    /* Mengirimkan true jika id adalah indeks yang valid utk kapasitas list l */
    /* yaitu antara indeks yang terdefinisi utk container*/

    return(id <= NEFFLISTKICAU(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListKicauanEmpty(ListKicauan l){
    return(NEFFLISTKICAU(l)==0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */

/* Mengirimkan true jika list l setengah penuh, mengirimkan false jika tidak */
boolean isListKicauanFull(ListKicauan l){
    return(NEFFLISTKICAU(l)==CAPACITYKICAU(l));
}

/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
void dealocateListKicauan(ListKicauan *l){
    free(BUFFERLISTKICAU(*l));
    CAPACITYKICAU(*l) = 0;
    NEFFLISTKICAU(*l) = 0;
}

/* ********** OPERASI LAIN ********** */
void copyListKicau(ListKicauan lIn, ListKicauan *lOut){
    IdxType i;
    dealocateListKicauan(lOut);
    CreateListGlobalKicauan(lOut, CAPACITYKICAU(lIn));

    for(i=0; i<NEFFLISTKICAU(lIn); i++){
        ELMTLISTKICAU(*lOut, i) = ELMTLISTKICAU(lIn, i);
    }

    NEFFLISTKICAU(*lOut) = NEFFLISTKICAU(lIn);
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListKicau(ListKicauan *l, int num){
    ListKicauan new;
    int newNEFF;
    IdxType i;

    CreateListGlobalKicauan(&new, CAPACITYKICAU(*l));
    copyListKicau(*l,&new);
    newNEFF = NEFFLISTKICAU(*l);
    dealocateListKicauan(l);
    CreateListGlobalKicauan(l, CAPACITYKICAU(new)+num);
    NEFFLISTKICAU(*l) = newNEFF;

    for(i=0; i<newNEFF; i++){
        ELMTLISTKICAU(*l,i) = ELMTLISTKICAU(new,i);
    }
}

IdxType getLastIdxKicau(ListKicauan l){
    return NEFFLISTKICAU(l)-1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* *** Menambahkan elemen terakhir *** */
void insertLastKicauan(ListKicauan *l, Kicauan val){
    if (NEFFLISTKICAU(*l)+1 > 3*CAPACITYKICAU(*l)/4) {  // Di modifikasi agar capacity otomatis langsung menyesuaikan dengan jumlah elemen
        expandListKicau(l, CAPACITYKICAU(*l));    // Capacity dikali 2
    }
    ELMTLISTKICAU(*l, getLastIdxKicau(*l)+1) = val;
    NEFFLISTKICAU(*l) ++;
}

void CreateKicauan(Kicauan *k, int id, String text, int idauthor, DATETIME waktu){
    ID(*k) = id;
    TEXT(*k) = text;
    LIKE(*k) = 0;
    IDAUTHOR(*k) = idauthor;
    WAKTU(*k) = waktu;
    UTAS(*k) = NULL;
    //CreateListBalasan(l,...)
}

void DisplaySatuKicau(Kicauan k){
    printf("| ID = %d\n", ID(k));
    printf("| Nama author dengan ID %d\n", IDAUTHOR(k));
    printf("| ");
    TulisDATETIME(WAKTU(k));
    printf("\n");
    printf("| ");
    displayString(TEXT(k));
    printf("\n");
    printf("| Disukai: %d\n", LIKE(k));
    printf("\n");
}

void Berkicau(ListKicauan *l, Kicauan *k, int idauthor){
    char c;
    int id;
    DATETIME waktu;
    String text;

    id = NEFFLISTKICAU(*l) + 1;

    time_t current_time;
    time(&current_time);
    current_time+=3600*7;

    struct tm* timeinfo = gmtime(&current_time);

    Year(waktu) = 1900 + timeinfo->tm_year;
    Month(waktu) = timeinfo->tm_mon + 1;
    Day(waktu) = timeinfo->tm_mday;
    Time(waktu)=DetikToTIME(current_time);

    printf("Masukkan kicauan :\n");
    readString(&text);
    //bikin kondisi kalau diterima inputnya hanya spasi lalu tbtb diakhiri mark untuk tidak valid dan diulang lagi
    while(text.length>280){
        deleteSLast(&text, &c);
    }

    CreateKicauan(k, id, text, idauthor, waktu);
    //bikin getAuthorNamefromID buat ngedisplay nama author dari data id

    printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
    DisplaySatuKicau(*k);
    insertLastKicauan(l, *k);
}

void DisplayKicauan(ListStatikUser l, ListKicauan k, int idUser, FriendMatrix m){
    int idAuthor;
    for(int i= NEFFLISTKICAU(k) - 1 ; i>=0; i--){
            idAuthor = IDAUTHOR(ELMTLISTKICAU(k, i));
            if(idAuthor == idUser){
                DisplaySatuKicau(ELMTLISTKICAU(k, i));
            } // else {
            //     if(isFriend(m, idAuthor, idUser)){
            //         DisplaySatuKicau(ELMTLISTKICAU(k, i));
            //     }
            // } 
    }
}

void SUKA_KICAUAN(ListStatikUser l, ListKicauan *k, int idKicauan, int idUser, FriendMatrix m){
    if(!isIdKicauanValid(*k, idKicauan)){
        printf("Tidak ditemukan kicauan dengan ID = %d\n", idKicauan);
    } else {
        int idAuthor = IDAUTHOR(ELMTLISTKICAU(*k, idKicauan-1));
        // if(UserTipe(l, idAuthor-1) == PUBLIK){
        //     LIKE(ELMTLISTKICAU(*k, idKicauan))++;
        // }  else {
            if(idAuthor == idUser){
                LIKE(ELMTLISTKICAU(*k, idKicauan-1))++;
            } // else {
            //     if(isFriend(m, idAuthor, idUser)){
            //         LIKE(ELMTLISTKICAU(*k, idKicauan-1))++;
            //     } else {
            //         printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
            //     }
            // }
        // }
    }
    DisplaySatuKicau(ELMTLISTKICAU(*k,idKicauan-1));
}

void UBAH_KICAUAN(ListStatikUser l, ListKicauan *k, int idKicauan, int idUser){
    String newText;

    if(isIdKicauanValid(*k, idKicauan)){
        int idAuthor = IDAUTHOR(ELMTLISTKICAU(*k, idKicauan-1));
        if (idAuthor == idUser) {
            printf("Masukkan kicauan baru : \n");
            readString(&newText);
            TEXT(ELMTLISTKICAU(*k,idKicauan-1)) = newText;
            DisplaySatuKicau(ELMTLISTKICAU(*k, idKicauan-1));
        } else {
            printf("Kicauan dengan ID = %d bukan milikmu!\n", idKicauan);
        }
    } else {
        printf("Tidak ditemukan kicauan dengan ID = %d!\n", idKicauan);
    }
}
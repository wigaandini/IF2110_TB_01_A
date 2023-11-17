#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header/boolean.h"
#include "header/charmachine.h"
#include "header/wordmachine.h"
#include "header/time.h"
#include "header/datetime.h"
#include "header/listdinkicauan.h"
#include "header/friendmatrix.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */

/* *** Konstruktor: Membentuk sebuah  List Kicauan dari komponen-komponennya *** */

void CreateListGlobalKicauan(ListKicauan *l, int capacity){
    /* Menyimpan seluruh kicauan yang telah dibuat */
    /* Prekondisi : list kosong */

    BUFFERLISTKICAU(*l) = (Kicauan*)malloc(capacity*sizeof(Kicauan));
    CAPACITYKICAU(*l) = CAPACITYMAXLISTKICAUAN;
    NEFFLISTKICAU(*l) = 0;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdKicauanValid(ListKicauan l, int id){
    return(id <= NEFFLISTKICAU(l));
}
/* Mengirimkan true jika id adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListKicauanEmpty(ListKicauan l){
    return(NEFFLISTKICAU(l) == 0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */

/* Mengirimkan true jika list l setengah penuh, mengirimkan false jika tidak */
boolean isListKicauanFull(ListKicauan l){
    return(NEFFLISTKICAU(l) == CAPACITYKICAU(l));
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

    for(i = 0; i < NEFFLISTKICAU(lIn); i++){
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

    for(i = 0; i < newNEFF; i++){
        ELMTLISTKICAU(*l,i) = ELMTLISTKICAU(new,i);
    }
}

IdxType getLastIdxKicau(ListKicauan l){
    return NEFFLISTKICAU(l) - 1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* *** Menambahkan elemen terakhir *** */
void insertLastKicauan(ListKicauan *l, Kicauan val){
    if (NEFFLISTKICAU(*l) + 1 > 3 * CAPACITYKICAU(*l) / 4) {  // Di modifikasi agar capacity otomatis langsung menyesuaikan dengan jumlah elemen
        expandListKicau(l, CAPACITYKICAU(*l));    // Capacity dikali 2
    }
    ELMTLISTKICAU(*l, getLastIdxKicau(*l)+1) = val;
    NEFFLISTKICAU(*l)++;
}

void CreateKicauan(Kicauan *k, int id, Word text, int idauthor, DATETIME waktu){
    ID(*k) = id;
    TEXT(*k) = text;
    LIKE(*k) = 0;
    IDAUTHOR(*k) = idauthor;
    WAKTU(*k) = waktu;
    UTAS(*k) = NULL;
    BALASAN(*k) = NULL;
}

void DisplaySatuKicau(ListStatikUser l, Kicauan k){
    printf("| ID = %d\n", ID(k));
    printf("| Nama author dengan ID %s\n", l.data[ID(k)].nama);
    printf("| ");
    TulisDATETIME(WAKTU(k));
    printf("\n");
    printf("| ");
    displayWord(TEXT(k));
    printf("\n");
    printf("| Disukai: %d\n", LIKE(k));
    printf("\n");
}

void DisplayAllKicauan(ListStatikUser l, ListKicauan k){
    for (int i = NEFFLISTKICAU(k) - 1 ; i >= 0; i--) {
        DisplaySatuKicau(l, ELMTLISTKICAU(k, i));
    }
}
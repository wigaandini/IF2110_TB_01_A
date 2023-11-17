/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* UtasType adalah struct int, string, datetime*/

#include <stdio.h>
#include <stdlib.h>
#include "header/listlinierutas.h"

Address newNode(UtasType val){
    Address p = (Address) malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}
/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListUtasPers(ListLinierUtas *l){
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

void CreateListUtasGlobal(ListUtas *l, int capacity){
    BUFFERLISTUTAS(*l) = (Kicauan*) malloc(capacity*sizeof(Kicauan));
    CAPACITYUTAS(*l) = CAPACITYMAXLISTUTAS;
    NEFFLISTUTAS(*l) = 0;
}
/* Menyimpan seluruh utas yang telah dibuat */
/* Prekondisi : list kosong */

void CreateUtas(UtasType *u, int idAuthor, int indexUtas, Word text, DATETIME waktu){
    Address p = newNode(*u);
    idAuthor(*u) = idAuthor;
    idxUtas(*u) = indexUtas;
    Text(*u) = text;
    Waktu(*u) = waktu;
    NEXT(p) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk utas dengan elemen yang diinput */

/****************** TEST LIST KOSONG ******************/
boolean isListUtasPersEmpty(ListLinierUtas l){
    return (FIRST(l) == NULL);
}
/* Mengirim true jika list kosong */

boolean isListUtasGlobalEmpty(ListUtas l){
    return(NEFFLISTUTAS(l) == 0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */

boolean isListUtasGlobalFull(ListUtas l){
    return(NEFFLISTUTAS(l) == CAPACITYUTAS(l));
}

void dealocateListUtasGlobal(ListUtas *l){
    free(BUFFERLISTUTAS(*l));
    CAPACITYUTAS(*l) = 0;
    NEFFLISTUTAS(*l) = 0;
}

/********* OPERASI LAIN ***********/
/* ********** OPERASI LAIN ********** */
void copyListUtas(ListUtas lIn, ListUtas *lOut){
    IdxType i;
    dealocateListUtasGlobal(lOut);
    CreateListUtasGlobal(lOut, CAPACITYUTAS(lIn));

    for(i = 0; i < NEFFLISTUTAS(lIn); i++){
        ELMTLISTUTAS(*lOut, i) = ELMTLISTUTAS(lIn, i);
    }

    NEFFLISTUTAS(*lOut) = NEFFLISTUTAS(lIn);
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListUtas(ListUtas *l, int num){
    ListUtas new;
    int newNEFF;
    IdxType i;

    CreateListUtasGlobal(&new, CAPACITYUTAS(*l));
    copyListUtas(*l,&new);
    newNEFF = NEFFLISTUTAS(*l);
    dealocateListUtasGlobal(l);
    CreateListUtasGlobal(l, CAPACITYUTAS(new)+num);
    NEFFLISTUTAS(*l) = newNEFF;

    for(i = 0; i < newNEFF; i++){
        ELMTLISTUTAS(*l,i) = ELMTLISTUTAS(new,i);
    }
}

IdxType getLastIdxUtasGlobal(ListUtas l){
    return NEFFLISTUTAS(l) - 1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* *** Menambahkan elemen terakhir *** */
void insertLastGlobal(ListUtas *l, Kicauan val){
    if (NEFFLISTUTAS(*l) + 1 > 3 * CAPACITYUTAS(*l) / 4) {  // Di modifikasi agar capacity otomatis langsung menyesuaikan dengan jumlah elemen
        expandListUtas(l, CAPACITYUTAS(*l));    // Capacity dikali 2
    }
    ELMTLISTUTAS(*l, getLastIdxUtasGlobal(*l)+1) = val;
    NEFFLISTUTAS(*l)++;
}

/****************** GETTER SETTER ********************/
UtasType getElmtPers(ListLinierUtas l, int idx){
    int i = 0;
    Address p;
    p = FIRST(l);
    while (i < idx){
        i ++;
        p = NEXT(p);
    }
    return INFO(p);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmtPers(ListLinierUtas *l, int idx, UtasType val){
    int i = 0;
    Address p;
    p = FIRST(*l);
    while (i < idx){
        i ++;
        p = NEXT(p);
    }
    INFO(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOfPers(ListLinierUtas l, UtasType val){
    Address p;
    boolean found = false;
    int i = 0;
    p = FIRST(l);
    while (p != NULL && !found){
        if(INFO(p).idAuthor == val.idAuthor && INFO(p).indexUtas == val.indexUtas && compareWord(INFO(p).text, val.text) && INFO(p).waktu.DD == val.waktu.DD && INFO(p).waktu.MM == val.waktu.MM && INFO(p).waktu.YYYY == val.waktu.YYYY && INFO(p).waktu.T.HH == val.waktu.T.HH && INFO(p).waktu.T.MM == val.waktu.T.MM && INFO(p).waktu.T.SS == val.waktu.T.SS){
            found = true;
        }
        else{
            i ++;
            p = NEXT(p);
        }
    }
    if(found){
        return i;
    }
    else{
        return IDXUNDEF;
    }
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDXUNDEF jika tidak ditemukan */

/* ********** Test Indeks yang valid ********** */
boolean isIdUtasGlobalValid(ListUtas l, int id){
    return(id <= NEFFLISTUTAS(l));
}
/* Mengirimkan true jika id adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstPers(ListLinierUtas *l, UtasType val){
    Address p = newNode(val);
    if (p != NULL){
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastPers(ListLinierUtas *l, UtasType val){
    Address p, last;
    if (isListUtasPersEmpty(*l)){
        insertFirstPers(l, val);
    }
    else{
        p = newNode(val);
        if (p != NULL){
            last = FIRST(*l);
            while (NEXT(last) != NULL){
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtPers(ListLinierUtas *l, UtasType val, int idx){
    int i = 0;
    Address p, loc;
    if (idx == 0){
        insertFirstPers(l, val);
    }
    else{
        p = newNode(val);
        if (p != NULL){
            loc = FIRST(*l);
            while (i < idx-1){
                i ++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstPers(ListLinierUtas *l, UtasType *val){
    Address p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastPers(ListLinierUtas *l, UtasType *val){
    Address p, loc;
    p = FIRST(*l);
    loc = NULL;
    while (NEXT(p) != NULL){
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL){
        FIRST(*l) = NULL;
    }
    else{
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAtPers(ListLinierUtas *l, int idx, UtasType *val){
    int i = 0;
    Address p, loc;
    if (idx == 0){
        deleteFirstPers(l, val);
    }
    else{
        loc = FIRST(*l);
        while (i < idx-1){
            i ++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
int length(ListLinierUtas l){
    int count = 0;
    Address p = FIRST(l);
    while (p != NULL){
        count ++;
        p = NEXT(p);
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(ListLinierUtas *l){
    Address p = FIRST(*l);
    UtasType val;
    while(p != NULL){
        deleteFirstPers(l, &val);
        p = NEXT(p);
    }
    *l = NULL;
}
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void copyListUtasPers(ListLinierUtas *l1, ListLinierUtas *l2){
    *l2 = *l1;
    // CreateList(l2);
    // FIRST(*l2) = FIRST(*l1);
}
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

void DisplaySatuUtas(UtasType u, ListStatikUser l){
    printf("    | INDEX = %d\n", idxUtas(u));
    printf("    | ");
    displayString(l.data[idAuthor(u)-1].nama);
    printf("\n    | ");
    TulisDATETIME(Waktu(u));
    printf("\n");
    printf("    | ");
    displayWord(Text(u));
    printf("\n\n");
}

void DisplayUtasPers(ListStatikUser l, ListUtas k, ListLinierUtas u, int idUser, int idUtas){
    int idAuthor;
    Address p = FIRST(u);
    idAuthor = IDAUTHOR(ELMTLISTUTAS(k, idUtas));
    DisplaySatuKicau(l, ELMTLISTUTAS(k, idUtas));
    for (int i = NEFFLISTUTAS(k) - 1 ; i >= 0; i--) {
        if (idAuthor == idUser) {
            DisplaySatuUtas(INFO(p), l);
            p = NEXT(p);
        } else {
            if(UserTipe(l, idAuthor-1) == PUBLIK){
                DisplaySatuUtas(INFO(p), l);
                p = NEXT(p);
            }
        } 
    }
}

int getLastIdxUtasPers(ListLinierUtas l){
    int i = 0;
    Address p;
    p = FIRST(l);
    while (NEXT(p) != NULL){
        i ++;
        p = NEXT(p);
    }
    return idxUtas(INFO(p));
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

boolean isIdxUtasPersValid(ListLinierUtas l, int idx){
    Address p = FIRST(l);
    boolean found = false;
    while(p != NULL && !found){
        if(idxUtas(INFO(p)) == idx){
            found = true;
        }
        else{
            p = NEXT(p);
        }
    }
    return(found);
}
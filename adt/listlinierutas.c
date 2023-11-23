/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* UtasType adalah struct int, string, datetime*/

#include <stdio.h>
#include <stdlib.h>
#include "header/listlinierutas.h"

AddressUtas newNodeUtas(UtasType val){
    AddressUtas p = (AddressUtas) malloc(sizeof(NodeUtas));
    if(p != NULL){
        INFOUtas(p) = val;
        NEXTUtas(p) = NULL;
    }
    return p;
}
/* Definisi List : */
/* List kosong : FIRSTUtas(l) = NULL */
/* Setiap elemen dengan AddressUtas p dapat diacu INFOUtas(p), NEXTUtas(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXTUtas(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListUtasPers(ListLinierUtas *l){
    FIRSTUtas(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

void CreateUtas(UtasType *u, int idAuthor, int indexUtas, Word text, DATETIME waktu, int idUtas){
    AddressUtas p = newNodeUtas(*u);
    idUtas(*u) = idUtas;
    idAuthor(*u) = idAuthor;
    idxUtas(*u) = indexUtas;
    Text(*u) = text;
    Waktu(*u) = waktu;
    NEXTUtas(p) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk utas dengan elemen yang diinput */

/****************** TEST LIST KOSONG ******************/
boolean isListUtasPersEmpty(ListLinierUtas l){
    return (FIRSTUtas(l) == NULL);
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ********************/
UtasType getElmtPers(ListLinierUtas l, int idx){
    int i = 0;
    AddressUtas p;
    p = FIRSTUtas(l);
    while (i < idx){
        i ++;
        p = NEXTUtas(p);
    }
    return INFOUtas(p);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmtPers(ListLinierUtas *l, int idx, UtasType val){
    int i = 0;
    AddressUtas p;
    p = FIRSTUtas(*l);
    while (i < idx){
        i ++;
        p = NEXTUtas(p);
    }
    INFOUtas(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOfPers(ListLinierUtas l, UtasType val){
    AddressUtas p;
    boolean found = false;
    int i = 0;
    p = FIRSTUtas(l);
    while (p != NULL && !found){
        if(INFOUtas(p).idAuthor == val.idAuthor && INFOUtas(p).indexUtas == val.indexUtas && compareWord(INFOUtas(p).text, val.text) && INFOUtas(p).waktu.DD == val.waktu.DD && INFOUtas(p).waktu.MM == val.waktu.MM && INFOUtas(p).waktu.YYYY == val.waktu.YYYY && INFOUtas(p).waktu.T.HH == val.waktu.T.HH && INFOUtas(p).waktu.T.MM == val.waktu.T.MM && INFOUtas(p).waktu.T.SS == val.waktu.T.SS){
            found = true;
        }
        else{
            i ++;
            p = NEXTUtas(p);
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
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstPers(ListLinierUtas *l, UtasType val){
    AddressUtas p = newNodeUtas(val);
    if (p != NULL){
        NEXTUtas(p) = FIRSTUtas(*l);
        FIRSTUtas(*l) = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastPers(ListLinierUtas *l, UtasType val){
    AddressUtas p, last;
    if (isListUtasPersEmpty(*l)){
        insertFirstPers(l, val);
    }
    else{
        p = newNodeUtas(val);
        if (p != NULL){
            last = FIRSTUtas(*l);
            while (NEXTUtas(last) != NULL){
                last = NEXTUtas(last);
            }
            NEXTUtas(last) = p;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtPers(ListLinierUtas *l, UtasType val, int idx){
    int i = 0;
    AddressUtas p, loc;
    if (idx == 0){
        insertFirstPers(l, val);
    }
    else{
        p = newNodeUtas(val);
        if (p != NULL){
            loc = FIRSTUtas(*l);
            while (i < idx-1){
                i ++;
                loc = NEXTUtas(loc);
            }
            NEXTUtas(p) = NEXTUtas(loc);
            NEXTUtas(loc) = p;
        }
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstPers(ListLinierUtas *l, UtasType *val){
    AddressUtas p = FIRSTUtas(*l);
    *val = INFOUtas(p);
    FIRSTUtas(*l) = NEXTUtas(p);
    free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastPers(ListLinierUtas *l, UtasType *val){
    AddressUtas p, loc;
    p = FIRSTUtas(*l);
    loc = NULL;
    while (NEXTUtas(p) != NULL){
        loc = p;
        p = NEXTUtas(p);
    }
    if (loc == NULL){
        FIRSTUtas(*l) = NULL;
    }
    else{
        NEXTUtas(loc) = NULL;
    }
    *val = INFOUtas(p);
    free(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAtPers(ListLinierUtas *l, int idx, UtasType *val){
    int i = 0;
    AddressUtas p, loc;
    if (idx == 0){
        deleteFirstPers(l, val);
    }
    else{
        loc = FIRSTUtas(*l);
        while (i < idx-1){
            i ++;
            loc = NEXTUtas(loc);
        }
        p = NEXTUtas(loc);
        *val = INFOUtas(p);
        NEXTUtas(loc) = NEXTUtas(p);
        free(p);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
int length(ListLinierUtas l){
    int count = 0;
    AddressUtas p = FIRSTUtas(l);
    while (p != NULL){
        count ++;
        p = NEXTUtas(p);
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(ListLinierUtas *l){
    AddressUtas p = FIRSTUtas(*l);
    UtasType val;
    while(p != NULL){
        deleteFirstPers(l, &val);
        p = NEXTUtas(p);
    }
    *l = NULL;
}
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void copyListUtasPers(ListLinierUtas *l1, ListLinierUtas *l2){
    *l2 = *l1;
    // CreateList(l2);
    // FIRSTUtas(*l2) = FIRSTUtas(*l1);
}
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

int getLastIdxUtasPers(ListLinierUtas l){
    int i = 0;
    AddressUtas p;
    p = FIRSTUtas(l);
    while (NEXTUtas(p) != NULL){
        i ++;
        p = NEXTUtas(p);
    }
    return idxUtas(INFOUtas(p));
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

boolean isIdxUtasPersValid(ListLinierUtas l, int idx){
    AddressUtas p = FIRSTUtas(l);
    boolean found = false;
    while(p != NULL && !found){
        if(idxUtas(INFOUtas(p)) == idx){
            found = true;
        }
        else{
            p = NEXTUtas(p);
        }
    }
    return(found);
}

AddressUtas searchAddressUtas(AddressUtas a, int idUtas){
    if(a == NULL){
        return NULL;
    }
    if(idUtas(INFOUtas(a)) == idUtas){
        return a;
    }
    else{
        return NULL;
    }
}

int searchPositionIndex(ListLinierUtas listUtasPers, int indexUtas){
    boolean found = false;
    int i = 0;
    AddressUtas p = FIRSTUtas(listUtasPers);
    while(!found && i < length(listUtasPers)){
        if(idxUtas(INFOUtas(p)) == indexUtas){
            found = true;
        }
        else{
            i++;
            p = NEXTUtas(p);
        }
    }
    return i;
}
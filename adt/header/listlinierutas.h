/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* UtasType adalah struct int, string, datetime*/

#ifndef listlinierutas_H
#define listlinierutas_H

#include "boolean.h"
#include "datetime.h"
#include "time.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "liststatikuser.h"
#include "friendmatrix.h"

#define CAPACITYMAXLISTUTAS 100
#define IDX_MIN 0
#define MARKUTAS -9999
/* Nilai elemen tak terdefinisi*/

/* Definisi Linked List Utas Personal */
typedef struct {
    int idUtas;
    int idAuthor;
    int indexUtas;
    Word text;
    DATETIME waktu;
} UtasType;

typedef struct nodeUtas* AddressUtas;
typedef struct nodeUtas {
    UtasType info;
    AddressUtas next;
} NodeUtas;

#define INFOUtas(p) (p)->info
#define NEXTUtas(p) (p)->next

typedef AddressUtas ListLinierUtas;

/* *** Notasi Akses: selektor Utas Personal *** */
#define idUtas(U) (U).idUtas
#define idAuthor(U) (U).idAuthor
#define idxUtas(U) (U).indexUtas
#define Text(U) (U).text
#define Waktu(U) (U).waktu

#define IDXUNDEF (-1)
#define FIRSTUtas(l) (l)

AddressUtas newNodeUtas(UtasType val);
/* Definisi List : */
/* List kosong : FIRSTUtas(l) = NULL */
/* Setiap elemen dengan AddressUtas p dapat diacu INFOUtas(p), NEXTUtas(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXTUtas(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListUtasPers(ListLinierUtas *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

void CreateUtas(UtasType *u, int idAuthor, int indexUtas, Word text, DATETIME waktu);
/* I.S. sembarang             */
/* F.S. Terbentuk utas dengan elemen yang diinput */

/****************** TEST LIST KOSONG ******************/
boolean isListUtasPersEmpty(ListLinierUtas l);
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ********************/
UtasType getElmtPers(ListLinierUtas l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmtPers(ListLinierUtas *l, int idx, UtasType val);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOfPers(ListLinierUtas l, UtasType val);
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDXUNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstPers(ListLinierUtas *l, UtasType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastPers(ListLinierUtas *l, UtasType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtPers(ListLinierUtas *l, UtasType val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstPers(ListLinierUtas *l, UtasType *val);
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastPers(ListLinierUtas *l, UtasType *val);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAtPers(ListLinierUtas *l, int idx, UtasType *val);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
int length(ListLinierUtas l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(ListLinierUtas *l);
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void copyListUtasPers(ListLinierUtas *l1, ListLinierUtas *l2);
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

int getLastIdxUtasPers(ListLinierUtas l);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

boolean isIdxUtasPersValid(ListLinierUtas l, int idx);

AddressUtas searchAddressUtas(AddressUtas a, int idUtas);

#endif
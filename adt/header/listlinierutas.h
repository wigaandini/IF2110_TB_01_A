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
#include "listdinkicauan.h"

#define CAPACITYMAXLISTUTAS 100
#define IDX_MIN 0
#define IDX_UNDEF -1
#define MARKUTAS -9999
/* Nilai elemen tak terdefinisi*/

/* Definisi Linked List Utas Personal */
typedef struct {
    int idKicau;
    int idAuthor;
    int indexUtas;
    Word text;
    DATETIME waktu;
} UtasType;

typedef struct node* Address;
typedef struct node {
    UtasType info;
    Address next;
} Node;

/* Definisi List Penyimpan Semua Utas.Utas Global (buat cari idUtas)*/
typedef struct
{
    Kicauan *buffer; 
    int nEff;      
    int capacity;  
} ListUtas;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(UtasType val);

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

typedef Address ListLinierUtas;

/* *** Notasi Akses: selektor Utas Personal *** */
#define IDKICAU(U) (U).idKicau
#define IDAUTHOR(U) (U).idAuthor
#define INDEXUTAS(U) (U).indexUtas
#define TEXT(U) (U).text
#define WAKTU(U) (U).waktu

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

/* *** Notasi Akses: selektor Utas Global *** */
#define NEFFLISTUTAS(L) (L).nEff
#define BUFFERLISTUTAS(L) (L).buffer
#define ELMTLISTUTAS(L, i) (L).buffer[i]
#define CAPACITYUTAS(L) (L).capacity

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListUtasPers(ListLinierUtas *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

void CreateListUtasGLobal(ListUtas *l, int capacity);
/* Menyimpan seluruh utas yang telah dibuat */
/* Prekondisi : list kosong */

void CreateUtas(UtasType *u, int idKicau, int idAuthor, int indexUtas, Word text, DATETIME waktu);
/* I.S. sembarang             */
/* F.S. Terbentuk utas dengan elemen yang diinput */

/****************** TEST LIST KOSONG ******************/
boolean isListUtasPersEmpty(ListLinierUtas l);
/* Mengirim true jika list kosong */

boolean isListUtasEmpty(ListUtas l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */

/* Mengirimkan true jika list l setengah penuh, mengirimkan false jika tidak */
boolean isListUtasFull(ListUtas l);

void dealocateListKicauan(ListUtas *l);

/****************** GETTER SETTER ******************/
UtasType getElmt(ListLinierUtas l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(ListLinierUtas *l, int idx, UtasType val);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(ListLinierUtas l, UtasType val);
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(ListLinierUtas *l, UtasType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(ListLinierUtas *l, UtasType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(ListLinierUtas *l, UtasType val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(ListLinierUtas *l, UtasType *val);
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(ListLinierUtas *l, UtasType *val);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(ListLinierUtas *l, int idx, UtasType *val);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(ListLinierUtas l);
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(ListLinierUtas l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
ListLinierUtas concat(ListLinierUtas l1, ListLinierUtas l2) ;
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(ListLinierUtas L, Address P);
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

// Address searchPrec(List L, UtasType X);
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

/*** Prekondisi untuk Max/Min : List tidak kosong ***/
// UtasType max(List l);
// /* Mengirimkan nilai info(P) yang maksimum */
// Address adrMax(List l);
// /* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
// UtasType min(List l);
// /* Mengirimkan nilai info(P) yang minimum */
// Address adrMin(List l);
// /* Mengirimkan address P, dengan info(P) yang bernilai minimum */

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(ListLinierUtas *l);
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void copyList(ListLinierUtas *l1, ListLinierUtas *l2);
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

void inverseList(ListLinierUtas *l);
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void splitList(ListLinierUtas *l1, ListLinierUtas *l2, ListLinierUtas l);
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */

// float average(List l);
// /* Mengirimkan nilai rata-rata info(P) */

ListLinierUtas fInverseList(ListLinierUtas l);
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

ListLinierUtas fCopyList(ListLinierUtas l);
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */

void cpAllocList(ListLinierUtas lIn, ListLinierUtas *lOut);
/* I.S. lIn sembarang. */
/* F.S. Jika semua alokasi berhasil,maka lOut berisi hasil copy lIn */
/* Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* lOut adalah list kosong jika ada alokasi elemen yang gagal */

#endif
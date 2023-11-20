/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "boolean.h"
#include "wordmachine.h"
#include "datetime.h"

typedef struct
{
    Word Text;
    DATETIME Waktu;
}Draf;

#define Nil -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

#define DrafText(D) (D).Text
#define DrafID(D) (D).id
#define DrafTime(D) (D).Waktu

typedef struct
{
    Word Text;
    int id;
    DATETIME Waktu;
} Draf;

#define DrafText(D) (D).Text
#define DrafID(D) (D).id
#define DrafTime(D) (D).Waktu

typedef Draf infotypeDraf;
typedef int addressDraf;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  infotypeDraf T[MaxEl]; /* tabel penyimpan elemen */
  addressDraf TOP;  /* alamat TOP: elemen puncak */
  int idUser;
} DrafStack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(DrafStack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(DrafStack * S, infotypeDraf X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(DrafStack * S, infotypeDraf* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif
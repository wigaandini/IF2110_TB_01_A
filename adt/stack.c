#include <stdio.h>
#include <time.h>
#include "header/stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(DrafStack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl (HAHH INI BUKANNYA MaxEl-1 ya?)*/
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(DrafStack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return Top(S) == Nil;
}

boolean IsFullStack(DrafStack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return Top(S) == MaxEl-1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(DrafStack * S, infotypeDraf X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S) += 1;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(DrafStack * S, infotypeDraf* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S) -=1;
}
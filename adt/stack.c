#include <stdio.h>
#include <time.h>
#include "header/stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
<<<<<<< Updated upstream
void CreateEmpty(Stack *S)
=======
void CreateEmptyStack(DrafStack *S)
>>>>>>> Stashed changes
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl (HAHH INI BUKANNYA MaxEl-1 ya?)*/
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return Top(S) == Nil;
}

boolean IsFull(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return Top(S) == MaxEl-1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
<<<<<<< Updated upstream
void Push(Stack * S, infotype X)
=======
void Push(DrafStack * S, infotypeDraf X)
>>>>>>> Stashed changes
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S) += 1;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
<<<<<<< Updated upstream
void Pop(Stack * S, infotype* X)
=======
void Pop(DrafStack * S, infotypeDraf * X)
>>>>>>> Stashed changes
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S) -=1;
}

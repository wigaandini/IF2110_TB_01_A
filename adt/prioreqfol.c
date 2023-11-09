#include "header/boolean.h"
#include "header/prioreqfol.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueTime, maka akses elemen : */
/*
#define IDUSER(e)           (e).iduser
#define IDFOLLOW(e)         (e).idfollow
#define NFRIENDUSER(e)      (e).nfrienduser
#define NFRIENDFOLLOW(e)    (e).nfriendfollow
#define Head(Q)             (Q).HEAD
#define Tail(Q)             (Q).TAIL
#define InfoHead(Q)         (Q).T[(Q).HEAD]
#define InfoTail(Q)         (Q).T[(Q).TAIL]
#define MaxEl(Q)            (Q).MaxEl
#define Elmt(Q,i)           (Q).T[(i)]
*/

/* ********* Prototype ********* */
boolean IsEmptyReqFol (Prioreqfol Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}

boolean IsFullReqFol (Prioreqfol Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}    

int NBElmtReqFol (Prioreqfol Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsEmpty(Q)){
        return 0;
    }
    else {
        if ((Tail(Q) - Head(Q)) >= 0){
            return Tail(Q) - Head(Q) + 1;
        }
        else {
            return MaxEl(Q) - (Head(Q) - (Tail(Q) + 1));
        }
    }
}

/* *** Kreator *** */
void MakeEmptyReqFol (Prioreqfol * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (inforeq *)malloc((Max) * sizeof(inforeq));
    if ((*Q).T == NULL) {
        MaxEl(*Q) = 0;
    }
    else {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxEl(*Q) = Max;
    }
}

/* *** Destruktor *** */
void DeAlokasiReqFol(Prioreqfol * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void EnqueueReqFol (Prioreqfol * Q, inforeq X){
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
    boolean found;
    int idx;
    int i, j;
    inforeq temp;

    // ALGORITMA
    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    }
    else {
        Tail(*Q) = Tail(*Q) == MaxEl(*Q) - 1 ? 0 : Tail(*Q) + 1;
        InfoTail(*Q) = X;
        i = Tail(*Q);
        j = i == 0 ? MaxEl(*Q) - 1 : i - 1;
        while (i != Head(*Q) && Time(Elmt(*Q, i)) < (Time(Elmt(*Q, j)))) {
            temp = Elmt(*Q, i);
            Elmt(*Q, i) = Elmt(*Q, j);
            Elmt(*Q, j) = temp;
            i = j;
            j = i == 0 ? MaxEl(*Q) - 1 : i - 1;
        }
    }
}

void DequeueReqFol (Prioreqfol * Q, inforeq * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintReqFol (Prioreqfol Q){
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/
    inforeq val;
    Prioreqfol temp;
    temp = Q;
    if (!IsEmpty(Q)) {
        while (!IsEmpty(temp)) {
            Dequeue(&temp, &val);
            // printf("%d %c\n", Time(val), Info(val));
        }
    }
    printf("#\n");
}

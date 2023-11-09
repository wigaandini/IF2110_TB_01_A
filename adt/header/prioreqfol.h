/* File : prioreqfol.h */
/* Definisi ADT Priority Queue Time dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#ifndef prioreqfol_H
#define prioreqfol_H

#include "boolean.h"
#include "friendmatrix.h"

#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef struct {
    int iduser;
    int idfollow;
    int nfrienduser;
    int nfriendfollow;
} inforeq;

typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueTime : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */

typedef struct {
    inforeq * T;   /* tabel penyimpan elemen */
    address HEAD;  /* alamat penghapusan */
    address TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} Prioreqfol;
/* Definisi PrioQueueTime kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueTime, maka akses elemen : */
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


/* ********* Prototype ********* */
boolean IsEmptyReqFol (Prioreqfol Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */

boolean IsFullReqFol (Prioreqfol Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBElmtReqFol (Prioreqfol Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmptyReqFol (Prioreqfol * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasiReqFol(Prioreqfol * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void EnqueueReqFol (Prioreqfol * Q, inforeq X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */

void DequeueReqFol (Prioreqfol * Q, inforeq * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintReqFol (Prioreqfol Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/

#endif
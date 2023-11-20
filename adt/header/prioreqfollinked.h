/* File: prioreqfollinked.h */

#ifndef PRIOREQFOLLINKED_H
#define PRIOREQFOLLINKED_H
#include "boolean.h"
#include <stdlib.h>
#include "friendmatrix.h"


#define NIL NULL
/* Deklarasi infotype */
typedef int ElTypeReq;
/* Queue dengan representasi berkait dengan pointer */
typedef struct node* Address;
typedef struct node { 
    int iduser;
    int idfollow;
    int nfrienduser;
    int nfriendfollow;
    Address next; 
} req; 
/* Type queue dengan ciri HEAD dan TAIL: */
typedef struct {
    Address addrHead; /* alamat penghapusan */
    Address addrTail; /* alamat penambahan */
} Prioreqfol;

/* Selektor */
#define IDUSER(p)           (p)->iduser
#define IDFOLLOW(p)         (p)->idfollow
#define NFRIENDUSER(p)      (p)->nfrienduser
#define NFRIENDFOLLOW(p)    (p)->nfriendfollow
#define NEXT(p) (p)->next

#define ADDR_HEAD(q) (q).addrHead
#define ADDR_TAIL(q) (q).addrTail

/* Prototype manajemen memori */
Address newReq(FriendMatrix m, ElTypeReq idus, ElTypeReq ifol);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
boolean isEmptyReqFol(Prioreqfol q);
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
int lengthReqFol(Prioreqfol q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void CreateReqFol(Prioreqfol *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
void daftarPermintaan(Prioreqfol q);
/*Menuliskan orang yang merequest kita dari yang teratas*/

/*** Primitif Enqueue/Dequeue ***/
void sendReqFol(Prioreqfol *q, FriendMatrix m, ElTypeReq idus, ElTypeReq ifol);
/* qfol adallah queue yang dimiliki orang yang ingin difollow
Idus adalah orang yang merequest
Ifol adalah orang yang direquest
Misal dhidit merequest follow kepada ucup
Maka priority request follow pada adt pengguna ucup akan bertambah
*/

void dequeueReqFol(Prioreqfol *q, ElTypeReq *x);
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */

void setujuiReqFol(Prioreqfol *q, FriendMatrix *m);
    //Menambahkan pertemanan kepada matriks pertemanan   
#endif
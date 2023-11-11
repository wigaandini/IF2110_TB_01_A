#include "header/prioreqfollinked.h"
#include "header/friendmatrix.h"
#include <stdio.h>
#include <stdlib.h>

//Dhidit Abdi Aziz
//13522040

/* Prototype manajemen memori */
Address newReq(FriendMatrix m, ElType idus, ElType ifol){
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
    Address p;
    ElType nfus = howMuchFriend(m, idus); //Jumlah follower orang yang merequest
    ElType nffol = howMuchFriend(m, ifol); //Jumlah follower orang yang direquest
    p = (Address)malloc(sizeof(req));
    if(p!=NULL){
        IDUSER(p) = idus;
        IDFOLLOW(p) = ifol;
        NFRIENDUSER(p) = nfus;
        NFRIENDFOLLOW(p) = nffol;
        NEXT(p) = NULL;
    }
    return p;

}

boolean isEmptyReqFol(Prioreqfol q){
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
    return ((ADDR_HEAD(q) == NULL)&&(ADDR_TAIL(q)==NULL));
}

int lengthReqFol(Prioreqfol q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
    Address p;
    int N;

    N = 0;
    if(!isEmpty(q)){
        p = ADDR_HEAD(q);
        do{
            N++;
            p = NEXT(p);
        }while (p!=NULL);
    }
    return N;
}
/*** Kreator ***/
void CreateReqFol(Prioreqfol *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void daftarPermintaan(Prioreqfol q){
/*Menuliskan orang yang merequest kita dari yang teratas*/
    Address p;
    p = ADDR_HEAD(q);
    while(p!=NULL){
        printf("ID Orang yang merequest: %d\n", IDFOLLOW(p));
        printf("Jumlah follower: %d\n\n", NFRIENDFOLLOW(p));
    } 
}

/*** Primitif Enqueue/Dequeue ***/
void SendReqFol(Prioreqfol *qfol, FriendMatrix m, ElType idus, ElType ifol){
/* qfol adallah queue yang dimiliki orang yang ingin difollow
Idus adalah orang yang merequest
Ifol adalah orang yang direquest
Misal dhidit merequest follow kepada ucup
Maka priority request follow pada adt pengguna ucup akan bertambah
*/
    Address p, pre, nex;
    p = newReq(m, idus, ifol);
    if(p!=NULL){
        if(isEmpty(*qfol)){
            ADDR_HEAD(*qfol) = p;
            ADDR_TAIL(*qfol) = p;
        }
    
        else{
        // Queue tidak kosong, harus dimasukkan sesuai urutan 
        // Ada tiga kasus: insertfirst, insertbetween, insertlast
            pre = NIL;
            nex = ADDR_HEAD(*qfol);
            while((NFRIENDUSER(p)<NFRIENDUSER(nex))&&(nex!=NULL)){
            //pencarian tempat yang tepat
            pre = nex;
            nex = NEXT(nex);
            }
            //tempat yang tepat sudah ditemukan
            NEXT(p) = nex;
            if(nex == ADDR_HEAD(*qfol)){
                //insertfirst
                ADDR_HEAD(*qfol) = p;
            }  
            else{
                NEXT(pre) = p;
                if(nex == NIL){
                    ADDR_TAIL(*qfol) = p;
                }
            }
        }
             
    }
}

void dequeueReqFol(Prioreqfol *q, ElType *x){
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
    Address p;
    *x = IDUSER(ADDR_HEAD(*q));
    p = ADDR_HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    if(ADDR_HEAD(*q)==NULL){
        ADDR_TAIL(*q) = NULL;
    }
    NEXT(p) = NULL;
    free(p);
}

void setujuiReqFol(Prioreqfol *q, FriendMatrix *m){
    //Menambahkan pertemanan kepada matriks pertemanan
    addFriend(m, IDUSER(ADDR_HEAD(*q)), IDFOLLOW(ADDR_HEAD(*q)));
}



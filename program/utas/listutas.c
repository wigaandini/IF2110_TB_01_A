/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#include <stdio.h>
#include <stdlib.h>
#include "listutas.h"

typedef struct{
    int idBalas;
    char[280] text;
    DATETIME waktu;
    Address utas;
} ElType;

typedef Address List;

Address newNode(ElType val){
    Address p = (Address) malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}
/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return (FIRST(l) == NULL);
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
    int i = 0;
    Address p;
    p = FIRST(l);
    while (i < idx){
        i ++;
        p = NEXT(p);
    }
    return INFO(p);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val){
    int i = 0;
    Address p;
    p = FIRST(*l);
    while (i < idx){
        i ++;
        p = NEXT(p);
    }
    INFO(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val){
    Address p;
    boolean found = false;
    int i = 0;
    p = FIRST(l);
    while (p != NULL && !found){
        if(INFO(p) == val){
            found = true;
        }
        else{
            i ++;
            p = NEXT(p);
        }
    }
    if(found){
        return i;
    }
    else{
        return IDX_UNDEF;
    }

    // int i = 0;
    // Address p = FIRST(l);
    // while (p != NULL) {
    //     if (INFO(p) == val) {
    //         return i;
    //     }
    //     p = NEXT(p);
    //     i++;
    // }
    // return IDX_UNDEF;
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address p = newNode(val);
    if (p != NULL){
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val){
    Address p, last;
    if (isEmpty(*l)){
        insertFirst(l, val);
    }
    else{
        p = newNode(val);
        if (p != NULL){
            last = FIRST(*l);
            while (NEXT(last) != NULL){
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx){
    int i = 0;
    Address p, loc;
    if (idx == 0){
        insertFirst(l, val);
    }
    else{
        p = newNode(val);
        if (p != NULL){
            loc = FIRST(*l);
            while (i < idx-1){
                i ++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
    Address p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
    Address p, loc;
    p = FIRST(*l);
    loc = NULL;
    while (NEXT(p) != NULL){
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL){
        FIRST(*l) = NULL;
    }
    else{
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
    int i = 0;
    Address p, loc;
    if (idx == 0){
        deleteFirst(l, val);
    }
    else{
        loc = FIRST(*l);
        while (i < idx-1){
            i ++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    if(isEmpty(l)){
        printf("[]");
    }
    else{
        printf("[");
        Address p = FIRST(l);
        while (p != NULL){
            printf("%d", INFO(p));
            p = NEXT(p);
            if (p != NULL){
                printf(",");
            }
        }
        printf("]");
    }
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
    int count = 0;
    Address p = FIRST(l);
    while (p != NULL){
        count ++;
        p = NEXT(p);
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
    Address p;
    List lnew;
    CreateList(&lnew);
    p = FIRST(l1);
    // p = l1;
    while (p != NULL){
        insertLast(&lnew, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2) ;
    while (p != NULL){
        insertLast(&lnew, INFO(p));
        p = NEXT(p);
    }
    return lnew;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P){
    boolean found = false;
    Address src = FIRST(L);
    while (src != NULL && !found){
        if (src == P){
            found = true;
        }
        else{
            src = NEXT(src);
        }
    }
    return found;

    // Address now;
    // boolean flag = false;
    // now = L;
    // while(now->next != NULL && !flag){
    //     if(now==P){
    //         flag = true;
    //     }
    //     now = now->next;
    // }
    // return flag;
}
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
Address searchPrec(List L, ElType X){
    Address p = FIRST(L);
    // Address p = L;
    Address prev;

    if(isEmpty(L) || length(L) == 1){
        return NULL;
    }
    while (INFO(p) != X && p != NULL){
        prev = p;
        p = NEXT(p);
    }
    if (p == NULL){
        return NULL;
    }
    else{
        return prev;
    }
}
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

/*** Prekondisi untuk Max/Min : List tidak kosong ***/
ElType max(List l){
    ElType maks;
    Address p = FIRST(l);
    // Address p = l;
    maks = INFO(p);
    while (p != NULL){
        if(INFO(p) >= maks){
            maks = INFO(p);
        }
        p = NEXT(p);
    }
    return maks;
}
/* Mengirimkan nilai info(P) yang maksimum */
Address adrMax(List l){
    ElType maks = max(l);
    Address p = FIRST(l);
    // Address p = l;
    while (p != NULL && INFO(p) != maks){
        p = NEXT(p);
    }
    return p;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
ElType min(List l){
    ElType minm;
    Address p = FIRST(l);
    // Address p = l;
    minm = INFO(p);
    while (p != NULL){
        if(INFO(p) <= minm){
            minm = INFO(p);
        }
        p = NEXT(p);
    }
    return minm;
}
/* Mengirimkan nilai info(P) yang minimum */
Address adrMin(List l){
    ElType minm = min(l);
    Address p = FIRST(l);
    // Address p = l;
    while (p != NULL && INFO(p) != minm){
        p = NEXT(p);
    }
    return p;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(List *l){
    Address p = FIRST(*l);
    ElType val;
    while(p != NULL){
        deleteFirst(l, &val);
        p = NEXT(p);
    }
    *l = NULL;
}
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void copyList(List *l1, List *l2){
    *l2 = *l1;
    // CreateList(l2);
    // FIRST(*l2) = FIRST(*l1);
}
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

void inverseList(List *l){
    if(!isEmpty(*l)){
        int n = length(*l);
        int i;
        Address p = *l;
        Address prev;
        Address last;
        while(NEXT(p)!= NULL){
            p = NEXT(p);
        }
        last = p;
        while (p != *l){
            prev = *l;
            while(NEXT(prev) != p){
                prev = NEXT(prev);
            }
            NEXT(p) = prev;
            p = prev;
        }
        NEXT(p) = NULL;
        *l = last;
    }
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void splitList(List *l1, List *l2, List l){
    CreateList(l1);
    CreateList(l2);
    int half = length(l) / 2;
    int cnt = 0;
    Address p = l;
    while(p != NULL){
        if(cnt < half){
            insertLast(l1, INFO(p));
        }
        else{
            insertLast(l2, INFO(p));
        }
        cnt++;
        p = NEXT(p);
    }
}
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */

float average(List l){
    int count = 0;
    ElType sum = 0;
    Address p = FIRST(l);
    while(p != NULL){
        sum += INFO(p);
        count ++;
    }
    return ((float)sum/count);
}
/* Mengirimkan nilai rata-rata info(P) */

List fInverseList(List l){
    List lnew;
    CreateList(&lnew);
    cpAllocList(l, &lnew);
    inverseList(&lnew);
    return lnew;
}
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

List fCopyList(List l){
    List lnew;
    Address p, prec, pnew;
    boolean berhasil;

    /* ALGORITMA */
    lnew = (Address) malloc(sizeof(Node));
    
    if (lnew != NULL) {
        CreateList(&lnew);

        berhasil = true;

        p = FIRST(l);
        prec = NULL;
        while (p != NULL && berhasil) {
            pnew = newNode(INFO(p));
            if (pnew != NULL) {
                if (prec == NULL) {
                    FIRST(lnew) = pnew;
                } else {
                    NEXT(prec) = pnew;
                }
                p = NEXT(p);
            } else {
                deleteAll(&lnew);
                berhasil = false;
            }
            prec = pnew;
        }
    }

    return lnew;
}
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */

void cpAllocList(List lIn, List *lOut){
    CreateList(lOut);
    *lOut = fCopyList(lIn);
}
/* I.S. lIn sembarang. */
/* F.S. Jika semua alokasi berhasil,maka lOut berisi hasil copy lIn */
/* Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* lOut adalah list kosong jika ada alokasi elemen yang gagal */
#ifndef adtbalasan_H
#define adtbalasan_H

#include "boolean.h"
#include "listdin.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "time.h"
#include "datetime.h"
#include "listdinkicauan.h"
#include "friendmatrix.h"
#include "liststatikuser.h"

typedef struct NodeBalasan* AddressBalasan;

typedef struct NodeBalasan{
    int id;
    Word teks;
    int idPenulis;
    DATETIME waktu; 
    AddressBalasan child; // Balasan dari balasan ini, berbentuk seperti linked-list
    AddressBalasan sibling; // Balasan yang 'kedalamannya' sama dengan balasan saat ini
} Balasan;

/* Jika B adalah Balasan maka: */
/* CHILD(B) adalah Balasan pertama dari B */
/* SIBLING(B) adalah Balasan yang 'kedalaman'-nya sama dengan B */
/* BALASAN KOSONG TIDAK TERDEFINISI */

#define NIL NULL

/*  ***        SELEKTOR          *** */
#define CHILDBALASAN(B) (B).child
#define SIBLINGBALASAN(B) (B).sibling
#define TEKSBALASAN(B) (B).teks
#define IDBALASAN(B) (B).id
#define IDPENULISBALASAN(B) (B).idPenulis
#define WAKTUBALASAN(B) (B).waktu

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
AddressBalasan newBalasan(int id, Word teks, int idPenulis, DATETIME waktu);
/* Membentuk sebuah Balasan dengan komponen yang valid */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BALASAN(ListKicauan *l, FriendMatrix *fh, ListStatikUser *lsu, int idKicau, int curUserId);
/* I.S. sembarang */
/* F.S. apabila idKicau valid:
        men-display semua balasan dari Kicauan dengan idKicau */
/*      otherwise, menampilkan pesan error                    */

void BALAS(ListKicauan *l, FriendMatrix *fh, ListStatikUser *lsu, Word textBalasan, DATETIME curTime, int idKicau, int idBalasan, int curUserId, int *curIdBalasan);
/* I.S. sembarang */
/* F.S. apabila idBalasan dan idKicau valid serta pengguna dapat membalas:
        membuat Balasan di Kicauan dengan idKicau dan Balasan dengan idBalasan */
/*      otherwise, menampilkan pesan error                                    */

void displayUnitBalasan(AddressBalasan a, ListStatikUser *lsu, boolean friend);

void displaySemuaBalasan(AddressBalasan a, FriendMatrix *fh, ListStatikUser *lsu, int curUserId, int indent);

/* ***************************************************************** */
/* OPERASI LAINNYA                                                   */
/* ***************************************************************** */
void HAPUS_BALASAN(ListKicauan *l, int curUserId, int idKicau, int idBalasan);

AddressBalasan searchAddressBalasan(AddressBalasan a, int idBalasan);

AddressBalasan insertBalasan(AddressBalasan a, Word text, int curIdBalasan, int curUserId, DATETIME waktu);

AddressBalasan findPrev(AddressBalasan a, AddressBalasan prev, boolean *fd, int idBalasan);

void hapusHelper(AddressBalasan cur);

#endif
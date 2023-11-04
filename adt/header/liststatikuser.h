/* MODUL LIST STATIK DENGAN ELEMEN BERUPA USER DATA */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik dengan index merepresentasikan ID dari User*/

#ifndef LISTSTATIKUSER_H
#define LISTSTATIKUSER_H

#include "boolean.h"
#include "stack.h"
#include "matrix.h"
#include "wordmachine.h"
#include "listdin.h"

/*  Kamus Umum */
#define CAPACITYUSER 20
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
// #define MARK ""
/* Nilai elemen tak terdefinisi adalah elemen kosong (list kosong didefinisikan dibawah)*/

enum Weton {   // Tipe Weton bikinan sendiri (EMPTYWETON, PAHING, KLIWON, WAGE, PON, dan LEGI)
   EMPTYWETON,
   PAHING,
   KLIWON,
   WAGE,
   PON,
   LEGI
};

enum TipeAkun {   // Tipe Akun bikinan sendiri (Publik/Privat)
   PUBLIK,
   PRIVAT
};

/* Definisi elemen dan koleksi objek */
typedef struct {        // Elemen dari list berupa tipe data buatan "UserData", 
   char nama[21];       // terdiri dari ID (indeks), Nama, Password, Bio, No HP, Weton, Jenis akun, dan foto profil
   int id;
   char sandi[21];
   char bio[136];
   ListDin noHP;     // Ini harus pake malloc, listdin tapi tiap elemennya adalah char
   enum Weton weton;
   enum TipeAkun tipe;
   Matrix foto;
   Matrix warnaFoto;
} UserData;             // type elemen list

typedef int IdxType;
typedef struct {
   UserData data[CAPACITYUSER]; /* memori tempat penyimpan elemen (container) */
} ListStatikUser;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatikUser, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatikUser */
/* Maka cara akses: 
   ELMT(l,i) untuk mengakses elemen UserData ke-i dengan ID i */
/* Definisi : 
   List kosong: semua elemen memenuhi nilai User Data berikut
   tiap char nama berisi '\0'
   tiap char sandi berisi '\0'
   tiap char bio berisi '\0'
   tiap char noHP '\0'
   weton bernilai EMPTYWETON
   foto akan berisi '*' di setiap elemen nya
   warnaFoto akan berisi 
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define UserName(l, i, j)     (l).data[(i)].nama[j]
#define UserId(l, i)          (l).data[i].id
#define UserSandi(l, i, j)    (l).data[(i)].sandi[j]
#define UserBio(l, i, j)      (l).data[(i)].bio[j]
#define UserNoHP(l, i, j)     (l).data[i].noHP.buffer[j]
#define UserWeton(l, i)       (l).data[i].weton
#define UserTipe(l, i)        (l).data[i].tipe
#define UserFoto(l, i)        (l).data[i].foto
#define UserWarnaFoto(l, i)   (l).data[i].warnaFoto

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List User kosong  */
void CreateListStatikUser(ListStatikUser *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List of User Data yang kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua User Data sesuai dengan definisi list kosong diatas */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int banyakUser(ListStatikUser l);
/* Mengirimkan banyaknya user yang telah terdaftar */
/* Mengirimkan nol jika belum ada user yang terdaftar */  


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isUserDataEmpty(ListStatikUser l);
/* Mengirimkan true jika List of User Data kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isUserDataFull(ListStatikUser l);
/* Mengirimkan true jika List of User Data penuh, mengirimkan false jika tidak */


void printListofUser(ListStatikUser l);
/* Proses : Menampilkan Data User yang terdaftar secara traversal, dengan diakhir newline */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong, akan ditampilkan seluruh Data User yang terdaftar */
/* Jika List kosong : menampilkan "Belum ada User yang terdaftar" */


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexUser(ListStatikUser l, Word name);
/* Search apakah ada Data User yang Username-nya bernilai name */
/* Jika ada, menghasilkan indeks i dari Data User tersebut */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */

int idOf(ListStatikUser l, Word name);
// Mengembalikan ID dari user yang memiliki username bernilai name

/* ********** MENAMBAH DATA USER ********** */
void addUser(ListStatikUser *l, Word name, Word pw);
/* I.S. l sembarang dan tidak penuh
   F.S. l bertambah satu user
   Proses: Pada user data yang masih kosong, UserName dan UserSandi diubah sesuai dengan masukkan terminal*/

/* ********** MENGUBAH DATA USER ********** */
// void editUserData(ListStatikUser *l, )


#endif
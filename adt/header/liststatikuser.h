/* MODUL LIST STATIK DENGAN ELEMEN BERUPA USER DATA */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik dengan index merepresentasikan ID dari User*/

#ifndef LISTSTATIKUSER_H
#define LISTSTATIKUSER_H

#include "boolean.h"
#include "stack.h"
#include "matrix.h"

/*  Kamus Umum */
#define CAPACITY 20
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
   char nama[21];       // terdiri dari Nama, Password, Bio, No HP, Weton, Jenis akun, dan foto profil
   char sandi[21];
   char bio[136];
   Stack noHP;           // Pake bigint.c ? iya pake
   enum Weton weton;
   enum TipeAkun tipe;
   Matrix foto;
   Matrix warnaFoto;
} UserData;             // type elemen list

typedef int IdxType;
typedef struct {
   UserData data[CAPACITY]; /* memori tempat penyimpan elemen (container) */
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
   Stack noHP kosong
   weton bernilai EMPTYWETON
   foto akan berisi '*' di setiap elemen nya
   warnaFoto akan berisi 
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define UserName(l, i, j)     (l).data[(i)].nama[j]
#define UserSandi(l, i, j)    (l).data[(i)].sandi[j]
#define UserBio(l, i, j)      (l).data[(i)].bio[j]
#define UserNoHP(l, i)        (l).data[i].noHP
#define UserWeton(l, i)       (l).data[i].weton
#define UserTipe(l, i)        (l).data[i].tipe
#define UserFoto(l, i)        (l).data[i].foto
#define UserWarnaFoto(l, i)   (l).data[i].warnaFoto

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List User kosong  */
void CreateListStatikUser(ListStatikUser *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatikUser l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatikUser l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListStatikUser l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatikUser l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListStatikUser l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatikUser l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListStatikUser l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatikUser *l);
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void printList(ListStatikUser l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatikUser plusMinusList(ListStatikUser l1, ListStatikUser l2, boolean plus);
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatikUser l1, ListStatikUser l2);
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatikUser l, ElType val);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatikUser l, ElType *max, ElType *min);
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatikUser *l, ElType val);
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatikUser *l, ElType val, IdxType idx);
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatikUser *l, ElType val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatikUser *l, ElType *val);
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatikUser *l, ElType *val, IdxType idx);
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatikUser *l, ElType *val);
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortList(ListStatikUser *l, boolean asc);
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

#endif
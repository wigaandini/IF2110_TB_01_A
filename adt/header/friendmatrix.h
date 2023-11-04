/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef FRIENDMATRIX_H
#define FRIENDMATRIX_H

#include "boolean.h"

/* Ukuran maksimum baris dan kolom */
#define ROW_CAPFRIEND 20
#define COL_CAPFRIEND 20

typedef int IdxType; /* Index baris, kolom */
typedef int ElTypeFriend;
typedef struct
{
   ElTypeFriend mem[ROW_CAPFRIEND][COL_CAPFRIEND]; /*Elemen antara 1 atau 0*/
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} FriendMatrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAPFRIEND-1][0..COL_CAPFRIEND-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrixFriend(int nRows, int nCols, FriendMatrix *m);
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

void displayMatrixFRIEND(FriendMatrix m,int row,int col);

/* *** Selektor *** */
#define ROW_EFFFRIEND(M) (M).rowEff
#define COL_EFFFRIEND(M) (M).colEff
#define ELMTFRIEND(M, i, j) (M).mem[(i)][(j)]

IdxType getLastIdxColFRIEND(FriendMatrix m);


// /* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
// IdxType getLastIdxRow(FriendMatrix m){
// /* Mengirimkan Index baris terbesar m */
//    return ROW_EFF(m) - 1; 
// }

// IdxType getLastIdxCol(FriendMatrix m){
// /* Mengirimkan Index kolom terbesar m */
//    return COL_EFF(m) - 1;
// }

// boolean isIdxEff(FriendMatrix m, IdxType i, IdxType j);
// /* Mengirimkan true jika i, j adalah Index efektif bagi m
// Index efektif berarti id user tersebut sudah terdaftar */

// boolean isFriend(FriendMatrix m, IdxType i, IdxType j){
// // Mengirimkan true jika user id i dan id j saling berteman
//    return ((ELMT(m,i,j) == 1)&&(ELMT(m,j,i) == 1));
// }

// void newUser(FriendMatrix *m);
// //Idx efektif diupdate

// void addFriend(FriendMatrix *m, IdxType i, IdxType j);

// void deleteFriend(FriendMatrix *m, IdxType i, IdxType j);

#endif
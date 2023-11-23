#include <stdio.h>
#include <stdlib.h>
#include "header/boolean.h"
#include "header/friendmatrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrixFriend(FriendMatrix *m){
// I.S Matrix tidak terdefinisi
// F.S. Dialokasikan matriks ukuran 20x20 yang berisi nol semua tapi tidak dapat diakses karena elemen efektifnya 0
    ROW_EFFFRIEND(*m) = 0;
    COL_EFFFRIEND(*m) = 0;
    //RowEff dan ColEff masih 0 karena belum ada pengguna
    int i, j;
    for(i = 0; i < 20; i++){
        for(j = 0; j < 20; j++){
            ELMTFRIEND(*m, i, j) = 0;
        }
    }
}

// /* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRowFriend(FriendMatrix m){
// Mengirimkan Index baris terbesar m 
    return ROW_EFFFRIEND(m) - 1; 
}

IdxType getLastIdxColFriend(FriendMatrix m){
// Mengirimkan Index baris terbesar m 
    return COL_EFFFRIEND(m) - 1;
}

IdxType howMuchFriend(FriendMatrix m, IdxType i){
// Mengeluarkan jumlah teman yang dia dimilki
// Prekondisi: i adalah id user yang terdefinisi (efektif)
    int j; //counter
    int sum = 0;
    for(j = 0; j<=getLastIdxColFriend(m); j++){
        if(i!=j){
            sum += ELMTFRIEND(m,i,j);
        }
    }
    return sum;
}

boolean isIdxEffFriend(FriendMatrix m, IdxType i, IdxType j){
// Mengirimkan true jika i, j adalah Index efektif bagi m
// Index efektif berarti id user tersebut sudah terdaftar */
    return (i>=0)&&(i<=getLastIdxRowFriend(m))&&(j>=0)&&(j<=getLastIdxRowFriend(m));
}

boolean isFriend(FriendMatrix m, IdxType i, IdxType j){
// Prekondisi: i dan j adalah index yang efektif 
// Mengirimkan true jika user id i dan id j saling berteman  
    return ((ELMTFRIEND(m,i,j) == 1)&&(ELMTFRIEND(m,j,i) == 1));
}

void addNeff(FriendMatrix *m){
// Prekondisi: Jumlah user<20
// Row efektid dan Col efektif akan ditambah
    ROW_EFFFRIEND(*m) ++;
    COL_EFFFRIEND(*m) ++;
}

void addFriend(FriendMatrix *m, IdxType i, IdxType j){
// Prekondisi: i dan j adalah index yang efektif
// Prekondisi: i != j
// Prekondisi: i dan j belum berteman
    ELMTFRIEND(*m,i,j) = 1;
    ELMTFRIEND(*m,j,i) = 1;   
}

void deleteFriend(FriendMatrix *m, IdxType i, IdxType j){
// Prekondisi: i dan j adalah index yang efektif
// Prekondisi: i != j
// Prekondisi: i dan j berteman
    ELMTFRIEND(*m,i,j) = 0;
    ELMTFRIEND(*m,j,i) = 0;  
}


#include <stdio.h>
#include <stdlib.h>
#include "header/boolean.h"
#include "header/friendmatrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrixFriend(int nRows, int nCols, FriendMatrix *m){
    ROW_EFFFRIEND(*m) = nRows;
    COL_EFFFRIEND(*m) = nCols;

    int i, j;
    for(i = 0; i < nRows; i++){
        for(j = 0; j < nCols; j++){
            ELMTFRIEND(*m, i, j) = 0;
        }
    }
}

IdxType getLastIdxColFRIEND(FriendMatrix m){
    return COL_EFFFRIEND(m) - 1;
}

void displayMatrixFRIEND(FriendMatrix m,int row,int col){
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(j == col-1){
                printf("%d\n", ELMTFRIEND(m, i, j));
            }
            else{
                printf("%d ", ELMTFRIEND(m, i, j));
            }
        }
    }
}
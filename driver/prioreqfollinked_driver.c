#include <stdio.h>
#include "../adt/friendmatrix.c"
#include "../adt/prioreqfollinked.c"


int main() {
    FriendMatrix m;
    createMatrixFriend(&m);

    int x;

    Prioreqfol q;
    ADDR_HEAD(q) = NULL;
    ADDR_TAIL(q) = NULL;

    // Menguji isEmptyReqFol
    isEmptyReqFol(q);

    // Menambahkan request pertemanan ke dalam queue
    newReq(m, 1, 3, 5);
    newReq(m, 4, 3, 6);
    newReq(m, 2, 3, 1);

    //Menguji display request follow
    daftarPermintaan(q);
    
    // Menguji dequeue request follow
    dequeueReqFol(&q, &x);
    daftarPermintaan(q);

    // Menguji isXRequestToY
    if(isXRequestToY(q, 1)){
        printf("User indeks 1 merequest kepada user indeks 3");
    }
    else{
        printf("User indeks 1 merequest kepada user indeks 3");
    }

    if(isXRequestToY(q, 4)){
        printf("User indeks 4 merequest kepada user indeks 3");
    }
    else{
        printf("User indeks 4 merequest kepada user indeks 3");
    }

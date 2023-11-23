#include <stdio.h>
#include "../adt/friendmatrix.c"
#include "../adt/prioreqfollinked.c"


int main() {
    FriendMatrix matrix;
    createMatrixFriend(&matrix);

    // Menambahkan beberapa pengguna dan pertemanan
    newUser(&matrix);
    newUser(&matrix);
    newUser(&matrix);

    addFriend(&matrix, 0, 1);
    addFriend(&matrix, 1, 2);

    // Menampilkan matriks dan informasi pengguna
    printf("Matrix:\n");
    for (IdxType i = 0; i <= getLastIdxRowFriend(matrix); i++) {
        for (IdxType j = 0; j <= getLastIdxColFriend(matrix); j++) {
            printf("%d ", ELMTFRIEND(matrix, i, j));
        }
        printf("\n");
    }

    printf("\nUser Information:\n");
    for (IdxType i = 0; i <= getLastIdxRowFriend(matrix); i++) {
        printf("User %d has %d friend(s).\n", i, howMuchFriend(matrix, i));
    }

    // Menguji isFriend
    IdxType user1 = 0, user2 = 1;
    if (isFriend(matrix, user1, user2)) {
        printf("\nUser %d and User %d are friends.\n", user1, user2);
    } else {
        printf("\nUser %d and User %d are not friends.\n", user1, user2);
    }

    // Menghapus pertemanan
    deleteFriend(&matrix, 0, 1);

    // Menampilkan matriks setelah menghapus pertemanan
    printf("\nMatrix after deleting friendship:\n");
    for (IdxType i = 0; i <= getLastIdxRowFriend(matrix); i++) {
        for (IdxType j = 0; j <= getLastIdxColFriend(matrix); j++) {
            printf("%d ", ELMTFRIEND(matrix, i, j));
        }
        printf("\n");
    }

    return 0;
}

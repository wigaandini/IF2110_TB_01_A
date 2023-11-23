#include <stdio.h>
#include <stdlib.h>
#include "../adt/treebalasan.c"
#include "../adt/liststatikuser.c"
#include "../adt/friendmatrix.c"
#include "../adt/wordmachine.c"
#include "../adt/charmachine.c"
#include "../adt/matrix.c"
#include "../adt/pcolor.c"
#include "../adt/stack.c"
#include "../adt/listdin.c"
#include "../adt/datetime.c"
#include "../adt/time.c"

int main() {
    // Inisialisasi data atau struktur yang diperlukan
    ListStatikUser lsu;
    FriendMatrix fh;
    AddressBalasan root = NULL;

    // Pengujian fungsi-fungsi
    DATETIME waktu;
    TIME t;
    // Inisialisasi waktu (sesuaikan sesuai kebutuhan)
    t.HH = 12;
    t.MM = 30;
    t.SS = 0;
    waktu.T = t;
    waktu.DD = 10;
    waktu.MM = 11;
    waktu.YYYY = 2023;

    Word word1 = {"Hello", 5};
    Word word2 = {"Hi", 2};

    // Contoh penggunaan fungsi newBalasan
    AddressBalasan balasan1 = newBalasan(2, word1, 2, waktu);
    AddressBalasan balasan2 = newBalasan(3, word2, 3, waktu);

    // Contoh penggunaan fungsi insertBalasan
    Word word3 = {"First Balasan", 13};
    root = newBalasan(1, word3, 4, waktu);
    CHILDBALASAN(*root) = balasan1;
    SIBLINGBALASAN(*balasan1) = balasan2;

    // Contoh penggunaan fungsi displaySemuaBalasan
    printf("Displaying all balasan:\n");
    displaySemuaBalasan(root, &fh, &lsu, 4, 0);
    // Contoh penggunaan fungsi searchAddressBalasan
    AddressBalasan foundBalasan = searchAddressBalasan(root, 2);
    if (foundBalasan != NULL) {
        printf("\nBalasan with ID 2 found!\n");
        displayUnitBalasan(foundBalasan, &lsu, true, 0);
    } else {
        printf("\nBalasan with ID 2 not found!\n");
    }

    // Penghapusan memori setelah pengujian
    hapusHelper(root);

    return 0;
}

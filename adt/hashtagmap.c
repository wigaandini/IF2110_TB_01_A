#include "hashtagmap.h"

/**
 * Modul Hash HashMap
 * Implementasi Hash HashMap dengan Open Addressing
*/

/* Definisi HashMap M kosong : M.CountHash = NilHash */
/* M.CountHash = jumlah element HashMap */
/* M.ElementsHash = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyHash(HashMap *M) {
    /* I.S. sembarang */
    /* F.S. M kosong */
    M->CountHash = 0;
    for (int i = 0; i < MaxElHash; i++) {
        M->ElementsHash[i].Key = UndefinedHash;
        M->ElementsHash[i].Value = UndefinedHash;
    }
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxElHash */
/* Ciri HashMap kosong : count bernilai NilHash */

/* *** Index Penyimpanan dengan modulo *** */
hashAddress Hash(hashKeyType K) {
    /* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxElHash */
    return K % MaxElHash;
}

/* ********** Operator Dasar HashMap ********* */
hashValueType ValueHash(HashMap M, hashKeyType k) {
    /* Menghasilkan nilai dari element dengan key K */
    /* Jika tidak ada key k pada M, akan mengembalikan UndefinedHash */
    hashAddress i = Hash(k);
    while (M.ElementsHash[i].Key != k && M.ElementsHash[i].Key != UndefinedHash) {
        i = (i + 1) % MaxElHash;
    }
    if (M.ElementsHash[i].Key == k) {
        return M.ElementsHash[i].Value;
    } else {
        return UndefinedHash;
    }
}
/* Mengembalikan nilai value dengan key k dari M */

void InsertHash(HashMap *M, hashKeyType k, hashValueType v) {
    if (M->CountHash < MaxElHash) {
        hashAddress i = Hash(k);
        while (M->ElementsHash[i].Key != UndefinedHash && M->ElementsHash[i].Key != k) {
            i = (i + 1) % MaxElHash;
        }
        if (M->ElementsHash[i].Key == UndefinedHash) {
            M->ElementsHash[i].Key = k;
            M->ElementsHash[i].Value = v;
            M->CountHash +;
        }
    }
}
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
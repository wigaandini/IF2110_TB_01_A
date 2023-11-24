#ifndef hashTagMap_H
#define hashTagMap_H
#include <stdio.h>
#include "boolean.h"

/**
 * Modul Hash HashMap
 * Implementasi Hash HashMap dengan Open Addressing
*/

// #define false 0
// #define true 1
#define NilHash 0
#define MaxElHash 100
#define UndefinedHash -9999

// typedef int bool;
typedef int hashKeyType;
typedef int hashValueType;
typedef int hashAddress;

typedef struct
{
	hashKeyType Key;
	hashValueType Value;
} hashType;

typedef struct
{
	hashType ElementsHash[MaxElHash];
	hashAddress CountHash;
} HashMap;

/* Definisi HashMap M kosong : M.CountHash = NilHash */
/* M.CountHash = jumlah element HashMap */
/* M.ElementsHash = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxElHash */
/* Ciri HashMap kosong : count bernilai NilHash dengan seluruh isi key & value map UndefinedHash */

/* *** Index Penyimpanan dengan modulo *** */
hashAddress Hash(hashKeyType K);
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxElHash */

/* ********** Operator Dasar HashMap ********* */
hashValueType Value(HashMap M, hashKeyType k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan UndefinedHash */

void Insert(HashMap *M, hashKeyType k, hashValueType v);
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing linear probing dengan interval 1 jika index sudah terisi    */

#endif
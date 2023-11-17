#ifndef adtkicauan_H
#define adtkicauan_H

#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "time.h"
#include "datetime.h"
#include "liststatikuser.h"
#include "friendmatrix.h"

#define CAPACITYMAXLISTKICAUAN 100
#define IDX_MIN 0
#define IDX_UNDEF -1

/* *** Definisi TYPE Kicauan <id, text, like, idauthor, waktu, tipekicauan, sambunganUtas, balasan> *** */

typedef struct node *Address;
typedef struct {
    int id;         //id kicauan
    Word text;    //text kicauan
    int like;       //jumlah like kicauan
    int idauthor;   //id author
    DATETIME waktu; //waktu unggah kicauan
    //tipekicauan
    Address sambunganUtas;  //address sambungan utas
    Address balasan;        //list of address balasan(?)
} Kicauan;

typedef struct {
    Kicauan *buffer;
    int nEff;  
    int capacity; 
} ListKicauan;

/* *** Notasi Akses: selektor Kicauan *** */
#define ID(K) (K).id
#define TEXT(K) (K).text
#define LIKE(K) (K).like
#define IDAUTHOR(K) (K).idauthor
#define WAKTU(K) (K).waktu
#define UTAS(K) (K).sambunganUtas
#define BALASAN(K) (K).balasan

#define NEFFLISTKICAU(L) (L).nEff
#define BUFFERLISTKICAU(L) (L).buffer
#define ELMTLISTKICAU(L, i) (L).buffer[i]
#define CAPACITYKICAU(L) (L).capacity

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */

/* *** Konstruktor: Membentuk sebuah  List Kicauan dari komponen-komponennya *** */
void CreateListGlobalKicauan(ListKicauan *l, int capacity);
/* Menyimpan seluruh kicauan yang telah dibuat */
/* Prekondisi : list kosong */

/* ********** Test Indeks yang valid ********** */
boolean isIdKicauanValid(ListKicauan l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListKicauanEmpty(ListKicauan l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */

/* *** Test list penuh *** */
boolean isListKicauanFull(ListKicauan l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

IdxType getLastIdxKicau(ListKicauan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* *** Menambahkan elemen terakhir *** */
void insertLastKicauan(ListKicauan *l, Kicauan val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* *** Konstruktor: Membentuk sebuah Kicauan dari komponen-komponennya *** */
void CreateKicauan(Kicauan *k, int id, Word text, int idauthor, DATETIME waktu);
/* Membentuk sebuah Kicauan dari komponen-komponennya yang valid */
/* Prekondisi : - id valid
                - text berupa string hasil input kicauan
                - like bernilai 0
                - idauthor bergantung pada id pengguna yang sedang masuk
                - waktu bergantung pada waktu pengguna selesai menggunakan mesin kata untuk menulis text
                - sambunganUtas bernilai NULL
                - balasan bernilai NULL
*/

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void DisplaySatuKicau(ListStatikUser l, Kicauan k);
/* I.S. : Kicauan terdefinisi*/
/* F.S. : Menampilkan seluruh komponen kicauan ke layar*/
/* Proses : Membaca komponen id, text, like, idauthor,
    dan waktu kemudian menampilkannnya ke layar*/

#endif
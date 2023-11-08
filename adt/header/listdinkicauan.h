#ifndef adtkicauan_H
#define adtkicauan_H

#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "time.h"
#include "datetime.h"
#include "string.h"
#include "liststatikuser.h"
#include "friendmatrix.h"


#define CAPACITYTEXTKICAU 1000
#define CAPACITYMAXLISTKICAUAN 100
#define IDX_MIN 0
#define IDX_UNDEF -1

/* *** Definisi TYPE Kicauan <id, text, like, idauthor, waktu, tipekicauan, sambunganUtas, balasan> *** */

typedef struct node *Address;
typedef struct {
    int id;         //id kicauan
    String text;    //text kicauan
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
void CreateKicauan(Kicauan *k, int id, String text, int idauthor, DATETIME waktu);
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
void DisplaySatuKicau(Kicauan k);
/* I.S. : Kicauan terdefinisi*/
/* F.S. : Menampilkan seluruh komponen kicauan ke layar*/
/* Proses : Membaca komponen id, text, like, idauthor,
    dan waktu kemudian menampilkannnya ke layar*/

void Berkicau(ListKicauan *l, Kicauan *k, int idauthor);
/* I.S. : Kicauan tidak terdefinisi */
/* F.S. : Kicauan terdefinisi dan merupakan kicauan yang valid */
/* Proses : Membaca komponen id, text, idauthor, dan waktu sehingga membentuk Kicauan
    yang valid. Tidak mungkin menghasilkan Simulator yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen text, membaca file Konfigurasi Kicauan untuk mendapat id kicauan 
    dan melakukan increment terhadap id kicauan terakhir, mengambil data pengguna untuk idauthor, serta membaca waktu.*/

void DisplayKicauan(ListStatikUser l, ListKicauan k, int idUser, FriendMatrix m);
/* I.S. : File konfigurasi kicauan terdefinisi*/
/* F.S. : Menampilkan seluruh komponen kicauan dari akun yang berteman dengan akun pengguna dan kicauan dirinya sendiri*/
/* Proses : Membaca file konfigurasi kicauan, mengidentifikasi tiap kicauan yang ada dalam file konfigurasi dan menampilkannya
    dengan kondisi (idauthor berteman dengan pengguna atau idauthor bersifat publik)*/

/* ***************************************************************** */
/* OPERASI LAINNYA                                             */
/* ***************************************************************** */

void SUKA_KICAUAN(ListStatikUser l, ListKicauan *k, int idKicauan, int idUser, FriendMatrix m);
/* I.S. : Kicauan terdefinisi */
/* F.S. : Apabila suatu kicauan dapat diakses oleh pengguna (isBerteman dengan idauthor true atau idauthor publik)
    jumlah like diincrement*/

void UBAH_KICAUAN(ListStatikUser l, ListKicauan *k, int idKicauan, int idUser);
/* I.S. : Kicauan terdefinisi*/
/* F.S. : Isi text kicauan berubah sesuai dengan perubahan yang dilakukan pengguna*/

#endif
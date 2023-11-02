#ifndef adtkicauan_H
#define adtkicauan_H

#include "header/boolean.h"
#include "header/listdin.h"
#include "header/charmachine.h"
#include "header/wordmachine.h"
#include "header/time.h"
#include "header/datetime.h"

#define CAPACITY 280

/* Definisi elemen dan address */
typedef struct
{
    char buffer[CAPACITY];
    int length;
} String;


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
    Address balasan;        //list of address balasan
} Kicauan;


/* *** Notasi Akses: selektor Kicauan *** */
#define ID(K) (K).id
#define TEXT(K) (K).text
#define LIKE(K) (K).like
#define IDAUTHOR(K) (K).idauthor
#define WAKTU(K) (K).waktu
#define UTAS(K) (K).sambunganUtas
#define BALASAN(K) (K).balasan

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */

/* *** Konstruktor: Membentuk sebuah Kicauan dari komponen-komponennya *** */
void CreateKicauan(Kicauan *k, int id, String text, int like, int idauthor, DATETIME waktu);
/* Membentuk sebuah Kicauan dari komponen-komponennya yang valid */
/* Prekondisi : - id valid
                - text berupa string kosong
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

void Kicau(Kicauan *k);
/* I.S. : Kicauan tidak terdefinisi */
/* F.S. : Kicauan terdefinisi dan merupakan kicauan yang valid */
/* Proses : Membaca komponen id, text, idauthor, dan waktu sehingga membentuk Kicauan
    yang valid. Tidak mungkin menghasilkan Simulator yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen text, membaca file Konfigurasi Kicauan untuk mendapat id kicauan 
    dan melakukan increment terhadap id kicauan terakhir, mengambil data pengguna untuk idauthor, serta membaca waktu.*/

void DisplayKicauan();
/* I.S. : File konfigurasi kicauan terdefinisi*/
/* F.S. : Menampilkan seluruh komponen kicauan dari akun yang berteman dengan akun pengguna dan kicauan dirinya sendiri*/
/* Proses : Membaca file konfigurasi kicauan, mengidentifikasi tiap kicauan yang ada dalam file konfigurasi dan menampilkannya
    dengan kondisi (idauthor berteman dengan pengguna atau idauthor bersifat publik)*/

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test text kicauan penuh *** */
boolean isKicauFull(String text);
/* Mengirimkan true jika text kicauan penuh, yaitu jika panjang string mencapai 280,
    mengirimkan false jika tidak penuh*/

/* ***************************************************************** */
/* OPERASI LAINNYA                                             */
/* ***************************************************************** */

void SUKA_KICAUAN(Kicauan *k);
/* I.S. : Kicauan terdefinisi */
/* F.S. : Apabila suatu kicauan dapat diakses oleh pengguna (isBerteman dengan idauthor true atau idauthor publik)
    jumlah like diincrement*/
/* Proses : */

void UBAH_KICAUAN(Kicauan *k);
/* I.S. : Kicauan terdefinisi*/
/* F.S. : Isi text kicauan berubah sesuai dengan perubahan yang dilakukan pengguna*/
/* Proses : */

#endif
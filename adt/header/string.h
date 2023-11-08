/* File : string.h */
/* Definisi ADT String */

#ifndef STRING_H
#define STRING_H

#include "boolean.h"
#include "wordmachine.h"
#include "charmachine.h"

#define CAPACITYSTRING 1000

/* Definisi elemen dan address */
typedef char ElType;
typedef struct
{
    ElType buffer[CAPACITYSTRING];
    int length;
} String;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah String, maka : */
#define LENGTH(s) (s).length
#define ELMT_STRING(s, i) (s).buffer[(i)]

/* *** Kreator *** */
/* I.S. sembarang */
/* F.S. Sebuah s kosong terbentuk dengan kondisi length = 0 */
/* Proses : Melakukan alokasi, membuat sebuah string kosong */
void CreateString(String *s);

/* ********* Prototype ********* */
/* Mengirim true jika s kosong */
boolean isStringEmpty(String s);

/* Mengirim true jika tabel penampung elemen s sudah penuh */
boolean isStringFull(String s);

/* Mengirimkan banyaknya elemen string. Mengirimkan 0 jika q kosong. */
int stringLength(String s);

/* *** Primitif Konstruktor *** */

/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. s mungkin kosong, tabel penampung elemen s TIDAK penuh */
/* F.S. s diisi elemen sebanyak n (diminta input) */
void readString(String *s);

/* *** Menghapus elemen terakhir *** */
/* Proses : Menghapus elemen terakhir String */
/* I.S. String tidak kosong */
/* F.S. c adalah nilai elemen terakhir s sebelum penghapusan, */
/*      Banyaknya elemen String berkurang satu */
/*      String s mungkin menjadi kosong */
void deleteSLast(String *s, ElType *c);

/* *** Display *** */

/* Proses : Menuliskan isi String dengan traversal, */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: "s1s2s3" */
/* Jika String kosong : menulis "" */
void displayString(String s);

/* *** Konversi tipe *** */
String wordToStringforADTstring(Word w);

void procwordToString(Word w, String *s);

void charToString(char c[], String *s, int len);

#endif
/* File : string.h */
/* Definisi ADT String */

#include "header/boolean.h"
#include "header/string.h"
#include "header/wordmachine.h"
#include "header/charmachine.h"
#include <stdio.h>

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah String, maka : */
//#define LENGTH(s) (s).length
//#define ELMT(s, i) (s).buffer[(i)]

/* *** Kreator *** */
/* I.S. sembarang */
/* F.S. Sebuah s kosong terbentuk dengan kondisi length = 0 */
/* Proses : Melakukan alokasi, membuat sebuah string kosong */
void CreateString(String *s)
{
    LENGTH(*s) = 0;
}

/* ********* Prototype ********* */
/* Mengirim true jika s kosong */
boolean isStringEmpty(String s)
{
    return LENGTH(s) == 0;
}

/* Mengirim true jika tabel penampung elemen s sudah penuh */
boolean isStringFull(String s)
{
    return LENGTH(s) == CAPACITYSTRING;
}

/* Mengirimkan banyaknya elemen string. Mengirimkan 0 jika q kosong. */
int stringLength(String s)
{
    return LENGTH(s);
}

/* *** Primitif Konstruktor *** */

/* Proses: Menambahkan char pada s dengan aturan FIFO */
/* I.S. s mungkin kosong, tabel penampung elemen s TIDAK penuh */
/* F.S. s diisi oleh input string */
void readString(String *s)
{
    // ALGORITMA
    CreateString(s);
    STARTSENTENCE();
    *s = wordToStringforADTstring(currentWord);
}

/* *** Display *** */

/* Proses : Menuliskan isi String dengan traversal, */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: "s1s2s3" */
/* Jika String kosong : menulis "" */
void displayString(String s)
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    if (LENGTH(s) == 0)
    {
        printf("String kosong\n");
    }
    else
    {
        for (i = 0; i < LENGTH(s); i++)
        {
            printf("%c", ELMT_STRING(s, i));
        }
    }
}

/* *** Menghapus elemen terakhir *** */
/* Proses : Menghapus elemen terakhir String */
/* I.S. String tidak kosong */
/* F.S. c adalah nilai elemen terakhir s sebelum penghapusan, */
/*      Banyaknya elemen String berkurang satu */
/*      String s mungkin menjadi kosong */
void deleteSLast(String *s, ElType *c)
{
    // KAMUS LOKAL

    // ALGORITMA
    if (isStringEmpty(*s) != true)
    {
        *c = ELMT_STRING(*s, LENGTH(*s) - 1);

        LENGTH(*s)
        --;
    }
}


/* *** Konversi tipe Word menjadi tipe String *** */
String wordToStringforADTstring(Word w)
{
    // KAMUS LOKAL
    String s;
    int i;
    // ALGORITMA
    CreateString(&s);
    LENGTH(s) = w.Length;
    for (i = 0; i < LENGTH(s); i++)
    {
        ELMT_STRING(s, i) = w.TabWord[i];
    }

    return s;
}

void procwordToString(Word w, String *s)
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    LENGTH(*s) = w.Length;
    for (i = 0; i < LENGTH(*s); i++)
    {
        ELMT_STRING(*s, i) = w.TabWord[i];
    }
}

void charToString(char c[], String *s, int len)
{
    LENGTH(*s) = len;
    for (int i = 0; i < len; i++)
    {
        ELMT_STRING(*s, i) = c[i];
    }
}
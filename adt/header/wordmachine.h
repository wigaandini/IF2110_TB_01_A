/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __WORDMACHINE_H__
#define __WORDMACHINE_H__

#include "../adt/boolean.h"
#include "charmachine.h"

#define NMax 280
#define BLANK ' '
#define ENTER '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

// typedef char ElType;
// typedef struct
// {
//     ElType buffer[CAPACITY];
//     int length;
// } String;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void IgnoreEnter();

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void LowerCase();
/* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
/* F.S. currentword menjadi lowercase di setiap karakternya */

void IgnoreNotEnter();

void CopySpace();

void STARTSENTENCE();

void STARTWORDFILE(char namaFile[]);

void ADVNEWLINE();

char* WordToString(Word word);

int WordToInt(Word str);

boolean compareWord(Word str1, Word str2);

void displayWord(Word word);

<<<<<<< HEAD:adt/wordmachine/wordmachine.h
=======
void displayString(char* str);

>>>>>>> main:adt/header/wordmachine.h
boolean WordIsInt(Word kata);

boolean CharIsInt(char c);

boolean compareString(Word str1, char str2[]);

Word stringToWord(char str[], int len);

Word MergeWord(Word word1, Word word2);

<<<<<<< HEAD:adt/wordmachine/wordmachine.h
=======
int StringToInt(char *str);

Word splitCommand(Word *w, Word command, int kataKe);

int lengthWord(Word w);

boolean isEmptyWord(Word w);

void LowerCase();
/* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
/* F.S. currentword menjadi lowercase di setiap karakternya */

int countWords(Word w);
/* Menghitung jumlah kata di suatu kalimat */

int lengthString(char *str);
/* Menghitung panjang string */
>>>>>>> main:adt/header/wordmachine.h
#endif
/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
    while (currentChar == BLANK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(){
    START();
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    }
    else{
        EndWord = false;
        CopyWord();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD(){
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    }
    else{
        CopyWord();
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord(){
    int i;
    i = 0;
    while(currentChar != MARK && currentChar != BLANK){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i ++;
    currentWord.Length = i;
    }

    if (currentWord.Length > NMax){
        currentWord.Length = NMax;
    }
    else{
        currentWord.Length = i;
    }
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void LowerCase(){
    int i;
    for(i = 0; i < currentWord.Length; i++){
        if(currentWord.TabWord[i] >= 65 && currentWord.TabWord[i] <= 90){
            currentWord.TabWord[i] += 32;
        }
    }
}
/* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
/* F.S. currentword menjadi lowercase di setiap karakternya */
// {
//    int i;
//    for (i = 0; i < currentWord.Length; i++){
//       if (currentWord.TabWord[i] >= 'A' && currentWord.TabWord[i] <= 'Z'){
//          currentWord.TabWord[i] = currentWord.TabWord[i] + 'a' - 'A';
//       }
//    }
// }
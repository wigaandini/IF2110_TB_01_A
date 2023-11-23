/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#include <stdio.h>
#include <stdlib.h>
#include "header/boolean.h"
#include "header/charmachine.h"
#include "header/wordmachine.h"

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
    IgnoreEnter();
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    }
    else{
        CopyWord();
        IgnoreEnter();
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord(){
    int i = 0;
    while ((currentChar != ENTER) && (currentChar != BLANK) && currentChar != MARK){
        if (i == NMax){
            break;
        }
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
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

void IgnoreNotEnter(){
    while (currentChar == BLANK) {
        ADV();
    }
}

void IgnoreEnter(){
    while (currentChar == ENTER) {
        ADV();
    }
}

void CopySpace(){
    int i = 0;
    while (currentChar != MARK){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i > NMax){
        currentWord.Length = NMax;
    }
    else{
        currentWord.Length = i;
    }
}

void STARTSENTENCE(){
    START();
    IgnoreEnter();
    IgnoreBlanks();
    for (int i = 0; i < NMax; i++) {
        currentWord.TabWord[i] = '\0'; 
    }
    currentWord.Length = 0;
    if(currentChar == MARK){
        EndWord = true;
    }
    else{
        EndWord = false;
        CopySpace();
    }
}

char* WordToString(Word word){
    char* str = (char*) malloc (word.Length+1);
    int i;
    for (i = 0; i<word.Length;i++){
        str[i] = word.TabWord[i];
    }
    str[word.Length] = '\0';
    return str;
}

int WordToInt(Word str){
    int result = 0;
    int i;

    for (i = 0; i < str.Length; i++) {
        if (str.TabWord[i] >= '0' && str.TabWord[i] <= '9') {
            result = result * 10 + (str.TabWord[i] - '0');
        } else {
            return 0;
        }
    }

    if (result < 0) {
        int digit = 1;
        for (i = 0; i < str.Length - 1; i++) {
            digit = digit * 10;
        }
        result += 38 * digit;
    }

    return result;
}

boolean compareWord(Word str1, Word str2){
    int i;
    if (str1.Length != str2.Length){
        return false;
    } 
    else {
        for (i = 0; i < str1.Length-1; i++){
            if (str1.TabWord[i] != str2.TabWord[i]){
                return false;
            }
        }
    }
    return true;
}

void displayWord(Word word) {
    int i = 0;
    for (i = 0; i < word.Length; i++) {
        if(word.TabWord[i] != MARK){
            printf("%c", word.TabWord[i]);
        }
    }
}

void displayString(char* str){
    int i = 0;
    while (str[i] != '\0'){
        printf("%c", str[i]);
        i++;
    }
}

boolean WordIsInt(Word kata){
    int i;
    boolean cek = false;
    for (i = 0; i < kata.Length; i++){
        if (kata.TabWord[i] <= 57 &&kata.TabWord[i] >= 48){
            cek = true;
        }
    }
    return cek;
}

boolean CharIsInt(char c){
    if (c <= 57 && c >= 48){
        return true;
    }
    else{
        return false;
    }
}

boolean compareString(Word str1, char* str2){
    int i;
    for (i = 0; i < str1.Length; i++){
        if (str1.TabWord[i] != str2[i]){
            return false;
        }
    }
    return true;
}

Word stringToWord(char str[], int len){
    int i;
    Word strWord;
    strWord.Length = len;
    for (i = 0; i < len; i++){
        strWord.TabWord[i] = str[i];
    }
    return strWord;
}

Word MergeWord(Word word1, Word word2){
    int i;
    Word res = {"",0};
    res = word1;
    res.Length += word2.Length + 1;
    res.TabWord[word1.Length] = BLANK;
    for (i = 0; i < word2.Length; i++){
        res.TabWord[word1.Length+1+i] = word2.TabWord[i];
    }
    return res;
}

int StringToInt(char *str) {
    int result = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
            i++;
        } 
        else {
            return 0;
        }
    }

    return result;
}

Word splitCommand(Word *w, Word command, int kataKe){
    int i = 0, counter = 0, length = 0;
    boolean stop;

    while (counter != kataKe - 1 && i < command.Length){
        stop = false;
        if (command.TabWord[i] == ' '){
            counter++;
            while (i < command.Length && !stop){
                i++;
                if (command.TabWord[i] != ' '){
                    stop = true;
                }
            }
        }
        else {
            i++;
        }

        if (i == command.Length){
            counter++;
        }
    }

    stop = false;
    while (!stop && i < command.Length) {
        if (command.TabWord[i] == ' '){
            stop = true;
        }
        else{
            w->TabWord[length] = command.TabWord[i];
            i++;
            length++;
        }
    }
    w->Length = length;
    return *w;
}

int lengthWord(Word w){
    int length = 0;
    for(int i = 0; i<w.Length; i++){
        if(w.TabWord[i] != BLANK && i != w.Length){
            length++;
        }
    }
    return length;
}

boolean isEmptyWord(Word w){
    return (lengthWord(w) == 0);
}

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


int countWords(Word w) {
    int count = 0;
    int isWord = 0; 

    for (int i = 0; i < w.Length; i++) {
        if (w.TabWord[i] == ' ' || w.TabWord[i] == '\t') {
            isWord = 0;
        }
        else if (isWord == 0) {
            isWord = 1;
            count++;
        }
    }
    return count;
}
/* Menghitung jumlah kata di suatu kalimat */

int lengthString(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
/* Menghitung panjang string */

void concatenate(char *str,char *str2,char *str3) {
    while (*str2) {
        *str++ = *str2++;
    }
    while (*str3) {
        *str++ = *str3++;
    }
    *str = '\0';
}
/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void IgnoreNotEnter(){
    while (currentChar == BLANK) {
        ADV();
    }
}

void CopySpace(){
    int i = 0;
    while (currentChar != LineMARK){
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
    if (currentChar=='\n'){
        EndWord = true;
    }
    else{
        EndWord = false;
        CopySpace();
    }
}

void STARTWORDFILE(char namaFile[]){
    STARTFILE(namaFile);
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    }
    else{
        EndWord = false;
        ADVWORD();
    }
}

void ADVNEWLINE(){
    Word kosong = {"", 0};
    currentWord = kosong;
    if(currentChar == MARK){
        EndWord = false;
        ADV();
        CopyWord();
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
    for (i=0; i<str.Length; i++){
        result = result * 10 + (str.TabWord[i] - 48);
    }
    if (result < 0){
        int digit = 1;
        for (i=0; i<str.Length-1; i++){
            digit = digit * 10;
        }
        result += 38 * digit;
    }
    return result;
}

boolean compareWord(Word str1, Word str2){
    int idx;
    int i;
    if (str1.Length != str2.Length){
        return false;
    } 
    else {
        for (i = 0; i < str1.Length; i++){
            if (str1.TabWord[i] != str2.TabWord[i]){
                return false;
            }
        }
    }
    return true;
}

void displayWord(Word word){
    int i;
    for (i = 0; i < word.Length-1; i++){
        printf("%c", word.TabWord[i]);
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
    for (i = 0; i < str1.Length-1; i++){
        if (str1.TabWord[i] != str2[i]){
            // displayWord(str1);
            // printf("\n");
            // printf("%c", str2);
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

    while (counter != kataKe - 1 && i < command.Length  + 1){
        stop = false;
        if (command.TabWord[i] == ' '){
            counter++;
            while (i < command.Length && !stop){
                i++;
                if (command.TabWord[i] != ' ')
                {
                    stop = true;
                }
            }
        }
        else if(command.TabWord[i] == MARK){
            stop = true;
        }
        else{
            i++;
        }

        if (i == command.Length  + 1){
            counter++;
        }
    }

    stop = false;
    while (!stop && i < command.Length  + 1){
        if (command.TabWord[i] == ' '){
            stop = true;
        }
        else if(command.TabWord[i] == MARK){
            stop = true;
        }
        else{
            w->TabWord[length] = command.TabWord[i];
            i++;
            length++;
        }
    }
    w->Length = length + 1;
    return *w;
}

char* MergeString(char* str1, char* str2) {
    // Calculate the lengths of the input strings
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    // Allocate memory for the merged string
    char* merged = (char*)malloc((len1 + len2 + 1) * sizeof(char));

    // Check if memory allocation was successful
    if (merged == NULL) {
        fprintf(stderr, "Memory allocation failed");
        return NULL;
    }

    // Copy the contents of str1 and str2 into the merged string
    strcpy(merged, str1);
    strcat(merged, str2);

    return merged;
}
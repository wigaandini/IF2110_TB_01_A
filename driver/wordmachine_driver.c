#include <stdio.h>
#include "../adt/wordmachine.c"
#include "../adt/charmachine.c"

int main() {
    char input[100];

    printf("Masukkan kalimat: ");
    // fgets(input, sizeof(input), stdin);

    // Menggunakan STARTSENTENCE
    STARTSENTENCE();
    printf("Kalimat hasil STARTSENTENCES: ");
    displayWord(currentWord);
    Word sentence = currentWord;
    printf("\n");

    // Menguji startword
    printf("Menguji STARTWORD:\n");
    printf("Masukkan kata kata: \n");
    STARTWORD();
    while (!EndWord) {
        displayWord(currentWord);
        printf("\n");

        ADVWORD();
    }

    // Mengubah currentWord menjadi sentence
    currentWord = sentence;

    // Menguji Lowercase
    printf("\nKalimat hasil LowerCase: ");
    LowerCase();
    displayWord(currentWord);
    printf("\n");

    // Menguji countWords
    printf("Jumlah kata dalam kalimat hasil LowerCase: %d\n", countWords(currentWord));
    printf("\n");

    // Menguji WordIsInt
    printf("Menguji WordIsInt\n");
    printf("Masukkan kalimat: ");
    STARTSENTENCE();
    if (WordIsInt(currentWord)) {
        printf("Kata dapat diubah menjadi integer.\n");

        // Menguji WordToInt
        int value = WordToInt(currentWord);
        printf("Nilai integer: %d\n", value);
    } else {
        printf("Kata tidak dapat diubah menjadi integer.\n");
    }
    printf("\n");

    // Menguji WordToString
    printf("Menguji WordToString\n");
    printf("Masukkan kalimat: ");
    STARTSENTENCE();
    char* str = WordToString(currentWord);
    printf("Kata sebagai string: %s\n", str);
    printf("\n");

    // Menguji compareWord
    printf("Menguji compareWord\n");
    printf("Masukkan kalimat: ");
    STARTSENTENCE();
    Word comparisonWord = {"test", 4};
    if (compareWord(currentWord, comparisonWord)) {
        printf("Kata sama dengan 'test'.\n");
    } else {
        printf("Kata tidak sama dengan 'test'.\n");
    }
    printf("\n");

    // Menguji mergeWord
    printf("Menguji mergeWord\n");
    Word word1 = {"Hello", 5};
    Word word2 = {"World", 5};
    printf("Kata pertama: ");
    displayWord(word1);
    printf("\n");
    printf("Kata kedua: ");
    displayWord(word2);
    printf("\n");
    Word mergedWord = MergeWord(word1, word2);
    printf("Gabungan kata: ");
    displayWord(mergedWord);
    printf("\n");
    printf("\n");


    Word str1 = {"Hello", 5};
    Word str2 = {"World", 5};

    // Uji fungsi compareString
    printf("Hasil compareString: %d\n", compareString(str1, "Hello")); // Seharusnya 1 (true)
    printf("Hasil compareString: %d\n", compareString(str1, "hello")); // Seharusnya 0 (false)
    printf("Hasil compareString: %d\n", compareString(str1, "Hi"));    // Seharusnya 0 (false)

    // Uji fungsi splitCommand
    Word w;
    Word command = {"Hello World", 11};
    splitCommand(&w, command, 2);
    printf("Hasil splitCommand: ");
    displayWord(w);  // Seharusnya mencetak "World"

    // Uji fungsi lengthString
    char sampleString[] = "Ini adalah contoh string";
    int length = lengthString(sampleString);
    printf("\nPanjang string: %d\n", length);  // Seharusnya 24


    return 0;
}

#include <stdio.h>
#include "../program/profil.c"
#include "../adt/liststatikuser.c"
#include "../adt/wordmachine.c"
#include "../adt/charmachine.c"
#include "../adt/pcolor.c"
#include "../adt/matrix.c"
#include "../adt/listdin.c"

int main () {
    STARTSENTENCE();
    if (compareString(currentWord, "")) {
        printf("Kosong\n");
    }
    // Print currentword dengan menambahkan '\' di setiap char nya
    // for (int i = 0; i < currentWord.Length; i++) {
    //     printf("\\%c", currentWord.TabWord[i]);
    // }
    // printf("\\\n");
    return 0;
}
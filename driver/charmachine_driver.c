#include "../adt/charmachine.c"
#include <stdio.h>

int main() {
    // Uji fungsi START dan ADV dari pita stdin
    printf("Uji fungsi START dan ADV dari pita stdin:\n");
    START();
    while (!EOP) {
        printf("%c", currentChar);
        ADV();
    }
    printf("\n\n");

    return 0;
}

#include <stdio.h>
#include "../adt/configmachine.c"
#include "../adt/charmachine.c"

int main() {
    // Uji fungsi STARTconfig dan ADVconfig
    char namaFile[] = "../config/kicauan.config"; // Ganti dengan nama file yang sesuai
    printf("Uji fungsi STARTconfig dan ADVconfig:\n");
    STARTconfig(namaFile);
    while (!EOP) {
        printf("%c", currentChar);
        ADVconfig();
    }

    return 0;
}

#include "../adt/liststatikuser.c"
#include "../adt/wordmachine.c"
#include "../adt/charmachine.c"
#include "../adt/matrix.c"
#include "../adt/pcolor.c"
#include "../adt/listdin.c"

#define here printf("here\n");

int main () {
    ListStatikUser l;
    CreateListStatikUser(&l);
    Word nama, pw;
    nama.Length = 4;
    nama.TabWord[0] = 'c';
    nama.TabWord[1] = 'a';
    nama.TabWord[2] = 'c';
    nama.TabWord[3] = 'a';

    pw.Length = 4;
    pw.TabWord[0] = 'p';
    pw.TabWord[1] = 'w';
    pw.TabWord[2] = 'c';
    pw.TabWord[3] = 'a';
    addUser(&l, nama, pw);

    printListofUser(l);
    printf("%d\n", banyakUser(l));
    return 0;
}
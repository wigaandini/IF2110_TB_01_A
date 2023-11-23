#include "../adt/liststatikuser.c"
#include "../adt/wordmachine.c"
#include "../adt/charmachine.c"
#include "../adt/matrix.c"
#include "../adt/pcolor.c"
#include "../adt/listdin.c"
#include "../adt/prioreqfollinked.c"
#include "../adt/draf.c"
#include "../adt/stack.c"
#include "../adt/datetime.c"
#include "../adt/time.c"
#include "../adt/friendmatrix.c"


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
    

    isUserDataEmpty(l);

    isUserDataEmpty(l);

    isUserDataFull(l);

    

    printListofUser(l);
    printf("%d\n", banyakUser(l));
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../adt/header/boolean.h"
#include "../adt/wordmachine.c"
#include "../adt/listlinierutas.c"
#include "../adt/listdinkicauan.c"
#include "../adt/liststatikuser.c"
#include "../adt/charmachine.c"
#include "../adt/datetime.c"
#include "../adt/friendmatrix.c"
#include "../program/utas.c"
#include "../adt/time.c"
#include "../adt/matrix.c"
#include "../adt/listdin.c"
#include "../adt/pcolor.c"
#include "../program/user.c"

// tes nya ucup
int main() {
    ListStatikUser users;
    CreateListStatikUser(&users);

    boolean isLoggedIn = false;
    int id_login = 0;

    printf("### TESTING DAFTAR FUNCTION ###\n");
    printf("### Case 1: Register new user ###\n");
    DAFTAR(&users, isLoggedIn);

    // printListofUser(users);

    printf("\n### Case 2: Trying to register when already logged in ###\n");
    isLoggedIn = true;
    DAFTAR(&users, isLoggedIn);

    // printListofUser(users);

    isLoggedIn = false;
    printf("\n### Case 3: Fill up user data ###\n");
    for (int i = 0; i < 2; i++) {
        DAFTAR(&users, isLoggedIn);
        // printListofUser(users);
    }

    // printListofUser(users);
    // exit(0);

    printf("\n### TESTING MASUK FUNCTION ###\n");
    printf("### Case 1: Login with correct credentials ###\n");
    isLoggedIn = false;
    MASUK(&users, &isLoggedIn, &id_login);

    printf("\n### Case 2: Trying to login when already logged in ###\n");
    isLoggedIn = true;
    MASUK(&users, &isLoggedIn, &id_login);

    printf("\n### Case 3: Login with incorrect credentials ###\n");
    isLoggedIn = false;
    MASUK(&users, &isLoggedIn, &id_login);

    printf("\n### TESTING KELUAR FUNCTION ###\n");
    printf("### Case 1: Logout when not logged in ###\n");
    isLoggedIn = false;
    KELUAR(&users, &isLoggedIn, &id_login);

    printf("\n### Case 2: Logout when logged in ###\n");
    isLoggedIn = true;
    KELUAR(&users, &isLoggedIn, &id_login);

    printf("\n### TESTING TUTUP_PROGRAM FUNCTION ###\n");
    TUTUP_PROGRAM();

    return 0;
}

// test nya wiga
// int main(){
//     ListStatikUser l;
//     CreateListStatikUser(&l);
//     boolean login = false;

//     do {
//         printf(">> ");
//         STARTSENTENCE();
//         displayWord(currentWord);
//         printf("\n");

//         if (compareString(currentWord, "DAFTAR")) {
//             DAFTAR(&l, login);
//             printListofUser(l);
//         } else if (compareString(currentWord, "KELUAR")) {
//             KELUAR(&login);  // Pass login by reference
//         } else if (compareString(currentWord, "MASUK")) {
//             MASUK(&l, &login);  // Pass login and username by reference
//         } else if (compareString(currentWord, "TUTUP_PROGRAM")) {
//             TUTUP_PROGRAM();
//         }
//     } while (!compareString(currentWord, "TUTUP_PROGRAM"));

//     return 0;
// }

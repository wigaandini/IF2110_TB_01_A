#include "readpengguna.c"
#include "readkicauan.c"
#include "readdraf.c"
#include "readbalasan.c"
#include "readutas.c"
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>

void delay(float sec) {
    clock_t start = clock();
    clock_t wait = sec * CLOCKS_PER_SEC;
    while (clock() < start + wait);
}

boolean is_directory(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
        return 0;
    return S_ISDIR(statbuf.st_mode);
}

void MUAT(ListStatikUser *l,ListKicauan *k,FriendMatrix *F, int *curIdBalasan){
    char fullPath[200];
    char *dirName;

    CreateListStatikUser(l);
    int i;
    for (i = 0; i < NEFFLISTKICAU(*k); i++) {
        free(k->buffer[i].sambunganUtas);
        free(k->buffer[i].balasan);
    }
    // free(k);

    CreateListGlobalKicauan(k, CAPACITYMAXLISTKICAUAN);

    printf("\nMasukkan nama folder yang hendak dimuat.\n");
    Word config;
    STARTSENTENCE();

    config = currentWord;
    dirName = WordToString(config);
    concatenate(fullPath, "config/", dirName);
    if (!is_directory(fullPath)){
        printf("\nTidak ada folder yang dimaksud.\n\n");
    } else{
        ReadUser(l,F,fullPath);
        ReadKicauan(k,*l,*F,fullPath);
        readbalasan(l,k,fullPath, curIdBalasan);
        ReadDraf(l,fullPath);
        ReadUtas(k,*l,fullPath);

        // printListofUser(l);
        // DisplayAllKicauan(l,listKicau);
        printf("\n");
        printf("Anda akan melakukan pemuatan dari %s.\n\n",dirName);
        delay(0.5);
        printf("Mohon tunggu...\n");
        delay(0.5);
        printf("1...\n");
        delay(1);
        printf("2...\n");
        delay(1);
        printf("3...\n\n");
        delay(1);
        printf("Pemuatan selesai !\n\n");
    }
    free(dirName);
}
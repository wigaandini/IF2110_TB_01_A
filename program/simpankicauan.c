#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../adt/header/listdinkicauan.h"
#include "../adt/header/liststatikuser.h"

char* namaFileKicauan = "/kicauan.config";


void concatString(char *ans, char *p1, char *p2){
    while(*p1){
        *ans = *p1;
        p1++;
        ans++;
    }
    while (*p2){
       *ans = *p2;
       p2++;
       ans++;
    }
    *ans = '\0';
}

void simpankicauan(ListKicauan l, ListStatikUser lsu, char *namaFolder){
    int ch = mkdir(namaFolder);
    // GAGAL MAKEDIR CONTINUE
    /*if(ch == -1){
        printf("Failed creating new directory\n");
        return;
    }*/
    char namaFile[1000];
    concatString(namaFile, namaFolder, namaFileKicauan);
    FILE* fptr = fopen(namaFile, "ab+");
    if(fptr == NULL){
        printf("Failed making new file\n");
        return;
    }
    fprintf(fptr, "%d\n", NEFFLISTKICAU(l));
    int i;
    for(i = 0; i < NEFFLISTKICAU(l); ++i){
        fprintf(fptr, "%d\n", ELMTLISTKICAU(l, i).id);
        int j;
        for(j = 0; j < ELMTLISTKICAU(l, i).text.Length; ++j){
            fprintf(fptr, "%c", ELMTLISTKICAU(l, i).text.TabWord[j]);
        }
        fprintf(fptr, "\n");
        fprintf(fptr, "%d\n", ELMTLISTKICAU(l, i).like);
        for(j = 0; lsu.data[ELMTLISTKICAU(l, i).idauthor - 1].nama[j] != '\0'; ++j){
            fprintf(fptr, "%c", lsu.data[ELMTLISTKICAU(l, i).idauthor - 1].nama[j]);
        }
        fprintf(fptr, "\n");
        DATETIME curWaktu = ELMTLISTKICAU(l, i).waktu;
        fprintf(fptr, "%d/%d/%d %02d:%02d:%02d", curWaktu.DD, curWaktu.MM, curWaktu.YYYY, curWaktu.T.HH, curWaktu.T.MM, curWaktu.T.SS);
        fprintf(fptr, "\n");
        
    }
    fclose(fptr);
}

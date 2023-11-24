#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../adt/header/treebalasan.h"
#include "../adt/header/listdinkicauan.h"
#include "../adt/header/liststatikuser.h"

char* namaFileBalasan = "/balasan.config";

void writeRecursion(FILE* fptr, int par, AddressBalasan adr, ListStatikUser lsu){
    if(adr == NULL){
        return;
    }
    fprintf(fptr, "%d %d\n", par, adr->id);
    int i;
    for(i = 0; i < adr->teks.Length; ++i){
        fprintf(fptr, "%c", adr->teks.TabWord[i]);
    }
    fprintf(fptr, "\n");
    for(i = 0; lsu.data[adr->idPenulis - 1].nama[i] != '\0'; ++i){
        fprintf(fptr, "%c", lsu.data[adr->idPenulis - 1].nama[i]);
    }
    fprintf(fptr, "\n");
    fprintf(fptr, "%d/%d/%d %02d:%02d:%02d", adr->waktu.DD, adr->waktu.MM, adr->waktu.YYYY, adr->waktu.T.HH, adr->waktu.T.MM, adr->waktu.T.SS);
    fprintf(fptr, "\n");
    writeRecursion(fptr, par, SIBLINGBALASAN(*adr), lsu);
    writeRecursion(fptr, IDBALASAN(*adr), CHILDBALASAN(*adr), lsu);
}

// // void concatString(char *ans, char *p1, char *p2){
// //     while(*p1){
// //         *ans = *p1;
// //         p1++;
// //         ans++;
// //     }
// //     while (*p2){
// //        *ans = *p2;
// //        p2++;
// //        ans++;
// //     }
// //     *ans = '\0';
// // }

void simpanbalasan(ListKicauan l, ListStatikUser lsu, char *namaFolder){
    int ch = mkdir(namaFolder,0777);
    char namaFile[1000];
    concatString(namaFile, namaFolder, namaFileBalasan);
    FILE* fptr = fopen(namaFile, "w");
    if(fptr == NULL){
        printf("Failed making new file\n");
        return;
    }
    int i, cnt = 0;
    for(i = 0; i < NEFFLISTKICAU(l); ++i){
        if(ELMTLISTKICAU(l, i).balasan != NULL){
            cnt++;
        }
    }
    fprintf(fptr, "%d\n", cnt);
    for(i = 0; i < NEFFLISTKICAU(l); ++i){
        if(ELMTLISTKICAU(l, i).balasan != NULL){
            fprintf(fptr, "%d\n", ELMTLISTKICAU(l, i).id);
            fprintf(fptr, "%d\n", numBalasan(ELMTLISTKICAU(l, i).balasan));
            writeRecursion(fptr, -1, ELMTLISTKICAU(l, i).balasan, lsu);
        }
    }
    fclose(fptr);
}
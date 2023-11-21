#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "header/treebalasan.h"
#include "header/listdinkicauan.h"
#include "header/liststatikuser.h"

const char* namaFileDraf = "/draf.config";

char *inputNamaFolder(FILE *stream){
    char *str;
    char ch;
    int len = 0, size = 1;
    str = realloc(NULL, sizeof(*str));
    if(str == NULL){
        return str;
    }
    while((scanf("%c", &ch)) && ch != '\n'){
        str[len++] = ch;
        if(len == size){
            str = realloc(str, sizeof(*str) * (size + 10));
            size += 10;
            if(str == NULL){
                return str;
            }
        }
    }
    str[len++] = '\0';
    return realloc(str, sizeof(*str) * len);
}

void writeRecursion(FILE* fptr, int par, AddressBalasan adr, ListStatikUser lsu){
    if(adr == NULL){
        return;
    }
    fprintf(fptr, "%d %d\n", par, adr->id);
    int i;
    for(i = 0; i < adr->teks.Length; ++i){
        fprintf(fptr, "%c", adr->teks.TabWord[i]);
    }
    fprintf(fptr, '\n');
    for(i = 0; lsu.data[adr->idPenulis].nama[i] != '\0'; ++i){
        fprintf(fptr, "%c", lsu.data[adr->idPenulis].nama[i]);
    }
    fprintf(fptr, '\n');
    fprintf(fptr, "%d/%d/%d %02d:%02d:%02d", adr->waktu.DD, adr->waktu.MM, adr->waktu.YYYY, adr->waktu.T.HH, adr->waktu.T.MM, adr->waktu.T.SS);
    fprintf(fptr, '\n');
    writeRecursion(fptr, par, SIBLINGBALASAN(*adr), lsu);
    writeRecursion(fptr, IDBALASAN(*adr), CHILDBALASAN(*adr), lsu);
}

void simpandraf(ListStatikUser lsu){
    char *namaFolder = inputNamaFolder(stdin);
    int ch = mkdir(namaFolder);
    if(ch == -1){
        printf("Failed creating new directory\n");
        return;
    }
    strcat(namaFolder, namaFileDraf);
    FILE* fptr = fopen(namaFolder, "ab+");
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

int main(){
    AddressBalasan root = newNode();
    root->id = -1;
    strcpy(root->teks, "iniroot");
    root->idPenulis = -1;
    makeAll(root);
    printf("hreeee\n");
    simpanPengguna(root);
    return 0;
}

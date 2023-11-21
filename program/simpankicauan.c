#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "header/listdinkicauan.h"
#include "header/liststatikuser.h"

const char* namaFileKicauan = "/kicauan.config";

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

void simpankicauan(ListKicauan l, ListStatikUser lsu){
    char *namaFolder = inputNamaFolder(stdin);
    int ch = mkdir(namaFolder);
    if(ch == -1){
        printf("Failed creating new directory\n");
        return;
    }
    strcat(namaFolder, namaFileKicauan);
    FILE* fptr = fopen(namaFolder, "ab+");
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
        fprintf(fptr, '\n');
        fprintf(fptr, "%d\n", ELMTLISTKICAU(l, i).like);
        for(j = 0; lsu.data[ELMTLISTKICAU(l, i).idauthor - 1].nama[j] != '\0'; ++j){
            fprintf(fptr, "%c", lsu.data[ELMTLISTKICAU(l, i).idauthor - 1].nama[j]);
        }
        fprintf(fptr, '\n');
        DATETIME curWaktu = ELMTLISTKICAU(l, i).waktu;
        fprintf(fptr, "%d/%d/%d %02d:%02d:%02d", curWaktu.DD, curWaktu.MM, curWaktu.YYYY, curWaktu.T.HH, curWaktu.T.MM, curWaktu.T.SS);
        fprintf(fptr, '\n');
        
    }
    fclose(fptr);
}

int main(){
    return 0;
}

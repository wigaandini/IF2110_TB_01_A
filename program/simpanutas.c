#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "header/listdinkicauan.h"
#include "header/liststatikuser.h"

const char* namaFileUtas = "/utas.config";

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

void simpanutas(ListKicauan l, ListStatikUser lsu){
    char *namaFolder = inputNamaFolder(stdin);
    int ch = mkdir(namaFolder);
    if(ch == -1){
        printf("Failed creating new directory\n");
        return;
    }
    strcat(namaFolder, namaFileUtas);
    FILE* fptr = fopen(namaFolder, "ab+");
    if(fptr == NULL){
        printf("Failed making new file\n");
        return;
    }
    int i, cnt = 0;
    for(i = 0; i < NEFFLISTKICAU(l); ++i){
        if(l.buffer[i].sambunganUtas != NULL){
            cnt++;
        }
    }
    fprintf(fptr, "%d\n", cnt);
    for(i = 0; i < NEFFLISTKICAU(l); ++i){
        if(l.buffer[i].sambunganUtas != NULL){
            fprintf(fptr, "%d\n", l.buffer[i].id);
            fprintf(fptr, "%d\n", length(l.buffer[i].sambunganUtas));
            AddressUtas cur = l.buffer[i].sambunganUtas;
            while(cur != NULL){
                int j;
                for(j = 0; j < cur->info.text.Length; ++j){
                    fprintf(fptr, "%c", cur->info.text.TabWord[j]);
                }
                fprintf(fptr, '\n');
                for(j = 0; lsu.data[l.buffer[i].idauthor - 1].nama[j] != '\0'; ++j){
                    fprintf(fptr, "%c", lsu.data[l.buffer[i].idauthor - 1].nama[j]);
                }
                fprintf(fptr, '\n');
                DATETIME curWaktu = cur->info.waktu;
                fprintf(fptr, "%d/%d/%d %02d:%02d:%02d", curWaktu.DD, curWaktu.MM, curWaktu.YYYY, curWaktu.T.HH, curWaktu.T.MM, curWaktu.T.SS);
                fprintf(fptr, '\n');
                cur = cur->next;
            }
        }        
    }
    fclose(fptr);
}

int main(){
    return 0;
}

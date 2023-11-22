#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "header/treebalasan.h"
#include "header/listdinkicauan.h"
#include "header/liststatikuser.h"

const char* namaFileDraf = "/draf.config";


void simpandraf(ListStatikUser lsu, char *namaFolder){
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
    for(i = 0; i < banyakUser(lsu); ++i){
        if(lsu.data[i].drafuser.TOP != -1){
            cnt++;
        }
    }
    fprintf(fptr, "%d\n", cnt);
    for(i = 0; i < banyakUser(lsu); ++i){
        if(lsu.data[i].drafuser.TOP != -1){
            int j;
            for(j = 0; j < lsu.data[i].nama[j] != '\0'; ++j){
                fprintf(fptr, "%c", lsu.data[i].nama[j]);
            }
            fprintf(fptr, " ");
            fprintf(fptr, "%d\n", lsu.data[i].drafuser.TOP + 1);
            while(!IsEmptyStack(lsu.data[i].drafuser)){
                Draf topelem;
                Pop(&(lsu.data[i].drafuser), &topelem);
                int k;
                for(k = 0; k < topelem.Text.Length; ++k){
                    fprintf(fptr, "%c", topelem.Text.TabWord[k]);
                }
                DATETIME curWaktu = topelem.Waktu;
                fprintf(fptr, "%d/%d/%d %02d:%02d:%02d", curWaktu.DD, curWaktu.MM, curWaktu.YYYY, curWaktu.T.HH, curWaktu.T.MM, curWaktu.T.SS);
                fprintf(fptr, "\n");
            }

        }
    }
    fclose(fptr);
}

int main(){
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../adt/header/treebalasan.h"
#include "../adt/header/listdinkicauan.h"
#include "../adt/header/liststatikuser.h"

char* namaFileDraf = "/draf.config";

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

void simpandraf(ListStatikUser lsu, char *namaFolder){
    int ch = mkdir(namaFolder,0777);
    char namaFile[1000];
    concatString(namaFile, namaFolder, namaFileDraf);
    FILE* fptr = fopen(namaFile, "w");
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
            for(j = 0; lsu.data[i].nama[j] != '\0'; ++j){
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
                fprintf(fptr, "\n");
                DATETIME curWaktu = topelem.Waktu;
                fprintf(fptr, "%d/%d/%d %02d:%02d:%02d", curWaktu.DD, curWaktu.MM, curWaktu.YYYY, curWaktu.T.HH, curWaktu.T.MM, curWaktu.T.SS);
                fprintf(fptr, "\n");
            }

        }
    }
    fclose(fptr);
}

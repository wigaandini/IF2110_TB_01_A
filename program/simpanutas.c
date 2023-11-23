#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../adt/header/listdinkicauan.h"
#include "../adt/header/liststatikuser.h"

char* namaFileUtas = "/utas.config";

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

void simpanutas(ListKicauan l, ListStatikUser lsu, char *namaFolder){
    
    int ch = mkdir(namaFolder);
    char namaFile[1000];
    concatString(namaFile, namaFolder, namaFileUtas);
    FILE* fptr = fopen(namaFile, "ab+");
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
                fprintf(fptr, "\n");
                for(j = 0; lsu.data[l.buffer[i].idauthor - 1].nama[j] != '\0'; ++j){
                    fprintf(fptr, "%c", lsu.data[l.buffer[i].idauthor - 1].nama[j]);
                }
                fprintf(fptr, "\n");
                DATETIME curWaktu = cur->info.waktu;
                fprintf(fptr, "%d/%d/%d %02d:%02d:%02d", curWaktu.DD, curWaktu.MM, curWaktu.YYYY, curWaktu.T.HH, curWaktu.T.MM, curWaktu.T.SS);
                fprintf(fptr, "\n");
                cur = cur->next;
            }
        }        
    }
    fclose(fptr);
}


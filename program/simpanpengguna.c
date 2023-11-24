#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../adt/header/listdinkicauan.h"
#include "../adt/header/liststatikuser.h"

char* namaFilePengguna = "/pengguna.config";

char* wetonDecider(int x) {
    char *ans; // Declare ans once, outside of the switch

    switch(x) {
        case 0:
            ans = "";
            break;
        case 1:
            ans = "Pahing";
            break;
        case 2:
            ans = "Kliwon";
            break;
        case 3:
            ans = "Wage";
            break;
        case 4:
            ans = "Pon";
            break;
        case 5:
            ans = "Legi";
            break;
        default:
            printf("Error, weton di luar scope??\n");
            ans = "EMPTYWETON"; // Return NULL or some error indicator
            break;
    }
    return ans;
}

char* tipeAkunDecider(int x){
    char *ans;
    switch (x){
    case 0:
        ans = "Publik";
        return ans;
    case 1:
        ans = "Privat";
        return ans;
    default:
        printf("Error, tipe akun di luar scope??\n");
    }
    return ans;
}

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

void simpanpengguna(ListStatikUser lsu, FriendMatrix fm, char *namaFolder){
    int ch = mkdir(namaFolder,0777);
    char namaFile[1000];
    concatString(namaFile, namaFolder, namaFilePengguna);
    FILE* fptr = fopen(namaFile, "w");
    if(fptr == NULL){
        printf("Failed making new file\n");
        return;
    }
    fprintf(fptr, "%d\n", banyakUser(lsu));
    int i;
    for(i = 0; i < banyakUser(lsu); ++i){
        int j;
        for(j = 0; lsu.data[i].nama[j] != '\0'; ++j){
            fprintf(fptr, "%c", lsu.data[i].nama[j]);
        }
        fprintf(fptr, "\n");
        for(j = 0; lsu.data[i].sandi[j] != '\0'; ++j){
            fprintf(fptr, "%c", lsu.data[i].sandi[j]);
        }
        fprintf(fptr, "\n");
        for(j = 0; lsu.data[i].bio[j] != '\0'; ++j){
            fprintf(fptr, "%c", lsu.data[i].bio[j]);
        }
        fprintf(fptr, "\n");
        for(j = 0; j < listLength(lsu.data[i].noHP); ++j){
            fprintf(fptr, "%c", lsu.data[i].noHP.buffer[j]);
        }
        fprintf(fptr, "\n");
        char *weton = wetonDecider(lsu.data[i].weton);
        fprintf(fptr, "%s\n", weton);
        char *tipeAkun = tipeAkunDecider(lsu.data[i].tipe);
        fprintf(fptr, "%s\n", tipeAkun);
        int p, q;
        for(p = 0; p < 5; ++p){
            for(q = 0; q < 5; ++q){
                fprintf(fptr, "%c ", lsu.data[i].warnaFoto.mem[p][q]);
                fprintf(fptr, "%c", lsu.data[i].foto.mem[p][q]);
                if(q != 4){
                    fprintf(fptr, " ");
                }
            }
            fprintf(fptr, "\n");
        }
    }
    int p, q;
    for(p = 0; p < ROW_EFFFRIEND(fm); ++p){
        for(q = 0; q < COL_EFFFRIEND(fm); ++q){
            fprintf(fptr, "%d", ELMTFRIEND(fm, p, q));
            if(q != COL_EFFFRIEND(fm)){
                fprintf(fptr, " ");
            }
        }
        fprintf(fptr, "\n");
    }
    int cntReq = 0;
    for(i = 0; i < banyakUser(lsu); ++i){
        Address cur = lsu.data[i].userReq.addrHead;
        while(cur != NULL){
            cntReq++;
            cur = cur->next;
        }
    }
    fprintf(fptr, "%d\n", cntReq);
    for(i = 0; i < banyakUser(lsu); ++i){
        Address cur = lsu.data[i].userReq.addrHead;
        while(cur != NULL){
            fprintf(fptr, "%d %d %d\n", cur->iduser, cur->idfollow, cur->nfrienduser);
            cur = cur->next;
        }
    }
    fclose(fptr);
}


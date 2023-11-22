#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "header/listdinkicauan.h"
#include "header/liststatikuser.h"

const char* namaFilePengguna = "/pengguna.config";

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

char* wetonDecider(int x){
    switch(x){
        case 0:
        char *ans = "";
        return ans;
        case 1:
        char *ans = "PAHING";
        return ans;
        case 2:
        char *ans = "KLIWON";
        return ans;
        case 3:
        char *ans = "WAGE";
        return ans;
        case 4:
        char *ans = "PON";
        return ans;
        case 5:
        char *ans = "LEGI";
        return ans;
        default:
        printf("Error, weton di luar scope??\n");
    }
}

char* tipeAkunDecider(int x){
    switch (x){
    case 0:
        char *ans = "PUBLIK";
        return ans;
    case 1:
        char *ans = "PRIVAT";
        return ans;
    default:
        printf("Error, tipe akun di luar scope??\n");
    }
}

void simpanpengguna(ListStatikUser lsu, FriendMatrix fm){
    char *namaFolder = inputNamaFolder(stdin);
    int ch = mkdir(namaFolder);
    if(ch == -1){
        printf("Failed creating new directory\n");
        return;
    }
    strcat(namaFolder, namaFilePengguna);
    FILE* fptr = fopen(namaFolder, "ab+");
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
        fprintf(fptr, "\n");
        char *tipeAkun = tipeAkunDecider(lsu.data[i].tipe);
        fprintf(fptr, "%s\n", tipeAkun);
        int p, q;
        for(p = 0; p < 5; ++p){
            for(q = 0; q < 5; ++q){
                fprintf(fptr, "%c", lsu.data[i].warnaFoto.mem[p][q]);
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
    for(i = 0; i < banyakUser(lsu); ++i){
        Address cur = lsu.data[i].userReq.addrHead;
        while(cur != NULL){
            fprintf(fptr, "%d %d %d\n", cur->iduser, cur->idfollow, cur->nfrienduser);
            cur = cur->next;
        }
    }
    fclose(fptr);
}

int main(){
    return 0;
}

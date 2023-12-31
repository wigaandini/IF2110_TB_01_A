#include <stdio.h>
#include "header/liststatikuser.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
#define here printf("here\n");
void CreateListStatikUser(ListStatikUser *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITYUSER */
/* Proses: Inisialisasi semua elemen List l dengan elemen kosong */
    IdxType i;
    for(i=0; i<CAPACITYUSER; i++){
        for (int j=0; j<136; j++) {
            if (j<21) {
                UserName(*l, i, j) = '\0';
                UserSandi(*l, i, j) = '\0';
            }
            UserBio(*l, i, j) = '\0';
        }

        CreateListDin(&(l->data[i].noHP), 16);

        UserId(*l, i) = i+1;

        UserWeton(*l, i) = EMPTYWETON;

        UserTipe(*l, i) = PUBLIK;
        
        CreateReqFol(&(l->data[i].userReq));
        CreateEmptyStack(&(l->data[i].drafuser));

        int p = 0;
        int q = 0;
        for (p=0; p<5; p++) {
            for (q=0; q<5; q++) {
                ELMT(UserFoto(*l,i), p, q) = '*';
            }
        }

        for (p=0; p<5; p++) {
            for (q=0; q<5; q++) {
                ELMT(UserWarnaFoto(*l,i), p, q) = '*';
            }
        }
    }
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int banyakUser(ListStatikUser l){
/* Mengirimkan banyaknya user yang terdaftar */
/* Mengirimkan nol jika List kosong */  
    int i;
    int cnt = 0;
    for(i=0; i<20; i++){
        if (UserName(l, i, 0) != '\0'){
            cnt++;
        }
    }
    return cnt;
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isUserDataEmpty(ListStatikUser l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    return (banyakUser(l) == 0);
}

/* *** Test List penuh *** */
boolean isUserDataFull(ListStatikUser l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return banyakUser(l) == CAPACITYUSER;
}

   
void printListofUser(ListStatikUser l){
    int i;
    boolean y = isUserDataEmpty(l);
    if (y){
        printf("Belum ada User yang terdaftar\n");
    }
    else{
        for(i=0; i<banyakUser(l); i++){         // iterasi tiap user
            printf("ID\t: %d\n", UserId(l, i));

            printf("Name\t: ");
            displayString(l.data[i].nama); printf("\n");
            
            printf("Pass\t: %s\n", l.data[i].sandi);
            
            printf("Bio\t: %s\n", l.data[i].bio);

            printf("No. HP\t: ");
            for (int j=0; j<UserNoHPNeff(l, i); j++) {
                printf("%c", UserNoHP(l, i, j));
            }
            printf("\n");

            printf("Weton\t: ");
            switch (UserWeton(l, i))
            {
            case EMPTYWETON:
                printf("\n");
                break;
            case PAHING:
                printf("Pahing\n");
                break;
            case KLIWON:
                printf("Kliwon\n");
                break;
            case WAGE:
                printf("Wage\n");
                break;
            case PON:
                printf("Pon\n");
                break;
            case LEGI:
                printf("Legi\n");
                break;
            default:
                break;
            }

            printf("Tipe\t: ");
            switch (UserTipe(l, i))
            {
            case PUBLIK:
                printf("Publik\n");
                break;
            case PRIVAT:
                printf("Privat\n");
                break;
            default:
                break;
            }
            printf("\n");

            printf("Foto dengan warna:\n");
            displayMatrixFoto(UserFoto(l, i), UserWarnaFoto(l, i));

            printf("Warna foto:\n");
            displayMatrix(UserWarnaFoto(l, i));

            printf("--------------------\n");            
        }
    }
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexUser(ListStatikUser l, Word name){
    boolean found;
    int i = 0;

    if(banyakUser(l) == 0){
        return IDX_UNDEF;
    }
    else{
        found = false;
        while(!found && i<banyakUser(l)){
            if (UserName(l, i, 0) == name.TabWord[0]) {
                boolean match = true;
                for (int j=0; j<name.Length; j++) {
                    if (UserName(l, i, j) != name.TabWord[j]) {
                        match = false;
                        break;
                    }
                }
                found = match;
            }
            else{
                found = false;
                i++;
            }
        }

        if(found){
            return i;
        }
        else{
            return IDX_UNDEF;
        }
    }
}

int idOf(ListStatikUser l, Word name) {
    return indexUser(l, name) +1;
}


/* ********** MENAMBAH ELEMEN ********** */
/* ********** MENAMBAH DATA USER ********** */
void addUser(ListStatikUser *l,FriendMatrix *F, Word name, Word pw)         // Ini kayanya masukkan nya ga dalam Word dah, coba cari tau
{
    IdxType i, idx;
    for(i=0; i<CAPACITYUSER; i++){
        if (UserName(*l, i, 0) == '\0'){
            idx = i;
            break;
        }
    }

    for (int i=0; i<name.Length; i++) {
        UserName(*l, idx, i) = name.TabWord[i];
    }

    for (int i=0; i<pw.Length; i++) {
        UserSandi(*l, idx, i) = pw.TabWord[i];
    }
    addNeff(F);
}

boolean checkUserExist(ListStatikUser l, Word name){
    int i = 0;
    boolean found = false;
    while(!found && i < banyakUser(l)){
        if(compareString(name, l.data[i].nama)){
            found = true;
        }
        i++;
    }
    return found;
}

boolean checkPass(ListStatikUser l, Word name, Word pass){
    int i = 0;
    boolean found = false;
    while(!found && i < banyakUser(l)){
        if ((compareString(name, l.data[i].nama)) && compareString(pass, l.data[i].sandi)) {
            found = true;
        }
        i++;
    }
    return found;
}


// Mengembalikan Id dari user dengan username bernilai name. Mengembalikan -1 jika tidak ada
int getIdOfName(ListStatikUser l, Word name){
    int i = 0;
    boolean found = false;
    while(!found && i < banyakUser(l)){
        if(compareString(name, l.data[i].nama)){
            found = true;
        }
        i++;
    }
    if (!found) {
        return -1;
    }
    return i;
}
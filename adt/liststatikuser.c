#include <stdio.h>
#include "header/liststatikuser.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
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
                if (j<16) {
                    UserNoHP(*l, i, j) = '\0';
                }
            }
            UserBio(*l, i, j) = '\0';
        }

        UserId(*l, i) = i+1;

        UserWeton(*l, i) = EMPTYWETON;

        Matrix foto;
        createMatrix(5, 5, &foto);
        UserFoto(*l, i) = foto;

        Matrix warnaFoto;
        createMatrix(5, 5, &warnaFoto);
        UserWarnaFoto(*l, i) = warnaFoto;
    }
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int banyakUser(ListStatikUser l){
/* Mengirimkan banyaknya user yang terdaftar */
/* Mengirimkan nol jika List kosong */  
    IdxType i, count=0;
    for(i=0; i<CAPACITYUSER; i++){
        if (UserName(l, i, 0) != '\0'){
            count ++;
        }
    }
    return count;
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isUserDataEmpty(ListStatikUser l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    return banyakUser(l) == 0;
}

/* *** Test List penuh *** */
boolean isUserDataFull(ListStatikUser l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return banyakUser(l) == CAPACITYUSER;
}

   
void printListofUser(ListStatikUser l){
    IdxType i;
    if (isUserDataEmpty(l)){
        printf("Belum ada User yang terdaftar\n");
    }
    else{
        for(i=0; i<banyakUser(l); i++){         // iterasi tiap user
            printf("ID\t: %d\n", UserId(l, i));

            printf("Name\t: %s\n", l.data[i].nama);
            
            printf("Pass\t: %s\n", l.data[i].sandi);
            
            printf("Bio\t: %s\n", l.data[i].bio);
            
            printf("No. HP\t: %s\n", l.data[i].noHP);

            printf("Weton\t: ");
            switch (UserWeton(l, i))
            {
            case EMPTYWETON:
                printf("EmptyWeton\n");
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

            printf("Foto:\n");
            displayMatrix(UserFoto(l, i));

            printf("Warna foto:\n");
            displayMatrix(UserWarnaFoto(l, i));
            
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
void addUser(ListStatikUser *l, Word name, Word pw)         // Ini kayanya masukkan nya ga dalam Word dah, coba cari tau
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
}

boolean checkUserExist(ListStatikUser l, Word name){
    int i = 0;
    boolean found = false;
    while(!found && i < banyakUser(l)){
        if(l.data[i].nama == WordToString(name)){
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
        if(l.data[i].nama == WordToString(name) && l.data[i].sandi == WordToString(pass)){
            found = true;
        }
        i++;
    }
    return found;
}
#include <stdio.h>
#include "../adt/header/configmachine.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/liststatikuser.h"
#include "../adt/header/friendmatrix.h"
#include "../adt/header/prioreqfollinked.h"

// gcc main.c adt/configmachine.c adt/charmachine.c adt/liststatikuser.c adt/listdin.c 
// adt/Matrix.c adt/friendmatrix.c adt/pcolor.c adt/prioreqfollinked.c -o tes

int charToInt(char c) {
    if (c >= '0' && c <= '9') {
        return (c - '0');
    }
    else{
        return -1;
    }
}

void ReadUser(ListStatikUser *l,FriendMatrix *F, char *path) {
    char realpath[200];
    concatenate(realpath, path, "/pengguna.config");
    STARTconfig(realpath);

    // ListStatikUser l; //DATA USER
    CreateListStatikUser(l);

    // FriendMatrix F; //MATRIKS PERTEMANAN
    createMatrixFriend(F);

    Prioreqfol R; //MATRIKS PERMINTAAN
    CreateReqFol(&R);

    boolean first=true;
    int count=0; //patokan
    int user=0; //user sekarang
    int temp=0; //banyak line

    int friendcount=0; //patokan matriks teman

    boolean reqfirst=true;
    // int reqcount=0; //patokan matriks permintaan

    while (!EOP) {
        if (first){
            Word bacaan;
            int i = 0;

            while (!EOP && currentChar != '\n') {
                bacaan.TabWord[i] = currentChar;
                i++;
                ADVconfig();
            }
            bacaan.TabWord[i] = '\0';

            // printf("%s\n", bacaan.TabWord);
            for (i = 0; bacaan.TabWord[i] != '\0'; i++) {
                if (i==0){
                    temp+=charToInt(bacaan.TabWord[i]);
                }
                else{
                    if (charToInt(bacaan.TabWord[i])<=9 && charToInt(bacaan.TabWord[i])>=0)
                    {
                        temp=temp*10+charToInt(bacaan.TabWord[i]);
                    }
                }
            }

            while (currentChar == '\n') {
                ADVconfig();
            }
            first=false;
        }
        if (count<(temp*11)){
            if (count%11==0){ //USERNAME
                Word bacaan;
                int i = 0;

                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';
                // printf("%s\n", bacaan.TabWord);
                
                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    // printf("%c", bacaan.TabWord[i]);
                    UserName(*l,user,i)=bacaan.TabWord[i];
                }
                // printf("\n");
                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
                // printf("%s\n",l.data[user].nama);
                UserId(*l, user)=user+1;
            }
            else if (count%11==1){ //PASSWORD
                Word bacaan;
                int i = 0;

                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';
                
                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    // printf("%c", bacaan.TabWord[i]);
                    UserSandi(*l,user,i)=bacaan.TabWord[i];
                }
                // printf("\n");
                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
                // printf("%s\n",l.data[user].sandi);
            }
            else if (count%11==2) { //BIO
                Word bacaan;
                int i = 0;

                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';
                
                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    // printf("%c", bacaan.TabWord[i]);
                    UserBio(*l,user,i)=bacaan.TabWord[i];
                }
                // printf("\n");
                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;

                // if (l.data[user].bio!="/0"){
                //     printf("%s\n",l.data[user].bio);
                // }
                // else{
                //     printf("\n");
                // }
            }
            else if (count%11==3){ //NOHP
                Word bacaan;
                int i = 0;

                // ListDin dummy;
                // CreateListDin(&dummy,16);

                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';

                for (int i = 0; bacaan.TabWord[i+1] != '\0'; i++) {
                    // printf("%c", bacaan.TabWord[i]);
                    insertLast(&((*l).data[user].noHP),bacaan.TabWord[i]);
                }

                // printList(l.data[user].noHP);
                // printf("\n");


                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
                // printList(l.data[0].noHP);
            }
            else if (count%11==4) { //WETON
                Word bacaan;
                int i = 0;
                
                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';

                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    if (i == 0 && bacaan.TabWord[i] == 'P' && bacaan.TabWord[i+1] != '\0') {
                        if (i == 0 && bacaan.TabWord[i+1] == 'a' && bacaan.TabWord[i+2] != '\0') {
                            UserWeton(*l, user) = PAHING;
                        } else {
                            UserWeton(*l, user) = PON;
                        }
                    } else if (i == 0 && bacaan.TabWord[i] == 'K' && bacaan.TabWord[i+1] != '\0') {
                        UserWeton(*l, user) = KLIWON;
                    } else if (i == 0 && bacaan.TabWord[i] == 'W' && bacaan.TabWord[i+1] != '\0') {
                        UserWeton(*l, user) = WAGE;
                    } else if (i == 0 && bacaan.TabWord[i] == 'L' && bacaan.TabWord[i+1] != '\0') {
                        UserWeton(*l, user) = LEGI;
                    } else if(i == 0 && bacaan.TabWord[i] != '\0'){
                        UserWeton(*l, user) = EMPTYWETON;
                    }
                    // printf("%c", bacaan.TabWord[i]);
                }
                // printf("\n");

                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
            }                        
            else if (count%11==5){ //TIPEAKUN
                Word bacaan;
                int i = 0;
                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';
                
                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    if (i == 0 && bacaan.TabWord[i] == 'P' && bacaan.TabWord[i+1] != '\0') {
                        if (i == 0 && bacaan.TabWord[i+1] == 'u' && bacaan.TabWord[i+2] != '\0') {
                            UserTipe(*l,user)=PUBLIK;
                        } else {
                            UserTipe(*l, user) = PRIVAT;
                        }
                    }
                    // printf("%c", bacaan.TabWord[i]);
                }
                // printf("\n");

                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
            }
            else{ //PROFIL WARNA/FOTO
                Word bacaan;
                int i = 0;

                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';
                
                int j = (count%11)%6;
                // printf("ini j :%d",j);
                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    // printf("%c",bacaan.TabWord[i]);
                    if (i%2==0){
                        if ((i/2)%2==0) {
                            UserWarnaFoto(*l,user).mem[j][(i/2)/2]=bacaan.TabWord[i];                   
                        }
                        else if ((i/2)%2==1){
                            UserFoto(*l,user).mem[j][((i/2)-1)/2]=bacaan.TabWord[i];
                        }
                    }
                }
                // printf("\n");

                while (currentChar == '\n') {
                    ADVconfig();
                }
                if (count%11==10){
                    user++;
                }
                count++;
            }
        }
        else if(friendcount<temp){ //MATRIKS PERTEMANAN
            Word bacaan;
            int i = 0;

            while (!EOP && currentChar != '\n') {
                bacaan.TabWord[i] = currentChar;
                i++;
                ADVconfig();
            }
            bacaan.TabWord[i] = '\0';
            
            for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                // printf("%c",bacaan.TabWord[i]);
                if (i%2==0){
                    ELMTFRIEND(*F,friendcount,i/2)=charToInt(bacaan.TabWord[i]);
                }
            }
            // printf("\n");

            while (currentChar == '\n') {
                ADVconfig();
            }
            friendcount++;
        }
        else{ //MATRIKS REQUEST
            if (reqfirst)
            {
                Word bacaan;
                int i = 0;

                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';

                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    // printf("%c", bacaan.TabWord[i]);
                }
                // printf("\n");

                while (currentChar == '\n') {
                    ADVconfig();
                }
                reqfirst=false;
            }
            else{
                Word bacaan;
                int i = 0;

                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';
                
                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    // int idus;
                    // int ifol;
                    if (i%2==0){
                        // ELMTFRIEND(R,reqcount,i/2)=charToInt(bacaan.TabWord[i]);
                        if (i/2==0)
                        {
                            // idus=charToInt(bacaan.TabWord[i]);
                        }
                        else if (i/2==1)
                        {
                            // ifol=charToInt(bacaan.TabWord[i]);
                        }
                        else if (i/2==3)
                        {
                            // sendReqFol(&R,F,idus,ifol);
                            // SendReqFol(&R, F, idus,ifol);
                        }
                    }
                }

                while (currentChar == '\n') {
                    ADVconfig();
                }
                // reqcount++;
                }
        }
    }

    // printListofUser(*l);
    // printList(l.data[0].noHP);
    // printf("\n");
    // displayMatrixFRIEND(F,temp,temp);
    // printf("\n");
    // displayMatrixFRIEND(R,reqcount,3);
}
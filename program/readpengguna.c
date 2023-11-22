#include <stdio.h>
#include "../adt/header/configmachine.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/liststatikuser.h"
#include "../adt/header/friendmatrix.h"

// gcc readpengguna.c ../adt/configmachine.c ../adt/charmachine.c ../adt/liststatikuser.c ../adt/listdin.c ../adt/Matrix.c ../adt/friendmatrix.c -o tes

int charToInt(char c) {
    if (c >= '0' && c <= '9') {
        return (c - '0');
    }
}

int main() {
    STARTconfig("../config/pengguna.config");

    ListStatikUser l; //DATA USER
    CreateListStatikUser(&l);

    FriendMatrix F; //MATRIKS PERTEMANAN
    createMatrixFriend(&F);

    FriendMatrix R; //MATRIKS PERMINTAAN
    createMatrixFriend(&R);

    boolean first=true;
    int count=0; //patokan
    int user=0; //user sekarang
    int temp=0; //banyak line

    int friendcount=0; //patokan matriks teman

    boolean reqfirst=true;
    int reqcount=0; //patokan matriks permintaan

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

            for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
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
                
                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    UserName(l,user,i)=bacaan.TabWord[i];
                }


                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
                UserId(l, user+1);
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
                    UserSandi(l,user,i)=bacaan.TabWord[i];
                }

                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
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
                    UserBio(l,user,i)=bacaan.TabWord[i];
                }

                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
            }
            else if (count%11==3){ //NOHP
                Word bacaan;
                int i = 0;

                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';
                
                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    if (charToInt(bacaan.TabWord[i])<=9 && charToInt(bacaan.TabWord[i])>=0)
                    {
                        insertLast(&(l.data[user].noHP),charToInt(bacaan.TabWord[i]));
                    }
                }

                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
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
                            UserWeton(l, user) = PAHING;
                        } else {
                            UserWeton(l, user) = PON;
                        }
                    } else if (i == 0 && bacaan.TabWord[i] == 'K' && bacaan.TabWord[i+1] != '\0') {
                        UserWeton(l, user) = KLIWON;
                    } else if (i == 0 && bacaan.TabWord[i] == 'W' && bacaan.TabWord[i+1] != '\0') {
                        UserWeton(l, user) = WAGE;
                    } else if (i == 0 && bacaan.TabWord[i] == 'L' && bacaan.TabWord[i+1] != '\0') {
                        UserWeton(l, user) = LEGI;
                    } else if(i == 0 && bacaan.TabWord[i] != '\0'){
                        UserWeton(l, user) = EMPTYWETON;
                    }
                }

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
                            UserTipe(l,user)=PUBLIK;
                        } else {
                            UserTipe(l, user) = PRIVAT;
                        }
                    }
                }

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
                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    if (i%2==0){
                        if ((i/2)%2==0) {
                            UserWarnaFoto(l,user).mem[j][(i/2)/2]=bacaan.TabWord[i];                   
                        }
                        else if ((i/2)%2==1){
                            UserFoto(l,user).mem[j][((i/2)-1)/2]=bacaan.TabWord[i];
                        }
                    }
                }

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
                if (i%2==0){
                    ELMTFRIEND(F,friendcount,i/2)=charToInt(bacaan.TabWord[i]);
                }
            }

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
                    if (i%2==0){
                        ELMTFRIEND(R,reqcount,i/2)=charToInt(bacaan.TabWord[i]);
                    }
                }

                while (currentChar == '\n') {
                    ADVconfig();
                }
                reqcount++;
                }
        }
    }
    printListofUser(l);
    printf("\n");
    displayMatrixFRIEND(F,temp,temp);
    printf("\n");
    displayMatrixFRIEND(R,reqcount,3);
}
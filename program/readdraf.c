#include "../adt/header/draf.h"
#include "../adt/header/configmachine.h"
#include "../adt/header/wordmachine.h"
#include "../adt/header/liststatikuser.h"
#include <stdio.h>

// int charToInt(char c) {
//     if (c >= '0' && c <= '9') {
//         return (c - '0');
//     }
// }

int pangkat(int a,int b){
    if (b==0){
        return 1;
    }
    
    return a*pangkat(a,b-1);
}

// void ReadDraf(ListStatikUser *l){
// }

void ReadDraf(ListStatikUser *l,char* path){
    char realpath[200];
    concatenate(realpath, path, "/draf.config");
    STARTconfig(realpath);
    
    // int n=0;
    // for ( n = 0; n < banyakUser(*l); n++)
    // {
    //     displayMatrixFoto(UserFoto(*l, n), UserWarnaFoto(*l, n));
    //     LihatDraf((*l).data[n].drafuser);
    // }
    
    DrafStack reverse;
    CreateEmptyStack(&reverse);

    int temp=0;
    // int count=0;

    boolean first=true;
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
        else{
            int totdraf=0;
            Word bacaan;
            bacaan.Length=0;
            int i = 0;

            while (!EOP && currentChar != '\n') {
                bacaan.TabWord[i] = currentChar;
                bacaan.Length++;
                i++;
                ADVconfig();
            }
            bacaan.TabWord[i] = '\0';

            int j;
            boolean space=false;
            boolean skipspace=false;
            Word revert;
            for ( j = bacaan.Length-1; j >= 0  ; j--){
                if (bacaan.TabWord[j] == ' '){
                    space=true;
                }
                
                if (!space){
                    if (charToInt(bacaan.TabWord[j])<=9 && charToInt(bacaan.TabWord[j])>=0){
                        if (bacaan.Length-j-1==0)
                        {
                            totdraf+=charToInt(bacaan.TabWord[j]);
                        }
                        else{
                            totdraf+=charToInt(bacaan.TabWord[j])*pangkat(10,bacaan.Length-j-1);
                        }
                    }
                }
                else{
                    if (!skipspace){
                        skipspace=true;
                        // printf("panjang%d\n",j-1);
                        revert.Length=j;
                        i=0;
                    } else{
                        revert.TabWord[revert.Length-i-1]=bacaan.TabWord[j];
                        i++;
                    }
                }
            }
            // printf("\n");
    
            // printf("\n");

            int idmasuk=-1;
            int n;
            for (n = 0; n < banyakUser(*l); n++){
                boolean adauser=true;
                for (i = 0; i < revert.Length; i++){
                    if (revert.TabWord[i]!=(l->data[n].nama[i])){
                        adauser=false;
                    }
                }
                if (adauser){
                    idmasuk=n;
                }
            }

            while (currentChar == '\n') {
                ADVconfig();
            }

            int k;
            for ( k = 0; k < totdraf; k++)
            {
                Draf dummy;
                dummy.Text.Length=0;

                Word bacaan;
                int i = 0;

                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';

                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    if (idmasuk!=-1){
                        dummy.Text.TabWord[i]=bacaan.TabWord[i];
                        dummy.Text.Length++;
                        // printf("%c", dummy.Text.TabWord[i]);
                    }
                }
                // printf("\n");

                while (currentChar == '\n') {
                    ADVconfig();
                }

                Word bacaan2;
                i = 0;

                while (!EOP && currentChar != '\n') {
                    bacaan2.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan2.TabWord[i] = '\0';

                int totwaktu=0;
                for (int i = 0; bacaan2.TabWord[i] != '\0'; i++) {
                    if (idmasuk!=-1){
                        if (i<2){
                            totwaktu=totwaktu*10+charToInt(bacaan2.TabWord[i]);
                        } else if (i==2){
                            dummy.Waktu.DD=totwaktu;
                            totwaktu=0;
                        } else if (i<5){                    
                            totwaktu=totwaktu*10+charToInt(bacaan2.TabWord[i]);
                        } else if (i==5){
                            dummy.Waktu.MM=totwaktu;
                            totwaktu=0;
                        } else if (i<10){                         
                            totwaktu=totwaktu*10+charToInt(bacaan2.TabWord[i]);
                        } else if (i==10){
                            dummy.Waktu.YYYY=totwaktu;
                            totwaktu=0;
                        } else if (i<13){
                            totwaktu=totwaktu*10+charToInt(bacaan2.TabWord[i]);
                        } else if (i==13){
                            dummy.Waktu.T.HH=totwaktu;
                            totwaktu=0;
                        } else if (i<16){
                            totwaktu=totwaktu*10+charToInt(bacaan2.TabWord[i]);
                        } else if (i==16){
                            dummy.Waktu.T.MM=totwaktu;
                            totwaktu=0;
                        } else if (i<18){
                            totwaktu=totwaktu*10+charToInt(bacaan2.TabWord[i]);
                        } else if (i==18){
                            totwaktu = totwaktu * 10 + charToInt(bacaan2.TabWord[i]);
                            dummy.Waktu.T.SS=totwaktu;
                            totwaktu=0;
                        }
                    }
                }
                // TulisDATETIME(dummy.Waktu);
                // printf("\n");
                
                while (currentChar == '\n') {
                    ADVconfig();
                }
                //printf("idmasuk: %d\n", idmasuk);
                if (idmasuk!=-1){
                    Push(&reverse,dummy);
                }
            }
            while (!IsEmptyStack(reverse)){
                Draf XX;
                Pop(&reverse,&XX);
                Push(&(l->data[idmasuk].drafuser),XX);
            }
        }
    }
}
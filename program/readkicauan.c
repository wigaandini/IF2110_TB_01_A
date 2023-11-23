#include <stdio.h>
#include "../adt/header/listdinkicauan.h"
#include "../adt/header/liststatikuser.h"

void ReadKicauan(ListKicauan *k, ListStatikUser l,FriendMatrix F, char* path){ 
    char realpath[200];
    concatenate(realpath, path, "/kicauan.config");
    STARTconfig(realpath);
    int count=0;
    // int user=0;

    boolean first=true;
    while (!EOP) {
        if (first)
        {
            Word bacaan;
            int i = 0;

            while (!EOP && currentChar != '\n') {
                bacaan.TabWord[i] = currentChar;
                i++;
                ADVconfig();
            }
            bacaan.TabWord[i] = '\0';

            int tot=0;

            for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                // CreateListGlobalKicauan(k,charToInt(bacaan.TabWord[i]));
                if (bacaan.TabWord[i+1] != '\0')
                {
                    tot=tot*10+charToInt(bacaan.TabWord[i]);
                    // printf("%c\n",bacaan.TabWord[i]);
                }
            }
            // printf("\n");
            // printf("tot:%d\n",tot);
            
            CreateListGlobalKicauan(k,1000);
            // temp=tot*4;

            while (currentChar == '\n') {
                ADVconfig();
            }
            first=false;
        }
        else{
            if (count%5==0)
            {
                Word bacaan;
                int i = 0;

                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';
                
                int theid=0;
                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    if (bacaan.TabWord[i+1] != '\0')
                    {
                        theid=theid*10+charToInt(bacaan.TabWord[i]);
                    }
                }
                ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).id=theid;
                printf("neff:%d\n",NEFFLISTKICAU(*k));
                printf("%d\n",ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).id);

                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
            }
            else if (count%5==1)
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
                    ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).text.TabWord[i]=bacaan.TabWord[i];
                    ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).text.Length++;
                }
                // printf("\n");

                // printf("%s\n",ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).text.TabWord);

                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
            }
            else if (count%5==2)
            {
                Word bacaan;
                int i = 0;

                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';

                int like=0;
                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    if (bacaan.TabWord[i+1] != '\0')
                    {
                        like=like*10+charToInt(bacaan.TabWord[i]);
                    }
                }

                ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).like=like;
                // printf("%d\n",ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).like);

                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
            }
            else if (count%5==3)
            {
                Word bacaan;
                int i = 0;

                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';

                boolean found =false;
                int user_now=0;
                while (!found && user_now<banyakUser(l) ){
                    boolean betul=true;
                    for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                        // printf("banding: %c,%c\n",bacaan.TabWord[i],l.data[user_now].nama[i]);
                        if (bacaan.TabWord[i]!=l.data[user_now].nama[i] && betul){
                            betul=false;
                        }
                    }
                    user_now++;
                    if (betul){
                        // printf("%s\n",bacaan.TabWord);
                        found=true;
                    }
                }
                // printf("usernow:%d\n",user_now);

                if (found)
                {
                    ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).idauthor=user_now;
                }
                
                // ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).idauthor=user_now;
                // user_now=0;
                // printf("%d\n",ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).idauthor);

                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
            }
            else if (count%5==4)
            {
                Word bacaan;
                int i = 0;

                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';

                int tot=0;
                for (i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    if (i<2){
                        tot=tot*10+charToInt(bacaan.TabWord[i]);
                        
                    } else if (i==2){
                        ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).waktu.DD=tot;
                        tot=0;
                    } else if (i<5){                    
                        tot=tot*10+charToInt(bacaan.TabWord[i]);
                    } else if (i==5){
                        ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).waktu.MM=tot;
                        tot=0;
                    } else if (i<10){                         
                        tot=tot*10+charToInt(bacaan.TabWord[i]);
                    } else if (i==10){
                        ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).waktu.YYYY=tot;
                        tot=0;
                    } else if (i<13){
                        tot=tot*10+charToInt(bacaan.TabWord[i]);
                    } else if (i==13){
                        ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).waktu.T.HH=tot;
                        tot=0;
                    } else if (i<16){
                        tot=tot*10+charToInt(bacaan.TabWord[i]);
                    } else if (i==16){
                        ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).waktu.T.MM=tot;
                        tot=0;
                    } else if (i<18){
                        tot=tot*10+charToInt(bacaan.TabWord[i]);
                    } else if (i==18){
                        ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).waktu.T.SS=tot;
                        tot=0;
                    }
                }
                // TulisDATETIME(ELMTLISTKICAU(*k,NEFFLISTKICAU(*k)).waktu);
                // printf("\n");

                if (count%5==4){
                    NEFFLISTKICAU(*k)++;
                }

                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
            }
        }
    }
    // DisplayKicauan(l,*k,3,F);
    // printf("waw:%d\n",ELMTLISTKICAU(*k,1).id);
}
#include <stdio.h>
#include "../adt/header/listdinkicauan.h"
#include "../adt/header/liststatikuser.h"

void ReadKicauan(ListKicauan *k, ListStatikUser l,FriendMatrix F){ 
    STARTconfig("config/kicauan.config");
    int temp=0;
    int count=0;
    int user=0;

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
            CreateListGlobalKicauan(k,tot);
            temp=tot*4;

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
                ELMTLISTKICAU(*k,user).id=theid;
                // printf("%d\n",ELMTLISTKICAU(*k,user).id);

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
                    ELMTLISTKICAU(*k,user).text.TabWord[i]=bacaan.TabWord[i];
                    ELMTLISTKICAU(*k,user).text.Length++;
                }
                // printf("\n");

                // printf("%s\n",ELMTLISTKICAU(*k,user).text.TabWord);

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

                ELMTLISTKICAU(*k,user).like=like;
                // printf("%d\n",ELMTLISTKICAU(*k,user).like);

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
                        if (bacaan.TabWord[i]!=l.data[user_now].nama[i] && betul)
                        {
                            betul=false;
                        }
                    }
                    user_now++;
                    if (betul)
                    {
                        found=true;
                    }
                }
                ELMTLISTKICAU(*k,user).idauthor=user_now;
                // printf("%d\n",ELMTLISTKICAU(*k,user).idauthor);

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
                        ELMTLISTKICAU(*k,user).waktu.DD=tot;
                        tot=0;
                    } else if (i<5){                    
                        tot=tot*10+charToInt(bacaan.TabWord[i]);
                    } else if (i==5){
                        ELMTLISTKICAU(*k,user).waktu.MM=tot;
                        tot=0;
                    } else if (i<10){                         
                        tot=tot*10+charToInt(bacaan.TabWord[i]);
                    } else if (i==10){
                        ELMTLISTKICAU(*k,user).waktu.YYYY=tot;
                        tot=0;
                    } else if (i<13){
                        tot=tot*10+charToInt(bacaan.TabWord[i]);
                    } else if (i==13){
                        ELMTLISTKICAU(*k,user).waktu.T.HH=tot;
                        tot=0;
                    } else if (i<16){
                        tot=tot*10+charToInt(bacaan.TabWord[i]);
                    } else if (i==16){
                        ELMTLISTKICAU(*k,user).waktu.T.MM=tot;
                        tot=0;
                    } else if (i<18){
                        tot=tot*10+charToInt(bacaan.TabWord[i]);
                    } else if (i==18){
                        ELMTLISTKICAU(*k,user).waktu.T.SS=tot;
                        tot=0;
                    }
                }
                // TulisDATETIME(ELMTLISTKICAU(*k,user).waktu);
                // printf("\n");

                if (count%5==4){
                    user++;
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
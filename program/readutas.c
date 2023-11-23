#include "../adt/header/listdinkicauan.h"
#include "../adt/header/listlinierutas.h" 


void ReadUtas(ListKicauan *kicau,ListStatikUser l,char *path){
    char realpath[200];
    concatenate(realpath, path, "/utas.config");
    STARTconfig(realpath);

    int count=0;
    int tempid=0;
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
                if (bacaan.TabWord[i+1] != '\0')
                {
                    tot=tot*10+charToInt(bacaan.TabWord[i]);
                }
            }

            while (currentChar == '\n') {
                ADVconfig();
            }
            first=false;
        }
        else{
            if (count%2==0)
            {
                Word bacaan;
                int i = 0;

                while (!EOP && currentChar != '\n') {
                    bacaan.TabWord[i] = currentChar;
                    i++;
                    ADVconfig();
                }
                bacaan.TabWord[i] = '\0';
                int idkicau=0;
                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    if (bacaan.TabWord[i+1] != '\0')
                    {
                        idkicau=idkicau*10+charToInt(bacaan.TabWord[i]);
                    }
                }
                // printf("idkicau:%d\n",idkicau);
                tempid=idkicau;

                while (currentChar == '\n') {
                    ADVconfig();
                }
                count++;
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

                int banyakutas=0;
                for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
                    if (bacaan.TabWord[i+1] != '\0')
                    {
                        banyakutas=banyakutas*10+charToInt(bacaan.TabWord[i]);
                    }
                }
                // printf("banyakutas:%d\n",banyakutas);


                while (currentChar == '\n') {
                    ADVconfig();
                }
                int k;
                UtasType dummy;
                DATETIME waktu;
                int idUtas;
                int indexUtas;
                
                
                for ( k = 0; k < banyakutas*3; k++)
                {
                    Word temp;
                    int i = 0;

                    while (!EOP && currentChar != '\n') {
                        temp.TabWord[i] = currentChar;
                        i++;
                        ADVconfig();
                    }
                    temp.TabWord[i] = '\0';

                    if (k%3==0){
                        for (int i = 0; temp.TabWord[i] != '\0'; i++) {
                            dummy.text.TabWord[i]=temp.TabWord[i];
                            dummy.text.Length++;
                        }
                        // printf("%s\n",dummy.text.TabWord);
                    }
                    else if (k%3==1){
                        Word namadicari;
                        int k;
                        int iduser=-1;
                        for ( k= 0; k < banyakUser(l); k++)
                        {
                            boolean tepat=true;
                            for (i = 0; temp.TabWord[i] != '\0'; i++){
                                // printf("%c", temp.TabWord[i]);
                                namadicari.TabWord[i]=temp.TabWord[i];
                                namadicari.Length++;
                                if (namadicari.TabWord[i]!=l.data[k].nama[i]){
                                    tepat=false;
                                }
                            }
                            if (tepat)
                            {
                                iduser=k;
                            }
                        }
                        dummy.idAuthor=iduser;
                    }
                    else{
                        int totwaktu=0;
                        for (int i = 0; temp.TabWord[i] != '\0'; i++) {
                            if (i<2){
                                totwaktu=totwaktu*10+charToInt(temp.TabWord[i]);
                            } else if (i==2){
                                waktu.DD=totwaktu;
                                totwaktu=0;
                            } else if (i<5){                    
                                totwaktu=totwaktu*10+charToInt(temp.TabWord[i]);
                            } else if (i==5){
                                waktu.MM=totwaktu;
                                totwaktu=0;
                            } else if (i<10){                         
                                totwaktu=totwaktu*10+charToInt(temp.TabWord[i]);
                            } else if (i==10){
                                waktu.YYYY=totwaktu;
                                totwaktu=0;
                            } else if (i<13){
                                totwaktu=totwaktu*10+charToInt(temp.TabWord[i]);
                            } else if (i==13){
                                waktu.T.HH=totwaktu;
                                totwaktu=0;
                            } else if (i<16){
                                totwaktu=totwaktu*10+charToInt(temp.TabWord[i]);
                            } else if (i==16){
                                waktu.T.MM=totwaktu;
                                totwaktu=0;
                            } else if (i<19){
                                totwaktu=totwaktu*10+charToInt(temp.TabWord[i]);
                            } else if (i==19){
                                waktu.T.SS=totwaktu;
                                totwaktu=0;
                            }
                        }
                        // TulisDATETIME(dummy.waktu);
                        // printf("\n");
                        
                        while (currentChar == '\n') {
                            ADVconfig();
                        }
                        idUtas=(count+1)/2;
                        indexUtas=(k+1)/3;
                        // printf("indexutas:%d\n",(k+1)/3);
                        // printf("idutas:%d\n",(count+1)/2);
                        // printf("tempid:%d\n",tempid);
                        // printf("%s\n",dummy.text.TabWord);
                        // printf("idauthor:%d\n",dummy.idAuthor);
                        // printf("idutas:%d\n",dummy.idUtas);
                        // TulisDATETIME(dummy.waktu);
                        // printf("\n");
                        CreateUtas(&dummy, iduser, indexUtas, temp, waktu, idUtas);
                        if(idUtas == 1){
                            ADDRESSUTAS(ELMTLISTKICAU(*kicau, tempid)) = newNodeUtas(dummy);
                        }
                        insertLastPers(&((*kicau).buffer[tempid-1].sambunganUtas),dummy);
                    }

                    while (currentChar == '\n') {
                        ADVconfig();
                    }

                }
                count++;
            }
        }
    }
}
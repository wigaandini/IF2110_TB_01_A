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
                if (bacaan.TabWord[i] != '\0')
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
                    if (bacaan.TabWord[i] != '\0')
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
                    if (bacaan.TabWord[i] != '\0')
                    {
                        banyakutas=banyakutas*10+charToInt(bacaan.TabWord[i]);
                    }
                }


                while (currentChar == '\n') {
                    ADVconfig();
                }
                int k;
                UtasType dummy;
                dummy.text.Length = 0;
                // CreateListUtasPers(&((*kicau).buffer[tempid-1].sambunganUtas));
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
                        for (int p = 0; temp.TabWord[p] != '\0'; p++) {
                            dummy.text.TabWord[p]=temp.TabWord[p];
                            dummy.text.Length++;
                        }
                    }
                    else if (k%3==1){
                        Word namadicari;
                        int k;
                        iduser=-1;
                        for ( k= 0; k < banyakUser(l); k++)
                        {
                            boolean tepat=true;
                            for (i = 0; temp.TabWord[i] != '\0'; i++){
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
                                dummy.waktu.DD=totwaktu;
                                dummy.waktu.DD=totwaktu;
                                totwaktu=0;
                            } else if (i<5){                    
                                totwaktu=totwaktu*10+charToInt(temp.TabWord[i]);
                            } else if (i==5){
                                dummy.waktu.MM=totwaktu;
                                dummy.waktu.MM=totwaktu;
                                totwaktu=0;
                            } else if (i<10){                         
                                totwaktu=totwaktu*10+charToInt(temp.TabWord[i]);
                            } else if (i==10){
                                dummy.waktu.YYYY=totwaktu;
                                dummy.waktu.YYYY=totwaktu;
                                totwaktu=0;
                            } else if (i<13){
                                totwaktu=totwaktu*10+charToInt(temp.TabWord[i]);
                            } else if (i==13){
                                dummy.waktu.T.HH=totwaktu;
                                dummy.waktu.T.HH=totwaktu;
                                totwaktu=0;
                            } else if (i<16){
                                totwaktu=totwaktu*10+charToInt(temp.TabWord[i]);
                            } else if (i==16){
                                dummy.waktu.T.MM=totwaktu;
                                dummy.waktu.T.MM=totwaktu;
                                totwaktu=0;
                            } else if (i<18){
                                totwaktu=totwaktu*10+charToInt(temp.TabWord[i]);
                            } else if (i==18){
                                totwaktu = totwaktu * 10 + charToInt(temp.TabWord[i]);
                                dummy.waktu.T.SS=totwaktu;
                                totwaktu=0;
                            }
                        }
                        // TulisDATETIME(dummy.waktu);
                        // printf("\n");
                        
                        while (currentChar == '\n') {
                            ADVconfig();
                        }
                        dummy.idUtas=(count+1)/2;
                        dummy.indexUtas=(k+1)/3;
                        // printf("idutas:%d\n",(count+1)/2);
                        // printf("tempid:%d\n",tempid);
            
                        // ELMTLISTKICAU((*kicau),tempid-1).sambunganUtas = newNodeUtas(dummy);
                        // if(dummy.indexUtas == 1){
                        //     addUtas(kicau, dummy.idAuthor, dummy.indexUtas, dummy.text, dummy.waktu, dummy.idUtas, tempid);
                        // }
                        // else{
                            insertLastPers(&((*kicau).buffer[tempid-1].sambunganUtas),dummy);
                        // }
                        dummy.text.Length = 0;
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
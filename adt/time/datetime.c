/* File: datetime.h */
/* Tanggal: 30 Agustus 2023 */
/* Definisi ADT DATETIME */

#include "time.h"
#include "datetime.h"
#include <stdio.h>
#include <math.h>
// #include "time.c"


/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
int GetMaxDay(int M, int Y){
/* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
/* Prekondisi: 1 <= M <= 12*/
/* Hint: Perhatikan Leap Year. Leap Year adalah tahun dengan 29 hari pada bulan Februari */
/* Aturan Leap Year: */
/* 1. Jika angka tahun itu habis dibagi 400, maka tahun itu sudah pasti tahun kabisat. 8*/
/* 2. Jika angka tahun itu tidak habis dibagi 400 tetapi habis dibagi 100, maka tahun itu sudah pasti bukan merupakan tahun kabisat. */
/* 3. Jika angka tahun itu tidak habis dibagi 400, tidak habis dibagi 100 akan tetapi habis dibagi 4, maka tahun itu merupakan tahun kabisat. */
/* 4. Jika angka tahun tidak habis dibagi 400, tidak habis dibagi 100, dan tidak habis dibagi 4, maka tahun tersebut bukan merupakan tahun kabisat. */
    int max;
    if (M>=1 && M<=7){
        if (M%2 == 0){
            if (M==2){
                if ((Y%400 == 0)){
                    max = 29;
                }
                else if (Y%100 != 0){
                    if (Y%4 == 0){
                        max = 29;
                    }
                    else{
                        max = 28;
                    }
                }
                else{
                    max = 28;
                }
            }
            else{
                max = 30;
            }
        }
        else{
            max = 31;
        }
    }
    else if (M>7 && M<=12){
        if (M%2 == 0){
            max = 31;
        }
        else{
            max = 30;
        }
    }
    return max;
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s){
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */
    return (IsTIMEValid(h,m,s) && (D>=1 && D<=GetMaxDay(M,Y)) && (M>=1 && M<=12) && (Y>=1900 && Y<=2030));
}

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss){
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */
    TIME T;
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    CreateTime(&T, hh, mm, ss);
    Time(*D) = T;
}


/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME *D){
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid */
/* Proses : mengulangi membaca komponen DD, MM, YY, h, m, s sehingga membentuk D */
/* yang valid. Tidak mungkin menghasilkan D yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, MM, YY, h, m, s
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika DATETIME tidak valid maka diberikan pesan: "DATETIME tidak valid", dan pembacaan
    diulangi hingga didapatkan DATETIME yang valid. */
/* Contoh:
    32 13 2023 12 34 56
    DATETIME tidak valid
    31 12 2023 12 34 56
    --> akan terbentuk DATETIME <31,12,2023,12,34,56> */
    int DD, MM, YYYY, h, m, s;
    scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &h, &m, &s);

    while (!IsDATETIMEValid(DD, MM, YYYY, h, m, s)){
        printf("DATETIME tidak valid\n");
        scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &h, &m, &s);
    }

    CreateDATETIME(D, DD, MM, YYYY, h, m, s);
}


void TulisDATETIME(DATETIME D){
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
    printf("%d/%d/%d %02d:%02d:%02d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}


/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2){
/* Mengirimkan true jika D1=D2, false jika tidak */
    return (Day(D1) == Day(D2)) && (Month(D1) == Month(D2)) && (Year(D1) == Year(D2)) && TEQ(Time(D1),Time(D2));
}

boolean DNEQ(DATETIME D1, DATETIME D2){
/* Mengirimkan true jika D1 tidak sama dengan D2 */
    return !DEQ(D1, D2);
}

boolean DLT(DATETIME D1, DATETIME D2){
/* Mengirimkan true jika D1<D2, false jika tidak */
    if (DEQ(D1,D2)){
        return false;
    }
    else if (Year(D1)<Year(D2)){
        return true;
    }
    else if (Year(D1) == Year(D2)){
        if (Month(D1)<Month(D2)){
            return true;
        }
        else if (Month(D1) == Month(D2)){
            if (Day(D1)<Day(D2)){
                return true;
            }
            else if (Day(D1) == Day(D2)){
                if (TLT(Time(D1),Time(D2))){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }    
    }
    else{
        return false;
    }
}


boolean DGT(DATETIME D1, DATETIME D2){
/* Mengirimkan true jika D1>D2, false jika tidak */
    return (!DLT(D1,D2) && !DEQ(D1,D2));
}


/* Cara Nadil */
DATETIME DATETIMENextNDetik(DATETIME D, int N)
/* Mengirim salinan D dengan detik ditambah N */
{
    int DD = Day(D);
    int MM = Month(D);
    int YYYY = Year(D);
    int hh = Hour(Time(D));
    int mm = Minute(Time(D));
    int ss = Second(Time(D));
    ss += N;
    while (ss > 59) {
        ss -= 60;
        mm++;
        if (mm > 59) {
            mm -= 60;
            hh++;
            if (hh > 23) {
                hh -= 24;
                DD++;
                if (DD > GetMaxDay(MM, YYYY)) {
                    DD -= GetMaxDay(MM, YYYY);
                    MM++;
                    if (MM > 12) {
                        MM -= 12;
                        YYYY++;
                    }
                }
            }
        }
    }
    DATETIME D2;
    CreateDATETIME(&D2, DD, MM, YYYY, hh, mm, ss);
    return D2;
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
/* Mengirim salinan D dengan detik dikurang N */
/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
{
    int DD = Day(D);
    int MM = Month(D);
    int YYYY = Year(D);
    int hh = Hour(Time(D));
    int mm = Minute(Time(D));
    int ss = Second(Time(D));
    ss -= N;
    while (ss < 0) {
        ss += 60;
        mm--;
        if (mm < 0) {
            mm += 60;
            hh--;
            if (hh < 0) {
                hh += 24;
                DD--;
                if (DD < 1) {
                    MM--;
                    if (MM < 1) {
                        MM += 12;
                        YYYY--;
                    }
                    DD += GetMaxDay(MM, YYYY);
                }
            }
        }
    }
    DATETIME D2;
    CreateDATETIME(&D2, DD, MM, YYYY, hh, mm, ss);
    return D2;
}



/* Cara Wiga*/
DATETIME DATETIMENextNDetik(DATETIME D, int N){
/* Mengirim salinan D dengan detik ditambah N */
    DATETIME date;
    TIME time;
    long akhir;
    akhir = TIMEToDetik(Time(D)) + N;

    if (akhir >= 86400){
        if (Day(D) == GetMaxDay(Month(D),Year(D))){
            Day(D) = 1;
            if (Month(D) == 12){
                Month(D) = 1;
                Year(D) += 1;
            }
            else{
                Month(D) += 1;
            }
        }
        else{
            Day(D) += 1;
        }

        akhir %= 86400;
        time = DetikToTIME(akhir);
    }

    CreateDATETIME(&date, Day(D), Month(D), Year(D), Hour(time), Minute(time), Second(time));
    return date;
}


DATETIME DATETIMEPrevNDetik(DATETIME D, int N){
/* Mengirim salinan D dengan detik dikurang N */
/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
    DATETIME date;
    TIME time;
    long akhir;
    akhir = TIMEToDetik(Time(D)) - N;

    if (akhir < 0){
        if (Day(D) == 1){
            Day(D) = GetMaxDay(Month(D)-1,Year(D));
            if (Month(D) == 1){
                Month(D) = 12;
                Year(D) -= 1;
            }
            else{
                Month(D) -= 1;
            }
        }
        else{
            Day(D) -= 1;
        }

        akhir += 86400;
        time = DetikToTIME(akhir);
    }

    CreateDATETIME(&date, Day(D), Month(D), Year(D), Hour(time), Minute(time), Second(time));
    return date;
}


long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh){
/* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
/* Prekondisi: DAkh > DAw */
    long dur;
    dur = TIMEToDetik(Time(DAkh)) - TIMEToDetik(Time(DAw));
    Time(DAkh) = Time(DAw);
    while (!DEQ(DAw, DAkh))
    {
        DAw = DATETIMENextNDetik(DAw, 86400);
        dur += 86400;
    }
    return dur;
}
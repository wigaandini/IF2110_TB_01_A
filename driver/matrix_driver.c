#include <stdio.h>
#include "../adt/matrix.c"
#include "../adt/pcolor.c"

int main() {
    // Deklarasi matriks
    Matrix m1, m2, m3;

    // Uji fungsi createMatrix
    createMatrix(3, 3, &m1);
    createMatrix(3, 3, &m2);

    // Uji fungsi readMatrix
    printf("Masukkan elemen matriks m1:\n");
    readMatrix(&m1, 3, 3);

    printf("Masukkan elemen matriks m2:\n");
    readMatrix(&m2, 3, 3);

    // Uji fungsi displayMatrix
    printf("Matriks m1:\n");
    displayMatrix(m1);

    printf("Matriks m2:\n");
    displayMatrix(m2);

    // Uji fungsi addMatrix, subtractMatrix, multiplyMatrix
    m3 = addMatrix(m1, m2);
    printf("Hasil penjumlahan m1 + m2:\n");
    displayMatrix(m3);

    m3 = subtractMatrix(m1, m2);
    printf("Hasil pengurangan m1 - m2:\n");
    displayMatrix(m3);

    m3 = multiplyMatrix(m1, m2);
    printf("Hasil perkalian m1 * m2:\n");
    displayMatrix(m3);

    // Uji fungsi multiplyMatrixWithMod
    int mod = 10;
    m3 = multiplyMatrixWithMod(m1, m2, mod);
    printf("Hasil perkalian (m1 * m2) %% %d:\n", mod);
    displayMatrix(m3);

    // Uji fungsi multiplyByConst, pMultiplyByConst
    ElType k = 2;
    m3 = multiplyByConst(m1, k);
    printf("Hasil perkalian setiap elemen m1 dengan %c:\n", k);
    displayMatrix(m3);

    pMultiplyByConst(&m2, k);
    printf("Hasil perkalian setiap elemen m2 dengan %c (m2 diubah secara in-place):\n", k);
    displayMatrix(m2);

    // Uji fungsi isMatrixEqual, isMatrixNotEqual, isMatrixSizeEqual
    if (isMatrixEqual(m1, m2)) {
        printf("Matriks m1 sama dengan m2.\n");
    } else {
        printf("Matriks m1 tidak sama dengan m2.\n");
    }

    if (isMatrixNotEqual(m1, m2)) {
        printf("Matriks m1 tidak sama dengan m2.\n");
    } else {
        printf("Matriks m1 sama dengan m2.\n");
    }

    if (isMatrixSizeEqual(m1, m2)) {
        printf("Ukuran efektif matriks m1 sama dengan m2.\n");
    } else {
        printf("Ukuran efektif matriks m1 tidak sama dengan m2.\n");
    }

    // Uji fungsi isSquare, isSymmetric, isIdentity, isSparse
    if (isSquare(m1)) {
        printf("Matriks m1 adalah matriks persegi.\n");
    } else {
        printf("Matriks m1 bukan matriks persegi.\n");
    }

    if (isSymmetric(m1)) {
        printf("Matriks m1 adalah matriks simetri.\n");
    } else {
        printf("Matriks m1 bukan matriks simetri.\n");
    }

    if (isIdentity(m1)) {
        printf("Matriks m1 adalah matriks identitas.\n");
    } else {
        printf("Matriks m1 bukan matriks identitas.\n");
    }

    if (isSparse(m1)) {
        printf("Matriks m1 adalah matriks sparse.\n");
    } else {
        printf("Matriks m1 bukan matriks sparse.\n");
    }

    // Uji fungsi negation, pNegation
    m3 = negation(m1);
    printf("Hasil negasi m1:\n");
    displayMatrix(m3);

    pNegation(&m2);
    printf("Hasil negasi m2 (m2 diubah secara in-place):\n");
    displayMatrix(m2);

    // Uji fungsi determinant
    if (isSquare(m1)) {
        float det = determinant(m1);
        printf("Determinan matriks m1: %.2f\n", det);
    } else {
        printf("Matriks m1 bukan matriks persegi, tidak dapat menghitung determinan.\n");
    }

    // Uji fungsi transpose, pTranspose
    m3 = transpose(m1);
    printf("Hasil transpose m1:\n");
    displayMatrix(m3);

    pTranspose(&m2);
    printf("Hasil transpose m2 (m2 diubah secara in-place):\n");
    displayMatrix(m2);

    return 0;
}

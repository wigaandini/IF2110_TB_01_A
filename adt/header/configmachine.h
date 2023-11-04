/* File: configmachine.h */
/* Definisi Mesin Karakter */

#ifndef __CONFIG_MACHINE_H__
#define __CONFIG_MACHINE_H__

// #define MARK ';'

#include "boolean.h"
#include "charmachine.h"

// extern char currentChar;
// extern boolean EOP;

void STARTconfig();


void ADVconfig();

#endif


// CARA PAKEK configmachine untuk baca setiap line
    // while (!EOP) {
    //     Word bacaan;
    //     int i = 0;

    //     while (!EOP && currentChar != '\n') {
    //         bacaan.TabWord[i] = currentChar;
    //         i++;
    //         ADVconfig();
    //     }
    //     bacaan.TabWord[i] = '\0';

    //     for (int i = 0; bacaan.TabWord[i] != '\0'; i++) {
    //         printf("%c", bacaan.TabWord[i]);
    //     }
    //     printf("\n");


    //     while (currentChar == '\n') {
    //         ADVconfig();
    //     }
    // }
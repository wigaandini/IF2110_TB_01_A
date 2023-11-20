/* File: configmachine.c */
/* Implementasi Mesin Karakter */

#include <stdio.h>
#include "header/configmachine.h"

static FILE *pita;

void ADVconfig() {
    if (fscanf(pita, "%1c", &currentChar) != 1) {
        currentChar = MARK;
        EOP = true;
    } else {
        EOP = false;
    }

    if (EOP)
    {
        fclose(pita);
    }
    
}

void STARTconfig(char *x){
    pita = fopen(x, "r");
    ADVconfig();
}
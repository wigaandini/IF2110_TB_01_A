#include "../adt/wordmachine.c"
#include "../adt/charmachine.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    STARTSENTENCE();
    displayWord(currentWord);
    printf("\n");
    // printf("%d\n", WordToInt(currentWord));
    displayString(WordToString(currentWord));
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
// #include "mesinkarakter.c"
// #include "mesinkata.c"

char decryptBev(char bev, int geser) {
    if (bev >= 'A' && bev <= 'Z') {
        return (bev - 'A' - geser + 26) % 26 + 'A';
    } else if (bev >= 'a' && bev <= 'z') {
        return (bev - 'a' - geser + 26) % 26 + 'a';
    }
    return bev;
}

int main(void) {
    STARTWORD();
    
    int shift = 0;
    sscanf(currentWord.TabWord, "%d", &shift);
    shift %= 26;

    ADVWORD();
    
    while (!EndWord) {
        for (int i = 0; i < currentWord.Length; i++) {
            char decryptedBev = decryptBev(currentWord.TabWord[i], shift);
            printf("%c", decryptedBev);
        }
        
        ADVWORD();
        if (!EndWord) {
            printf(" ");
        }
    }
    
    printf("\n");
    return 0;
}
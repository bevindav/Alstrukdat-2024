#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
// #include "mesinkarakter.c"
// #include "mesinkata.c"

boolean mangEak(Word kata) {
    if (kata.Length > 50) return false;

    int oktet_count = 0;
    int at_count = 0;
    char buffer[51];
    strncpy(buffer, kata.TabWord, kata.Length);
    buffer[kata.Length] = '\0';

    for (int i = 0; i < kata.Length; i++) {
        if (!((buffer[i] >= '0' && buffer[i] <= '9') || buffer[i] == '@')) {
            return false;
        }
        if (buffer[i] == '@') {
            at_count++;
        }
    }

    if (at_count != 3) return false;

    char *bev = strtok(buffer, "@");
    while (bev != NULL) {
        if (oktet_count >= 4) return false;

        int panjang = strlen(bev);
        if (panjang == 0 || (panjang > 1 && bev[0] == '0')) return false;

        for (int i = 0; i < panjang; i++) {
            if (bev[i] < '0' || bev[i] > '9') return false;
        }

        int oktet = atoi(bev);
        if (oktet < 0 || oktet > 255) return false;

        oktet_count++;
        bev = strtok(NULL, "@");
    }

    return oktet_count == 4;
}

int main() {
    STARTWORD();
    
    boolean first = true;
    while (!EndWord) {
        if (!first) {
            printf(" ");
        }

        if (mangEak(currentWord)) {
            printf("4Lay");
        } else {
            printf("ewh");
        }

        first = false;
        ADVWORD();
    }
    
    printf("\n");
    return 0;
}
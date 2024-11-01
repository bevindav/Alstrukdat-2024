#include <math.h>
#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik L1;
    readList(&L1);    
    int n = listLength(L1);
    boolean carry = true;
    int i = n - 1;

    while (carry) {
        if (i == -1) {
            insertFirst(&L1, 1);
            carry = false;
        } else {
            ELMT(L1, i) += 1;
            if (ELMT(L1, i) == 10) {
                ELMT(L1, i) = 0;
            } else {
                carry = false;
            }
        }
        i--;
    }

    for (i = 0; i < listLength(L1); i++) {
        printf("%d", ELMT(L1, i));
        if (i != listLength(L1) - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
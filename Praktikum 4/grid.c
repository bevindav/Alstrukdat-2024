#include <stdio.h>
#include "matrix.h"

const int MOD = 1000000007;

Matrix m1;
Matrix jalur;
int main(void) {
    int n;
    scanf("%d", &n);
    readMatrix(&m1, n, n);
    createMatrix(n, n, &jalur);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ELMT(jalur, i, j) = 0;
        }
    }
    int rowAkhir = getLastIdxRow(m1);
    int colAkhir = getLastIdxCol(m1);
    ELMT(jalur, rowAkhir, colAkhir)= 1;
    for (i = rowAkhir; i >= 0; i--) {
        for (j = colAkhir; j >= 0; j--) {
            if (ELMT(m1, i, j) == 1) {
                ELMT(jalur, i, j) = 0;
            } else {
                if (i + 1 <= rowAkhir) {
                    ELMT(jalur, i, j) = (ELMT(jalur, i, j) + ELMT(jalur, i + 1, j)) % MOD;
                }
                if (j + 1 <= colAkhir) {
                    ELMT(jalur, i, j) = (ELMT(jalur, i, j) + ELMT(jalur, i, j + 1)) % MOD;
                }
            }
        }
    }

    printf("%d\n", ELMT(jalur, 0, 0) % MOD);
    return 0;
}

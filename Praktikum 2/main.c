#include <math.h>
#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik L1, frekuensi, unik;
    readList(&L1);    
    CreateListStatik(&frekuensi);
    CreateListStatik(&unik);

    int n = listLength(L1);
    for (int i = 0; i < n; i++) {
        if (ELMT(frekuensi, ELMT(L1, i)) == MARK) {
            ELMT(frekuensi, ELMT(L1, i)) = 1;
            insertLast(&unik, ELMT(L1, i));
        } else {
            ELMT(frekuensi, ELMT(L1, i)) += 1;
        }
    }

    int maks = 0;
    for (int i = 1; i < listLength(unik); i++) {
        if (ELMT(frekuensi, ELMT(unik, i)) > ELMT(frekuensi, ELMT(unik, maks))) {
            maks = i;
        }
    }

    int maks2 = -1;
    for (int i = 0; i < listLength(unik); i++) {
        if (ELMT(frekuensi, ELMT(unik, i)) == ELMT(frekuensi, ELMT(unik, maks))) continue;

        if (maks2 == -1) {
            maks2 = i;
            continue;
        }

        if (ELMT(frekuensi, ELMT(unik, i)) > ELMT(frekuensi, ELMT(unik, maks2))) {
            maks2 = i;
        } else if (ELMT(frekuensi, ELMT(unik, i)) == ELMT(frekuensi, ELMT(unik, maks2))) {
            if (ELMT(unik, i) < ELMT(unik, maks2)) {
                maks2 = i;
            }
        }
    }

    if (maks2 == -1) {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    } else {
        printf("%d\n", ELMT(unik, maks2));
    }
    return 0;
}
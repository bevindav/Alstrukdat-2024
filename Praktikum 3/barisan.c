#include <stdio.h>
#include "listdin.h"
// #include "listdin.c"

int main() {
    ListDin l, ltemp;
    int i, j, k, back = 0;
    boolean found = false;

    // list input
    CreateListDin(&l, 1000);
    readList(&l);

    // membuat list kosong temporary
    CreateListDin(&ltemp, 1000);

    // masukan elemen pertama list l ke list temporary
    ELMT(ltemp, 0) = ELMT(l, 0);
    NEFF(ltemp) = 1;

    for (i = 1; i < listLength(l); i++) {
        j = 0;
        found = false;

        while (!found && j <= getLastIdx(ltemp)) {
            if (ELMT(l, i) < ELMT(ltemp, j)) {
                // mundurin angka2 selanjutnya
                for (k = getLastIdx(ltemp); k >= j; k--) {
                    ELMT(ltemp, k + 1) = ELMT(ltemp, k);
                }
                ELMT(ltemp, j) = ELMT(l, i);
                back += (getLastIdx(ltemp) - j + 1); // itung mundur sekaligus
                // ini tuh kann codenya ngitung berapa banyak geser dengan nanti yang paling kecil agaknya digeser ke depan gitu lah
                // contohnya di kasus input tc:
                // 3
                // 4 5 1
                
                // itu tuh awalnya kan l [4, 5, 1]
                // nah di awal inisiasi yg enih     ELMT(ltemp, 0) = ELMT(l, 0);
                // bikin ltemp isinya [4]
                // di iterasi pertama i = 1, j = 0, ELMT(l, i) = 5, ELMT(ltemp, j) = 4, nah karna salah masuk ke else
                // terus pas iterasi j = 1 si 5 lebih besar dari semuanya yaudah, masuk ke if(!found) jadi dimasukkin ke temp
                // jadi ltemp = [4, 5]
                //nah karna udh kek gitu, sisa 1 nya itu dimasukkin ke indeks 0
                // ok makanya backnya diitung pake (getLastIdx(ltemp) - j + 1), yang kondisinya indeks akhir ltemp = 1, j = 0
                // makanya 1 - 0 + 1 = 2
                found = true;
            } else {
                j++;
            }
        }

        if (!found) {
            insertLast(&ltemp, ELMT(l, i));
        } else {
            NEFF(ltemp)++;
        }
    }

    printf("%d\n", back);

    return 0;
}

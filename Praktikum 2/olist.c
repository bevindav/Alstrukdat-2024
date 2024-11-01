#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik L1;
    ElType val;
    readList(&L1);

    ListStatik unik, frekuensi;
    CreateListStatik(&unik);
    CreateListStatik(&frekuensi);

    int n = listLength(L1);

    for (int i = 0; i < n; i++) {
        if (indexOf(unik, ELMT(L1, i)) == IDX_UNDEF) {
            insertLast(&unik, ELMT(L1, i)); 
            insertLast(&frekuensi, 1);          
        } else {
            int id = indexOf(unik, ELMT(L1, i));
            ELMT(frekuensi, id)++;  
        }
    }

    printList(unik);
    printf("\n");

    for (int i = 0; i < listLength(unik); i++) {
        printf("%d %d\n", ELMT(unik, i), ELMT(frekuensi, i));
    }

    return 0;
}

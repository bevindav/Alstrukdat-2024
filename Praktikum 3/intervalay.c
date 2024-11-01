#include <stdio.h>
#include <math.h>
#include "listdin.h"

int main() {
    int n;
    scanf("%d", &n);

    ListDin resultList, inputList;
    CreateListDin(&inputList, n);
    CreateListDin(&resultList, n + 2);

    int idx;
    for (idx = 0; idx < n; idx++) {
        scanf("%d", &ELMT(inputList, idx));
        NEFF(inputList)++;
    }

    int leftBound, rightBound;
    scanf("%d", &leftBound);
    scanf("%d", &rightBound);

    boolean isInserted = 0;
    for (idx = 0; idx < listLength(inputList); idx += 2) {
        int currentStart = ELMT(inputList, idx);
        int currentEnd = ELMT(inputList, idx + 1);

        if (currentStart > rightBound && !isInserted) {
            insertLast(&resultList, leftBound);
            insertLast(&resultList, rightBound);
            isInserted = 1;
        }

        if (listLength(resultList) > 0 && ELMT(resultList, getLastIdx(resultList)) >= currentStart) {
            if (ELMT(resultList, getLastIdx(resultList)) < currentEnd) {
                ELMT(resultList, getLastIdx(resultList)) = currentEnd;
            }
            continue;
        }

        if (!isInserted && currentEnd >= leftBound && rightBound >= currentStart) {
            isInserted = 1;
            if (currentStart > leftBound) {
                currentStart = leftBound;
            }
            if (currentEnd < rightBound) {
                currentEnd = rightBound;
            }
        }

        insertLast(&resultList, currentStart);
        insertLast(&resultList, currentEnd);
    }

    if (!isInserted) {
        insertLast(&resultList, leftBound);
        insertLast(&resultList, rightBound);
    }

    for (idx = 0; idx < listLength(resultList); idx++) {
        if (idx != listLength(resultList) - 1) 
            printf("%d ", ELMT(resultList, idx));
        else 
            printf("%d\n", ELMT(resultList, idx));
    }
}

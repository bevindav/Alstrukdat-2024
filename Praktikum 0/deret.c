#include <stdio.h>

int main () {
    int a, b, i;
    scanf("%d %d", &a, &b);
    
        if (a == b) {
        printf("%d\n", a);
        return 0;
    }
    printf("%d ", a);
    
    for (i = a; i <= b;) {
        if (i % 2 == 0) {
            i = i * 2;
            if (i <= b) {
                if (i + 1 > b || i * 2 > b) {
                    printf("%d", i);
                } else {
                    printf("%d ", i);
                }
            }

        } else if (i % 2 == 1) {
            i = i + 1;
            if (i <= b) {
                if (i + 1 > b || i * 2 > b) {
                    printf("%d", i);
                } else {
                    printf("%d ", i);
                }
            }
        }
    }
    
    printf("\n");
    return 0;
}

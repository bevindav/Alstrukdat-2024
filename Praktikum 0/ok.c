# include <stdio.h>

int main () {
    int n, k, b, sum=0;
    scanf("%d %d", &n, &k);
    while (n>0){
        scanf("%d", &b);
            if (b%k != 0){
                sum = sum + b;
                n = n-1;
                }
            else {
                n = n-1;
            }
    }
    printf("%d\n", sum);
    return 0;
}
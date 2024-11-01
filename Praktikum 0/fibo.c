#include <stdio.h>

int hitung_fibonacci(int n, int a, int b) {
    if (n == 1)
        return a;
    if (n == 2)
        return b;
    
    int fib1 = a, fib2 = b, fib_n;
    for (int i = 3; i <= n; i++) {
        fib_n = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib_n;
    }
    
    return fib_n;
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    printf("%d\n", hitung_fibonacci(n, a, b));
    return 0;
}

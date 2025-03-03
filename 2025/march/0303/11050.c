#include <stdio.h>

int f(int n) { 
    return n ? n * f(n - 1) : 1; 
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", f(n) / (f(k) * f(n - k)));
    return 0;
}

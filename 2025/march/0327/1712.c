#include <stdio.h>

int main() {
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);
    
    if (B >= C) printf("-1");
    else printf("%lld", (A / (C - B)) + 1);
    
    return 0;
}

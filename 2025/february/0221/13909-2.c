#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long count=0;
    long long i=1;
    while (i*i <= n) { // i의 제곱이 N 이하일 때까지
        count++;
        i++;
    }
    printf("%lld", count);
    
    return 0;
}

#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    // 코드1 수행 횟수 계산: nC3 = n * (n-1) * (n-2) / 6
    long long count = (n * (n - 1) * (n - 2)) / 6;
    printf("%lld\n", count);
    printf("3"); // 최고차항의 차수는 3

    return 0;
}

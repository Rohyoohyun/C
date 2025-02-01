#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", n * (n - 1) / 2); // 코드1의 수행 횟수 출력
    printf("2\n"); // 최고차항의 차수 출력

    return 0;
}

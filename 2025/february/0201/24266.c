#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", n * n * n); // 코드1의 수행 횟수 출력
    printf("3"); // 최고차항의 차수 출력

    return 0;
}

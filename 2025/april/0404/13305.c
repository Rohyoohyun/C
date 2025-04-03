#include <stdio.h>

#define MAX 100000

long long d[MAX];  // 도로 길이 저장
long long p[MAX];  // 주유소 가격 저장

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N - 1; i++) {
        scanf("%lld", &d[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%lld", &p[i]);
    }

    long long minP = p[0];  // 현재까지의 최소 주유 가격
    long long cost = 0;     // 총 비용

    for (int i = 0; i < N - 1; i++) {
        if (p[i] < minP) {
            minP = p[i];  // 최소 기름 가격 갱신
        }
        cost += minP * d[i];  // 최소 가격으로 주유
    }

    printf("%lld", cost);
    return 0;
}

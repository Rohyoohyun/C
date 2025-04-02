#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int B, C;  // 총감독관이 감시 가능한 인원, 부감독관이 감시 가능한 인원
    scanf("%d %d", &B, &C);

    long long total= 0;  // 필요한 감독관 수 (큰 값이므로 long long)
    for (int i = 0; i < N; i++) {
        // 1. 총감독관 1명 배치
        total++;
        int rem = A[i] - B;

        // 2. 남은 인원을 부감독관이 감시해야 함
        if (rem > 0) {
            total += (rem+ C - 1) / C;  // 올림 계산
        }
    }

    printf("%lld", total);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#define MAX 1000000

bool prime[MAX + 1]; // 소수 여부를 저장하는 배열

// 에라토스테네스의 체를 이용한 소수 판별
void func() {
    for (int i=2; i<=MAX; i++) {
        prime[i] = true; // 모든 수를 우선 소수로 가정
    }

    for (int i=2; i*i <= MAX; i++) {
        if (prime[i]) { // i가 소수이면
            for (int j=i*i; j<=MAX; j+=i) { // i의 배수 제거
                prime[j] = false;
            }
        }
    }
}

// N의 골드바흐 파티션 개수 세기
int count_goldbach(int N) {
    int count = 0;

    // p ≤ q 조건을 만족하기 위해 p만 탐색
    for (int p=2; p <= N/2; p++) {
        int q = N-p;
        if (prime[p] && prime[q]) {
            count++;
        }
    }
    return count;
}

int main() {
    func();

    int T, N;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);
        printf("%d\n", count_goldbach(N));
    }

    return 0;
}

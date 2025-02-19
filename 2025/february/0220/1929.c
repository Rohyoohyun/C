#include <stdio.h>
#include <stdbool.h>
#define MAX 1000000

bool is_prime[MAX+1]; // 소수 여부를 저장하는 배열

// 에라토스테네스의 체 알고리즘을 사용하여 소수 판별
void func(int n) {
    // 모든 수를 소수(true)로 초기화
    for (int i=2; i<=n; i++) {
        is_prime[i] = true;
    }

    // 2부터 √N 까지 반복하며 배수들을 제거
    for (int i=2; i*i<=n; i++) {
        if (is_prime[i]) { // 현재 수가 소수라면
            for (int j=i*i; j<=n; j+=i) { // i의 배수를 모두 제거
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &m, &n);

    func(n); // N까지의 소수를 미리 계산
    for (int i=m; i<=n; i++) {
        if (is_prime[i]) printf("%d\n", i);
    }

    return 0;
}

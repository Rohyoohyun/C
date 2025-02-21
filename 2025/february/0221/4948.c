#include <stdio.h>
#include <stdbool.h>
#define MAX 250000  // 2 × 123,456 (문제에서 최대 범위)

// 소수 여부를 저장하는 배열
bool is_prime[MAX + 1];

// 에라토스테네스의 체 알고리즘을 사용하여 소수 판별
void func() {
    // 모든 수를 소수(true)로 초기화
    for (int i=2; i<=MAX; i++) {
        is_prime[i] = true;
    }

    // 2부터 √MAX 까지 반복하며 배수들을 제거
    for (int i=2; i*i<=MAX; i++) {
        if (is_prime[i]) { // 현재 수가 소수라면
            for (int j=i*i; j<=MAX; j += i) { // i의 배수를 모두 제거
                is_prime[j] = false;
            }
        }
    }
}

// n보다 크고 2n 이하의 소수 개수를 세는 함수
int count_primes(int n) {
    int count = 0;
    for (int i = n+1; i <= 2*n; i++) {
        if (is_prime[i]) count++;
    }
    return count;
}

int main() {
    func(); // 소수를 미리 계산하여 저장

    int n;
    while (scanf("%d", &n) == 1 && n != 0) { // 입력을 조건으로 사용
        printf("%d\n", count_primes(n)); // n보다 크고 2n 이하의 소수 개수 출력
    }

    return 0;
}

#include <stdio.h>
#include <math.h>

// 주어진 수 n이 소수인지 판별하는 함수
int is_prime(long long n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;

    // 짝수이거나 3의 배수이면 소수X
    if (n%2 == 0 || n%3 == 0) return 0;

    // 5부터 √n 까지 6씩 증가하며 나누어지는지 확인
    // 모든 소수는 6k ± 1 형태이므로 6의 배수 ± 1만 검사
    for (long long i = 5; i * i <= n; i += 6) {
        // i 또는 i+2 중 하나라도 n을 나누면 소수가 아님
        if (n%i == 0 || n%(i+2) == 0) return 0;
    }
    return 1;
}

// n 이상의 가장 작은 소수를 찾는 함수
long long func(long long n) {
    while (!is_prime(n)) { // n이 소수가 아닐 경우, n을 1씩 증가시키며 가장 가까운 소수를 찾음
        n++;
    }

    return n; // 소수를 찾으면 해당 값을 반환
}

int main() {
    int t; 
    scanf("%d", &t);

    while (t--) {
        long long n; // 입력받을 정수 (최대 4 * 10^9이므로 long long 사용)
        scanf("%lld", &n);
        printf("%lld\n", func(n)); // n보다 크거나 같은 가장 작은 소수를 찾아 출력
    }

    return 0;
}

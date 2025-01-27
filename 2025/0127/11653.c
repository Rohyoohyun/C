#include <stdio.h>

void func(int n) {
    for (int i=2; i*i<=n; i++) { // i는 2부터 시작하며, n의 제곱근까지 확인
        while (n%i == 0) {       // i로 나누어떨어질 때마다 출력
            printf("%d\n", i);
            n /= i;              // n을 i로 나눔 (확인된 소인수를 반복해서 처리하지 않도록 하기 위함)
        }
    }
    if (n > 1) printf("%d", n); // 마지막 소인수
}

int main() {
    int n;
    scanf("%d", &n);
    func(n);
    return 0;
}
#include <stdio.h>

int func(int n) {
    if (n < 2) return 0;
    for (int i=2; i*i<=n; i++) { // n의 제곱근까지만 확인
        if (n%i == 0) return 0; // 나누어 떨어지면 소수가 아님
    }
    return 1; // 소수임
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int sum = 0, min = 10001;
    for (int i=m; i<=n; i++) {
        if(func(i)) {
            sum += i; // 소수라면 합에 더함
            if (i < min) min = i;
        }
    }

    if (sum == 0) printf("-1");
    else printf("%d\n%d", sum, min);

    return 0;
}

#include <stdio.h>

// 최대공약수(GCD) 계산 (유클리드 알고리즘)
long long int gcd(long long int a, long long int b) {
    while (b != 0) {
        long long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 최소공배수(LCM) 계산
long long int lcm(long long int a, long long int b) {
    return (a / gcd(a, b)) * b;  // 오버플로우 방지를 위해 (A / GCD) 먼저 계산
}

int main() {
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld", lcm(a, b));
    return 0;
}
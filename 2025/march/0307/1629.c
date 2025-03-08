#include <stdio.h>

long long power(long long a, long long b, long long c) {
    if (b == 0) return 1;  // A^0 = 1
    long long half = power(a, b / 2, c);
    half = (half * half) % c;
    
    if (b % 2 == 1) // 홀수이면 한 번 더 곱하기
        half = (half * a) % c;
    
    return half;
}

int main() {
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);
    printf("%lld", power(A, B, C));
    return 0;
}

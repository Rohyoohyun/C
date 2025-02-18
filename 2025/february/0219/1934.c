#include <stdio.h>

// 최대공약수를 구하는 함수 (유클리드 알고리즘)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 최소공배수를 구하는 함수
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b; // 오버플로우 방지를 위해 A/B 후 곱셈
}

int main() {
    int T, a, b;
    scanf("%d", &T);
    
    while (T--) {
        // A와 B 입력
        scanf("%d %d", &a, &b);
        printf("%d\n", lcm(a, b));
    }
    
    return 0;
}
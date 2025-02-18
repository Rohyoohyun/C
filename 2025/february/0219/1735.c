#include <stdio.h>

// 최대공약수(GCD) 계산 (유클리드 호제법)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b, c, d;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);
    
    // 두 분수의 합 계산
    int num = a*d + c*b; // 새로운 분자
    int denum = b*d;       // 새로운 분모
    
    // 기약분수로 변환
    int g = gcd(num, denum);
    num /= g;
    denum /= g;
    printf("%d %d", num, denum);
    
    return 0;
}

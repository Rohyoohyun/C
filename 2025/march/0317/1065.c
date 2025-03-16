#include <stdio.h>

int func(int n) {
    if (n < 100) return 1;

    int a = n/100;       // 백의 자리
    int b = (n/10) % 10; // 십의 자리
    int c = n%10;        // 일의 자리

    return (a-b == b-c); // 등차수열 여부 확인
}

int main() {
    int n, count = 0;
    scanf("%d", &n);

    for (int i=1; i<=n; i++) {
        if (func(i)) count++;
    }
    printf("%d", count);
    
    return 0;
}

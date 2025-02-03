#include <stdio.h>

// 각 자리수의 합을 구하는 함수
int func(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int res = 0;
    
    // 가능한 최소 생성자는 N - 9 * 자릿수
    for (int i=n-9*6; i<n; i++) {
        if (i > 0 && i+func(i) == n) {
            res = i;
            break;
        }
    }
    printf("%d", res);
    
    return 0;
}

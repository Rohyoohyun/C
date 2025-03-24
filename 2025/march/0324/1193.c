#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    
    int n = 1; // 대각선 그룹 번호
    while (x > n*(n+1)/2) {
        n++;
    }
    
    int idx = x - (n*(n-1)/2); // 해당 대각선에서 몇 번째인지
    int num, den;
    
    if (n%2 == 1) { // 홀수 대각선이면 위에서 아래로
        num = n+1 - idx;
        den = idx;
    } else { // 짝수 대각선이면 아래에서 위로
        num = idx;
        den = n+1 - idx;
    }
    
    printf("%d/%d", num, den);
    return 0;
}
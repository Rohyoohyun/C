#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    // 삼각형 조건: 가장 긴 변이 나머지 두 변의 합보다 작아야 함
    while (a >= b + c) a--;
    while (b >= a + c) b--;
    while (c >= a + b) c--;
    printf("%d", a + b + c);
    
    return 0;
}
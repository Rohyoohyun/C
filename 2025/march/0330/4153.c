#include <stdio.h>

void check_triangle(int a, int b, int c) {
    int max, x, y;
    
    // 가장 긴 변 찾기
    if (a > b && a > c) {
        max = a; 
        x = b; 
        y = c;
    } else if (b > a && b > c) {
        max = b; 
        x = a; 
        y = c;
    } else {
        max = c; 
        x = a; 
        y = b;
    }
    
    // 직각 삼각형 판별
    if (max * max == x*x + y*y) puts("right");
    else puts("wrong");
}

int main() {
    int a, b, c;
    
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;
        check_triangle(a, b, c);
    }
    
    return 0;
}

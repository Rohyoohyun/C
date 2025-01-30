#include <stdio.h>

int main() {
    int a, b, c;
    
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break; // 종료 조건
        
        if (a + b <= c || a + c <= b || b + c <= a) puts("Invalid");
        else if (a == b && b == c) puts("Equilateral");
        else if (a == b || a == c || b == c) puts("Isosceles");
        else puts("Scalene");
    }
    
    return 0;
}

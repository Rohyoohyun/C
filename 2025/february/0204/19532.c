#include <stdio.h>

int main() {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    
    int D = a*e - b*d;
    int Dx = c*e - b*f;
    int Dy = a*f - c*d;
    
    int x = Dx / D;
    int y = Dy / D;
    
    printf("%d %d\n", x, y);
    
    return 0;
}

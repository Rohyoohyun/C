#include <stdio.h>

int main() {
    int E, S, M;
    scanf("%d %d %d", &E, &S, &M);
    
    int year = 1;
    int e = 1, s = 1, m = 1;
    
    while (!(e == E && s == S && m == M)) {
        year++;
        e++; s++; m++;
        
        if (e > 15) e = 1;
        if (s > 28) s = 1;
        if (m > 19) m = 1;
    }
    printf("%d", year);
    
    return 0;
}

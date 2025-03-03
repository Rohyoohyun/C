#include <stdio.h>

int main() {
    int n, min = 1000000, max = 2, x;
    scanf("%d", &n);
    
    while (n--) {
        scanf("%d", &x);
        if (x < min) min = x;
        if (x > max) max = x;
    }
    printf("%d", min*max);
    
    return 0;
}

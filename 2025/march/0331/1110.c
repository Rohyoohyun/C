#include <stdio.h>

int main() {
    int n, nn, cl = 0;
    scanf("%d", &n);
    
    int on = n;
    while (1) {
        int t = n / 10;
        int o = n % 10;
        int s = t + o;
        nn = (o * 10) + (s % 10);
        n = nn;
        cl++;
        
        if (nn == on) break;
    }
    
    printf("%d", cl);
    return 0;
}

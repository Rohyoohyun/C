#include <stdio.h>

int main() {
    int X, N, a, b, total = 0;
    scanf("%d", &X);
    scanf("%d", &N);
    
    for (int i=0; i<N; i++) {
        scanf("%d %d", &a, &b);
        total += a*b;
    }
    
    if (total == X) printf("Yes");
    else printf("No");
    
    return 0;
}

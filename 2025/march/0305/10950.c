#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%d", &n);
    for(int i=0; i<n; i++, puts("")){
        scanf("%d %d", &a, &b);
        printf("%d", a+b);
    }
    return 0;
}

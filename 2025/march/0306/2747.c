#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) { printf("0");return 0;    }

    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    printf("%d", b);
    
    return 0;
}

#include <stdio.h>

int main() {
    int N, count = 0;
    scanf("%d", &N);

    for (int i = 5; i <= N; i *= 5) {
        count += N / i;
    }
    printf("%d", count);
    return 0;
}

#include <stdio.h>

int main() {
    int a1, a0, c, n0;
    scanf("%d %d", &a1, &a0);
    scanf("%d", &c);
    scanf("%d", &n0);

    // O(n) 정의를 만족하려면 f(n) ≤ c * g(n)이어야 함.
    // 즉, a1 * n + a0 ≤ c * n이 되어야 함.
    // 정리하면 a1 * n + a0 - c * n ≤ 0 → (a1 - c) * n + a0 ≤ 0
    
    int res = 1;
    for (int n = n0; n <= 100; n++) {
        if ((a1 - c) * n + a0 > 0) {
            res = 0;
            break;
        }
    }
    printf("%d", res);
    
    return 0;
}

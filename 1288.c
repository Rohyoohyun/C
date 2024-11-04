#include <stdio.h>

int memo[13][13] = {0};
int ncr(int n, int r) {
    if (memo[n][r]) return memo[n][r];
    if (r == 1) return memo[n][r] = n;
    if (r == n) return memo[n][r] = 1;
    return memo[n][r] = ncr(n-1, r-1) + ncr(n-1, r);
}

int main() {
    int n, r;
    scanf("%d %d", &n, &r);
    printf("%d", ncr(n, r));
    return 0;
}
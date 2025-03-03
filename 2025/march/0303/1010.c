#include <stdio.h>

long long func(int n, int r) {
    long long res = 1;
    if (r > n-r) r = n-r;  // nCr = nC(n-r), 작은 값 선택
    for (int i=0; i<r; i++) {
        res = res * (n-i) / (i+1);
    }
    return res;
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        printf("%lld\n", func(m, n));
    }
    return 0;
}

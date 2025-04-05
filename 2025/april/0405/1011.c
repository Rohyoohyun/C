#include <stdio.h>
#include <math.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        long long x, y;
        scanf("%lld %lld", &x, &y);

        long long d = y - x;
        long long k = (long long)sqrt(d);  // 정수 제곱근

        if (k * k == d) printf("%lld\n", 2 * k - 1);
        else if (d <= k * (k + 1)) printf("%lld\n", 2 * k);
        else printf("%lld\n", 2 * k + 1);
    }

    return 0;
}

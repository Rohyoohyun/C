#include <stdio.h>
#define MAX 1000000
int d[MAX * 2], f = MAX, r = MAX;  // 덱 배열 및 front, rear 초기화

int main() {
    int n, c, x;
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &c);
        if (c == 1) scanf("%d", &x), d[--f] = x;
        else if (c == 2) scanf("%d", &x), d[r++] = x;
        else if (c == 3) printf("%d\n", f == r ? -1 : d[f++]);
        else if (c == 4) printf("%d\n", f == r ? -1 : d[--r]);
        else if (c == 5) printf("%d\n", r - f);
        else if (c == 6) printf("%d\n", f == r);
        else if (c == 7) printf("%d\n", f == r ? -1 : d[f]);
        else if (c == 8) printf("%d\n", f == r ? -1 : d[r - 1]);
    }
}

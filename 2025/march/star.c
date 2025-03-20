// 포인터 별 문제

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1], *p = s;
    for (int i=0; i<n; i++) {
        *(p+i) = '*';
        puts(s);
    }
}

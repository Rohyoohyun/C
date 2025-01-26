#include <stdio.h>

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == -1) break; // 종료 조건

        int div[10001]; // 약수를 저장할 배열
        int cnt = 0, sum = 0; // 약수들의 개수, 합

        // 약수 찾기
        for (int i=1; i<n; i++) {
            if (n % i == 0) {
                div[cnt++] = i;
                sum += i;
            }
        }

        // 완전수 여부 판단 및 출력
        if (sum == n) {
            printf("%d =", n);
            for (int i = 0; i<cnt; i++) {
                if (i > 0) printf(" +");
                printf(" %d", div[i]);
            }
            puts("");
        } else printf("%d is NOT perfect.\n", n);
    }

    return 0;
}

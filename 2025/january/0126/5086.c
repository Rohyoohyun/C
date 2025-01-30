#include <stdio.h>

int main() {
    int a, b;
    while (1) {
        scanf("%d %d", &a, &b); // 두 수 입력

        // 종료 조건
        if (a == 0 && b == 0) break;

        if (b%a == 0) puts("factor");// 약수 관계 확인
        else if (a % b == 0) puts("multiple"); // 배수 관계 확인
        else puts("neither");
    }

    return 0;
}

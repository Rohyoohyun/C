#include <stdio.h>

int main() {
    int m, d;
    scanf("%d %d", &m, &d);

    // 각 달의 일 수
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    char *wd[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

    int total = 0;
    for (int i = 0; i < m - 1; i++) {
        // 1월부터 (m-1)월까지의 일수를 더함
        total += days[i];
    }

    total += d; // 현재 달의 일수 추가

    // 요일 계산 (1월 1일이 MON(1)이므로, total % 7 사용)
    printf("%s", wd[total%7]);

    return 0;
}

#include <stdio.h>

int main() {
    int A, B, C, D;
    scanf("%d %d %d", &A, &B, &C);
    scanf("%d", &D);

    // 현재 시각을 초 단위로 변환
    int total = A * 3600 + B * 60 + C;

    // 요리 시간 추가
    total += D;

    // 24시간 기준으로 나머지 계산
    total %= 86400;  // 24 * 60 * 60

    // 다시 시, 분, 초로 변환
    int hour = total / 3600;
    int minute = (total % 3600) / 60;
    int second = total % 60;
    printf("%d %d %d", hour, minute, second);

    return 0;
}

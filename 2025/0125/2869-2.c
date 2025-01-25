#include <stdio.h>

int main() {
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);

    // 계산: (V - A) / (A - B)를 올림 처리 후 +1 (수동 계산)
    int remain = v-a;
    int daily = a-b;
    int days = remain / daily;
    if (remain % daily) days++; // 나머지가 있으면 하루 추가
    days++; // 마지막 날 추가
    
    printf("%d", days);

    return 0;
}
#include <stdio.h>

int main() {
    int A, B, C;
    scanf("%d %d", &A, &B);
    scanf("%d", &C);
    
    B += C;  // 현재 분에 요리 시간을 더함
    A += B / 60;  // 총 분을 60으로 나눈 몫을 시에 추가
    B %= 60;  // 분을 60으로 나눈 나머지
    A %= 24;  // 시를 24로 나눈 나머지 (24시간 형식 유지)
    
    printf("%d %d", A, B);
    return 0;
}

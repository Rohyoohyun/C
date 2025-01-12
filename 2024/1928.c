#include <stdio.h>

#define MAX_SIZE 1000000 // 메모이제이션을 위한 배열 크기

int memo[MAX_SIZE]; // 메모이제이션 배열
int func(int n) {
    if (n < MAX_SIZE && memo[n] != 0) return memo[n]; // 이미 계산된 값이 있으면 반환
    if (n == 1) return 1;

    printf("%d\n", n); // 현재 n 출력
    int result;
    if (n % 2 != 0) result = func(n * 3 + 1); // n이 홀수일 때
    else result = func(n / 2); // n이 짝수일 때

    if (n < MAX_SIZE) memo[n] = result; // 계산된 값을 메모이제이션 배열에 저장
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", func(n));
    return 0;
}
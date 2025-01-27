#include <stdio.h>

int func(int n) {
    if (n < 2) return 0; // 2보다 작은 경우 소수가 아님
    for (int i=2; i*i<=n; i++) // 숫자의 제곱근까지만 확인
        if (n%i == 0) return 0; // 나누어 떨어지면 소수가 아님
    return 1; // 소수임
}

int main() {
    int n, cnt = 0;
    scanf("%d", &n);

    int arr[101]; // 자연수 저장
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    for (int i=0; i<n; i++) // 배열의 각 원소가 소수인지 확인
        if (func(arr[i])) cnt++; // 소수이면 카운트 증가
    printf("%d", cnt);

    return 0;
}
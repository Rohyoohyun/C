#include <stdio.h>

int func(int n) {
    if (n < 2) return 0; // 소수가 아님
    for (int i=2; i*i<=n; i++)
        if (n%i == 0) return 0; // 나누어 떨어지면 소수가 아님
    return 1; // 소수임
}

int main() {
    int n, cnt = 0;
    scanf("%d", &n);

    int arr[101];
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    for (int i=0; i<n; i++)
        if (func(arr[i])) cnt++;
    printf("%d", cnt);

    return 0;
}

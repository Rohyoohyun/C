#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int p = 2; 
    for (int i=0; i<n; i++) 
        p = p*2-1; // 한 변의 점 개수는 이전 점 개수 * 2 - 1
    printf("%d", p*p); // 전체 점의 개수는 한 변의 점 개수의 제곱

    return 0;
}
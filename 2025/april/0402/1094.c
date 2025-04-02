#include <stdio.h>

int main() {
    int X;
    scanf("%d", &X);

    int count = 0;
    while (X > 0) {
        if (X & 1) count++;  // X의 마지막 비트가 1이면 count 증가
        X >>= 1;  // X를 오른쪽으로 한 칸 이동 (2로 나눔)
    }

    printf("%d", count);
    return 0;
}

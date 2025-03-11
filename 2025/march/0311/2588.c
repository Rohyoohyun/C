#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int B1 = B%10;         // B의 1의 자리
    int B2 = (B/10) % 10;  // B의 10의 자리
    int B3 = B/100;        // B의 100의 자리

    int res1 = A * B1;    // (3)
    int res2 = A * B2;    // (4)
    int res3 = A * B3;    // (5)
    int res4 = A * B;     // (6)

    printf("%d\n%d\n%d\n%d\n", res1, res2, res3, res4);

    return 0;
}

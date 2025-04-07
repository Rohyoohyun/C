#include <stdio.h>

int main() {
    int a, b, c;
    int reward;

    scanf("%d %d %d", &a, &b, &c);

    if (a == b && b == c) reward = 10000 + a * 1000; // 세 눈이 모두 같은 경우
    else if (a == b || a == c) reward = 1000 + a * 100; // 두 눈이 같은 경우 (a와 b 또는 a와 c)
    else if (b == c) reward = 1000 + b * 100; // 두 눈이 같은 경우 (b와 c)
    else { // 모두 다른 눈인 경우
        int max = a;
        if (b > max) max = b;
        if (c > max) max = c;
        reward = max * 100;
    }

    printf("%d", reward);
    return 0;
}

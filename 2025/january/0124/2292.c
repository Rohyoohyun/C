#include <stdio.h>

int main() {
    long long int n;
    scanf("%lld", &n);

    if (n == 1){printf("1");return 0;}// 방 1은 바로 중심이므로 1 출력
    
    long long layer = 1; // 현재 벌집의 층수 (중앙은 1층)
    long long range = 1; // 현재 범위의 마지막 숫자 (1층은 1)

    while (range < n) {
        range += 6 * layer; // 각 층의 숫자는 6의 배수로 증가
        layer++;
    }
    printf("%lld", layer); // N이 위치한 층 출력

    return 0;
}

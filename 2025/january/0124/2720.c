#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int coins[4] = {25, 10, 5, 1}; // 동전단위

    for (int i=0; i<n; i++) {
        int coin;
        scanf("%d", &coin);
        
        int res[4] = {0};
        for (int j=0; j<4; j++) { // 최소 동전 개수를 계산
            res[j] = coin/coins[j]; // 현재 동전 단위로 몇 개를 사용할 수 있는지 계산
            coin %= coins[j]; // 남은 금액 계산
        }
        
        printf("%d %d %d %d\n", res[0], res[1], res[2], res[3]);
    }

    return 0;
}


#include <stdio.h>

int res(int k, int n) {
    int apt[15][15] = {0};
    
    // 0층 초기화 (각 호에는 호수만큼 사람이 산다)
    for (int i = 1; i <= 14; i++) {
        apt[0][i] = i;
    }
    
    // 아파트 채우기
    for (int f = 1; f <= 14; f++) {
        for (int r = 1; r <= 14; r++) {
            for (int pr = 1; pr <= r; pr++) {
                apt[f][r] += apt[f - 1][pr];
            }
        }
    }
    
    return apt[k][n];
}

int main() {
    int t, k, n;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d", &k, &n);
        printf("%d\n", res(k, n));
    }
    
    return 0;
}

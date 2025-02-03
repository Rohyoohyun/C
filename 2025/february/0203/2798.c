#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int cards[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &cards[i]);
    }
    
    int res = 0;
    
    // 브루트포스 탐색: 세 개의 카드 선택
    for (int i=0; i<n-2; i++) {
        for (int j=i+1; j<n-1; j++) {
            for (int k=j+1; k<n; k++) {
                int sum = cards[i] + cards[j] + cards[k];
                
                // m을 넘지 않으면서 최대한 가까운 합을 찾음
                if (sum <= m && sum > res) res = sum;
            }
        }
    }
    printf("%d", res);
    
    return 0;
}

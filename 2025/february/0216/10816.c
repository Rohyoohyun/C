#include <stdio.h>
#include <stdlib.h>
#define MAX 10000000
#define RANGE 20000001

int cardCount[RANGE];
int main() {
    int n, m, num;
    scanf("%d", &n);
    
    // 숫자 카드 입력 및 개수 저장
    for (int i=0; i<n; i++) {
        scanf("%d", &num);
        cardCount[num+MAX]++; // 음수를 0 기반으로 변환
    }
    
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        scanf("%d", &num);
        printf("%d ", cardCount[num+MAX]);
    }
    
    return 0;
}

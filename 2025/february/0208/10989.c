#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 10000
#define MAX_N 10000000

int count[MAX_NUM + 1]; // 숫자 개수를 저장하는 배열
int main() {
    int N, num;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        count[num]++; // 해당 숫자의 개수 증가
    }
    
    // 정렬된 출력 (계수 정렬 결과)
    for (int i = 1; i <= MAX_NUM; i++) {
        while (count[i]--) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}

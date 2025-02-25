#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int queue[1000];  // 사람들을 저장할 배열
    for (int i=0; i<n; i++) 
        queue[i] = i + 1;

    int idx = 0, cnt = n;  // 현재 인덱스와 남은 사람 수
    printf("<");

    while (cnt > 0) {
        // k번째 사람을 찾음
        idx = (idx + k-1) % cnt;
        
        // 출력
        printf("%d", queue[idx]);
        if (cnt > 1) printf(", ");

        // 배열에서 제거 (왼쪽으로 이동)
        for (int i=idx; i<cnt-1; i++) {
            queue[i] = queue[i+1];
        }
        cnt--;  // 사람 수 감소
    }

    printf(">");
    return 0;
}

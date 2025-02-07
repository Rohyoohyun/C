#include <stdio.h>
#include <stdlib.h>

// 내림차순 정렬을 위한 비교 함수
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int scores[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &scores[i]);
    }
    
    // 점수 내림차순 정렬
    qsort(scores, n, sizeof(int), compare);
    printf("%d", scores[k - 1]);
    
    return 0;
}

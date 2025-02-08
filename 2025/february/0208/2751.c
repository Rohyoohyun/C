#include <stdio.h>
#include <stdlib.h>

// 비교 함수 (qsort에서 사용)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int *arr = (int*)malloc(N * sizeof(int)); // 동적 메모리 할당
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    // 정렬 수행
    qsort(arr, N, sizeof(int), compare);
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
    
    free(arr);
    return 0;
}

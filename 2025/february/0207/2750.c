#include <stdio.h>
#include <stdlib.h>

// 비교 함수 (qsort에서 사용)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // 정렬 수행
    qsort(arr, n, sizeof(int), compare);
    
    for (int i=0; i<n; i++)
        printf("%d\n", arr[i]);
    
    return 0;
}

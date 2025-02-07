#include <stdio.h>
#include <stdlib.h>

// 비교 함수 (qsort에서 사용)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[5];
    int sum = 0;
    
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    // 평균 계산
    int avg = sum / 5;
    
    // 정렬 수행
    qsort(arr, 5, sizeof(int), compare);
    
    int med = arr[2]; // 중앙값 계산
    printf("%d\n", avg);
    printf("%d", med);
    
    return 0;
}

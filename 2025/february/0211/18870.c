#include <stdio.h>
#include <stdlib.h>

// 비교 함수 (오름차순 정렬)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int)); // 원본 배열
    int *sorted = (int*)malloc(n * sizeof(int)); // 정렬할 배열
    
    // 입력 받기 및 배열 복사
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]); // 배열에 원소 입력 받기
        sorted[i] = arr[i];   // 정렬할 배열에 원소 복사
    }
    
    // 좌표 정렬
    qsort(sorted, n, sizeof(int), compare);
    
    // 중복 제거 후 압축된 좌표 찾기
    int *unique = (int*)malloc(n * sizeof(int));
    int cnt = 0;
    unique[cnt++] = sorted[0];
    for (int i=1; i<n; i++) {
        if (sorted[i] != sorted[i-1]) { 
            unique[cnt++] = sorted[i]; // 중복되지 않은 원소만 저장
        }
    }
    
    // 좌표 압축 결과 출력
    for (int i=0; i<n; i++) {
        int left = 0, right = cnt-1, mid, result = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (unique[mid] == arr[i]) {
                result = mid; // 압축된 좌표 찾기
                break;
            } else if (unique[mid] < arr[i]) left = mid + 1; // 오른쪽 탐색
            else right = mid-1; // 왼쪽 탐색
        }
        printf("%d ", result); // 압축된 좌표 출력
    }
    
    // 메모리 해제
    free(arr);
    free(sorted);
    free(unique);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 200000

int a[MAX_N], b[MAX_N];

// 정렬을 위한 비교 함수
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// 이진 탐색 함수
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return 1; // 찾음
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return 0; // 없음
}

int main() {
    int n, m, count = 0;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    
    // 정렬
    qsort(a, n, sizeof(int), compare);
    qsort(b, m, sizeof(int), compare);
    
    // 대칭 차집합 개수 계산
    for (int i = 0; i < n; i++) 
        if (!binarySearch(b, m, a[i])) count++;
    for (int i = 0; i < m; i++) 
        if (!binarySearch(a, n, b[i])) count++;
    
    printf("%d", count);
    return 0;
}

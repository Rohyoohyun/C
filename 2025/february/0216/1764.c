#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500000

char unheard[MAX][21]; // 듣도 못한 사람 명단
char unseen[MAX][21]; // 보도 못한 사람 명단
char result[MAX][21]; // 듣보잡 명단

// 문자열 정렬을 위한 비교 함수
int compare(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

// 이진 탐색 함수
int binarySearch(char arr[][21], int size, char *target) {
    int left = 0, right = size-1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid], target);
        if (cmp == 0) return 1; // 찾음
        else if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return 0; // 없음
}

int main() {
    int n, m, count = 0;
    scanf("%d %d", &n, &m);
    
    // 듣도 못한 사람 입력
    for (int i=0; i<n; i++) {
        scanf("%s", unheard[i]);
    }
    
    // 듣도 못한 사람 명단 정렬
    qsort(unheard, n, 21, compare);
    
    // 보도 못한 사람 입력 및 듣보잡 판별
    for (int i=0; i<m; i++) {
        scanf("%s", unseen[i]);
        if (binarySearch(unheard, n, unseen[i])) strcpy(result[count++], unseen[i]);
    }
    
    // 듣보잡 명단 정렬
    qsort(result, count, 21, compare);
    printf("%d\n", count);
    for (int i=0; i<count; i++) {
        puts(result[i]);
    }
    
    return 0;
}

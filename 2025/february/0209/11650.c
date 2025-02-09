#include <stdio.h>
#include <stdlib.h>

// 비교 함수 (x 오름차순, x가 같으면 y 오름차순)
int compare(const void *a, const void *b) {
    int *p1 = (int*)a;
    int *p2 = (int*)b;
    
    if (p1[0] != p2[0]) return p1[0] - p2[0];
    return p1[1] - p2[1];
}

int main() {
    int n;
    scanf("%d", &n);
    
    int (*points)[2] = (int(*)[2])malloc(n * sizeof(int) * 2); // 동적 메모리 할당
    if (points == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }
    
    // 정렬 수행
    qsort(points, n, sizeof(points[0]), compare);
    
    // 결과 출력
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", points[i][0], points[i][1]);
    }
    
    free(points); // 메모리 해제
    return 0;
}

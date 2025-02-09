#include <stdio.h>
#include <stdlib.h>

// 비교 함수 (y 오름차순, y가 같으면 x 오름차순)
int compare(const void *a, const void *b) {
    int *p1 = (int*)a;
    int *p2 = (int*)b;
    
    if (p1[1] != p2[1]) return p1[1] - p2[1];
    return p1[0] - p2[0];
}

int main() {
    int n;
    scanf("%d", &n);
    
    int (*points)[2] = (int(*)[2])malloc(n * sizeof(int) * 2); // 동적 메모리 할당
    for (int i=0; i<n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }
    qsort(points, n, sizeof(points[0]), compare);
    for (int i=0; i<n; i++) {
        printf("%d %d\n", points[i][0], points[i][1]);
    }
    
    free(points); // 메모리 해제
    return 0;
}
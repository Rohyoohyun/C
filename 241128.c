// 3004 : 데이터 재정렬

// 방법1
#include <stdio.h>
#include <stdlib.h>
#define MAX 500001

// 비교 함수 (qsort에 사용)
int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int a[MAX], sorted[MAX], rank[MAX];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        sorted[i] = a[i]; // 정렬용 복사본
    }

    qsort(sorted, N, sizeof(int), compare);
    for (int i = 0; i < N; i++) {
        int low = 0, high = N-1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (sorted[mid] < a[i]) low = mid + 1;
            else high = mid;
        }
        rank[i] = low;
    }

    for (int i = 0; i < N; i++)
        printf("%d ", rank[i]);

    return 0;
}

// 방법2
#include <stdio.h>
#include <stdlib.h>
#define MAX 500001

// 비교 함수 (qsort에 사용)
int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int a[MAX], sorted[MAX], rank[MAX];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        sorted[i] = a[i]; // 복사본을 만들어서 정렬에 사용
    }

    // 정렬
    qsort(sorted, N, sizeof(int), compare);

    int cur = 0;
    rank[0] = cur;
    for (int i = 1; i < N; i++) {
        if (sorted[i] != sorted[i-1]) cur++;
        rank[i] = cur;
    }

    for (int i = 0; i < N; i++) {
        // 각 a[i]의 순위를 찾아 출력
        for (int j = 0; j < N; j++) {
            if (a[i] == sorted[j]) {
                printf("%d ", rank[j]);
                break;
            }
        }
    }

    return 0;
}

// 방법3
#include <stdio.h>
#define MAX 500000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX] = {0};
    int idx[MAX] = {0};
    for(int i=0; i<n; i++){
        scanf("%d", arr+i);
        idx[arr[i]] = 1; // 위치 표시
    }

    int cnt=1;
    for(int i=0; i<MAX; i++)
        if(idx[i]) idx[i] = cnt++;

    for(int i=0; i<n; i++)
        printf("%d ", idx[arr[i]]-1);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;  // 내림차순
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp);

    int res = 0;
    for (int i = 0; i < n; i++) {
        int tmp = arr[i] * (i + 1);
        if (tmp > res) res = tmp;
    }

    printf("%d", res);
    return 0;
}

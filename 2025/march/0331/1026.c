#include <stdio.h>
#include <stdlib.h>

int compare_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    
    qsort(a, n, sizeof(int), compare_asc);
    qsort(b, n, sizeof(int), compare_desc);
    
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i] * b[i];
    }
    printf("%d", s);
    return 0;
}

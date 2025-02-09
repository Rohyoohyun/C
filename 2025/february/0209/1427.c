#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 내림차순 정렬을 위한 비교 함수
int compare(const void *a, const void *b) {
    return (*(char*)b - *(char*)a);
}

int main() {
    char num[11];
    scanf("%s", num);
    
    int len = strlen(num);
    qsort(num, len, sizeof(char), compare); // 내림차순 정렬
    printf("%s", num);
    
    return 0;
}

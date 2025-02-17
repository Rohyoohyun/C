#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000  // 최대 문자열 길이

char s[MAX+1];  // 입력받을 문자열
int suffix[MAX];  // 접미사 배열을 저장할 배열
int lcp[MAX];  // LCP 배열을 저장할 배열

// 접미사 배열을 위한 비교 함수
int compare_suffix(const void *a, const void *b) {
    return strcmp(s + *(int *)a, s + *(int *)b);
}

// LCP(Longest Common Prefix) 배열을 계산하는 함수
void compute_lcp(int len) {
    for (int i = 1; i < len; i++) { // LCP는 첫 번째 접미사와 비교할 필요가 없음 (i=1부터 시작)
        int l = 0;
        // 현재 접미사와 이전 접미사의 공통 접두사를 비교하여 LCP 길이를 구함
        while (s[suffix[i] + l] == s[suffix[i - 1] + l]) { 
            l++;
        }
        lcp[i] = l;  // LCP 배열에 저장
    }
}

int main() {
    scanf("%s", s);
    int len = strlen(s);

    for (int i=0; i<len; i++) {
        suffix[i] = i;  // 접미사의 시작 인덱스를 저장
    }

    // 접미사 배열 정렬
    qsort(suffix, len, sizeof(int), compare_suffix);

    // LCP 배열 계산
    compute_lcp(len);

    // 서로 다른 부분 문자열 개수 계산
    int unique = (len * (len+1)) / 2;  // 모든 부분 문자열의 개수 (n(n+1)/2)
    for (int i=1; i<len; i++) {
        unique -= lcp[i];  // LCP 값을 빼서 중복된 부분 제거
    }
    printf("%d", unique);
    
    return 0;
}

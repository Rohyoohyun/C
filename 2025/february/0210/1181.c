// 시간 초과 뜸...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char **words = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        words[i] = (char*)malloc(51 * sizeof(char)); // 최대 길이 50 + 널문자
        scanf("%s", words[i]);
    }
    
    // 정렬 수행 (길이 오름차순, 길이가 같으면 사전 순 정렬)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int len1 = strlen(words[i]);
            int len2 = strlen(words[j]);
            if (len1 > len2 || (len1 == len2 && strcmp(words[i], words[j]) > 0)) {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
    
    // 중복 제거 및 출력
    printf("%s\n", words[0]);
    for (int i = 1; i < n; i++) {
        if (strcmp(words[i], words[i - 1]) != 0) {
            printf("%s\n", words[i]);
        }
    }
    
    // 메모리 해제
    for (int i = 0; i < n; i++) {
        free(words[i]);
    }
    free(words);
    
    return 0;
}
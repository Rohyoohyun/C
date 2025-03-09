#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

int L, C;
char chars[MAX];  // 입력받은 문자 저장
char password[MAX];  // 현재 선택된 문자 저장

// 모음 체크 함수
int is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// 백트래킹을 이용한 조합 생성
void generate_password(int depth, int start, int vowels, int consonants) {
    if (depth == L) {  // L개의 문자 선택 완료
        if (vowels >= 1 && consonants >= 2) {  // 조건 만족 시 출력
            password[L] = '\0';  // 문자열 종료
            printf("%s\n", password);
        }
        return;
    }

    for (int i = start; i < C; i++) {
        password[depth] = chars[i];

        if (is_vowel(chars[i])) {
            generate_password(depth + 1, i + 1, vowels + 1, consonants);
        } else {
            generate_password(depth + 1, i + 1, vowels, consonants + 1);
        }
    }
}

// 정렬 함수 (qsort 사용)
int compare(const void *a, const void *b) { return (*(char*)a - *(char*)b);}

int main() {
    // 입력 받기
    scanf("%d %d", &L, &C);
    for (int i = 0; i < C; i++) {
        scanf(" %c", &chars[i]);
    }

    // 문자들을 사전순으로 정렬
    qsort(chars, C, sizeof(char), compare);

    // 백트래킹 시작
    generate_password(0, 0, 0, 0);

    return 0;
}

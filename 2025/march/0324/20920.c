#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LEN 11 
#define MAX_WORDS 100000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

// 비교 함수: 조건에 맞게 정렬
int compare(const void *a, const void *b) {
    Word *wordA = (Word *)a;
    Word *wordB = (Word *)b;

    // 1. 자주 등장하는 단어가 앞에 오도록 정렬 (내림차순)
    if (wordA->count != wordB->count) 
        return wordB->count - wordA->count;

    // 2. 단어 길이가 긴 순서로 정렬 (내림차순)
    int lenA = strlen(wordA->word);
    int lenB = strlen(wordB->word);
    if (lenA != lenB)
        return lenB - lenA;

    // 3. 알파벳 순 정렬 (오름차순)
    return strcmp(wordA->word, wordB->word);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Word words[MAX_WORDS];
    int word_count = 0;
    
    char temp[MAX_WORD_LEN];
    
    // 해시 테이블처럼 사용하기 위한 배열
    Word *hash_table[26][MAX_WORDS] = {NULL};
    int hash_counts[26] = {0};

    for (int i = 0; i < N; i++) {
        scanf("%s", temp);
        int len = strlen(temp);

        if (len < M) continue;  // M보다 짧으면 무시

        int index = temp[0] - 'a'; // 첫 글자로 해싱

        // 중복 검사
        int found = 0;
        for (int j = 0; j < hash_counts[index]; j++) {
            if (strcmp(hash_table[index][j]->word, temp) == 0) {
                hash_table[index][j]->count++;
                found = 1;
                break;
            }
        }

        // 새로운 단어라면 추가
        if (!found) {
            strcpy(words[word_count].word, temp);
            words[word_count].count = 1;
            hash_table[index][hash_counts[index]++] = &words[word_count];
            word_count++;
        }
    }

    qsort(words, word_count, sizeof(Word), compare);
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i].word);
    }

    return 0;
}

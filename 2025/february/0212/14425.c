// 굉장히 어려워따ㅏㅏㅏㅏㅏ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10007  // 해시 테이블 크기 (소수 사용)

// 해시 테이블의 노드 구조체 정의 (체이닝 방식)
typedef struct Node {
    char str[501];        // 문자열 저장 (최대 500자 + NULL)
    struct Node* next;    // 다음 노드 포인터 (충돌 처리용)
} Node;

Node* hashTable[TABLE_SIZE]; // 해시 테이블 선언

// 해시 함수 (djb2 알고리즘)
unsigned int hash(const char* str) {
    unsigned long hash = 5381; 
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % TABLE_SIZE;
}

// 해시 테이블에 문자열 삽입
void insert(const char* str) {
    unsigned int idx = hash(str); // 해시 값 계산
    Node* newNode = (Node*)malloc(sizeof(Node)); // 새 노드 할당
    strcpy(newNode->str, str);
    newNode->next = hashTable[idx]; // 체이닝 방식으로 연결
    hashTable[idx] = newNode;
}

// 해시 테이블에서 문자열 찾기
int find(const char* str) {
    unsigned int idx = hash(str); // 해시 값 계산
    Node* curr = hashTable[idx]; 
    while (curr) { // 연결 리스트 탐색
        if (strcmp(curr->str, str) == 0) return 1; // 찾으면 1 반환
        curr = curr->next;
    }
    return 0; // 찾지 못하면 0 반환
}

// 메모리 해제 함수
void freeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* curr = hashTable[i];
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char str[501];

    // N개의 문자열 입력받아 해시 테이블에 저장
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(str);
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        scanf("%s", str);
        if (find(str)) count++; // 존재하면 카운트 증가
    }

    printf("%d", count);
    freeHashTable();

    return 0;
}

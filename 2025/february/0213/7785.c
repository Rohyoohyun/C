// 시간 초과

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define MAX 1000000     // 최대 기록 개수 (1,000,000)
#define MAX_NAME_LEN 6    // 최대 이름 길이 (5글자 + NULL 문자 포함)

// 문자열을 기준으로 내림차순 정렬을 수행하는 비교 함수
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)b, *(const char **)a);  // 사전순 내림차순 정렬
}

int main() {
    int n;  
    scanf("%d", &n);  // 기록 개수 입력 받기

    hcreate(MAX);   // 해시 테이블 생성 (최대 n개의 데이터 저장 가능)
    
    ENTRY e, *ep;     // 해시 테이블을 위한 ENTRY 구조체
    char name[MAX_NAME_LEN], action[10];  // 이름과 행동(enter/leave)을 저장할 문자열
    char *names[MAX];  // 현재 사무실에 있는 사람들의 이름을 저장할 배열
    int count = 0;       // 사무실에 남아있는 사람 수

    for (int i = 0; i < n; i++) {
        scanf("%s %s", name, action);  // 이름과 출입 여부 입력받기
        e.key = strdup(name);          // 문자열을 동적으로 복사하여 e.key에 저장
        e.data = (void *)1;            // 해시 테이블에 저장할 임의의 데이터 (필요하지 않음)

        if (strcmp(action, "enter") == 0) {  // "enter"인 경우
            ep = hsearch(e, ENTER);   // 해시 테이블에 삽입
            if (ep && ep->key == e.key) {  // 새로운 값이 삽입된 경우
                names[count++] = ep->key;  // names 배열에 추가
            } else {
                free(e.key);  // 이미 존재하는 경우 메모리 해제
            }
        } else {  // "leave"인 경우
            ep = hsearch(e, FIND);  // 해시 테이블에서 찾기
            if (ep) {  // 존재하면 삭제
                for (int j = 0; j < count; j++) {  // names 배열에서 해당 이름 삭제
                    if (strcmp(names[j], ep->key) == 0) {
                        free(ep->key);  // 메모리 해제
                        names[j] = names[--count];  // 마지막 값을 현재 위치로 이동 후 count 감소
                        break;
                    }
                }
            }
        }
    }

    // 이름을 내림차순 정렬 (사전순 역순)
    qsort(names, count, sizeof(char *), compare);

    // 사무실에 남아 있는 사람 출력
    for (int i = 0; i < count; i++) {
        puts(names[i]);
    }

    hdestroy();  // 해시 테이블 제거 (메모리 정리)
    return 0;
}

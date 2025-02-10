#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 회원 정보를 저장하는 구조체
typedef struct {
    int age;           
    char name[101];   
    int index;        // 입력 순서를 유지하기 위한 인덱스
} Member;

// 정렬을 위한 비교 함수
// 1. 나이를 기준으로 오름차순 정렬
// 2. 나이가 같으면 입력된 순서(index) 기준으로 정렬
int compare(const void *a, const void *b) {
    Member *m1 = (Member *)a;
    Member *m2 = (Member *)b;
    
    if (m1->age != m2->age) return m1->age - m2->age;
    return m1->index - m2->index;
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 동적 메모리 할당 (회원 정보를 저장할 배열)
    Member *members = (Member *)malloc(n * sizeof(Member));
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &members[i].age, members[i].name);
        members[i].index = i; // 입력 순서 저장
    }
    
    // qsort를 이용한 정렬 수행
    qsort(members, n, sizeof(Member), compare);
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", members[i].age, members[i].name);
    }
    
    // 할당된 메모리 해제
    free(members);
    return 0;
}

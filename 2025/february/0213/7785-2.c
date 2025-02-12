#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)   // scanf 사용 시 발생하는 경고 무시
#define MAX 1000001

// 구조체 정의: 이름(name)과 출입 여부(inandout) 저장
typedef struct {
    char name[6];      // 최대 5글자의 이름 저장 (null 문자 포함하여 6칸 할당)
    char inandout[6];  // "enter" 또는 "leave"를 저장 (최대 5글자)
} record;

record arr[MAX];
int compare(const void* a, const void* b) {
    // 비교 함수: 이름을 기준으로 내림차순 정렬 (qsort에 사용)
    record num1 = *(record*)a;
    record num2 = *(record*)b;

    // strcmp()를 이용하여 문자열 비교 후 내림차순 정렬
    if (strcmp(num1.name, num2.name) < 0) return 1;  // num1이 num2보다 사전순으로 앞이면 큰 값 반환 (내림차순)
    else if (strcmp(num1.name, num2.name) > 0) return -1; // num1이 num2보다 뒤면 작은 값 반환
    else return 0;  // 같으면 0 반환
}

int main() {
    int n;
    scanf("%d", &n);

    // n개의 이름과 출입 여부 입력 받기
    for (int i = 0; i < n; i++) {
        scanf("%s %s", arr[i].name, arr[i].inandout);
    }
    
    // 이름 기준으로 내림차순 정렬
    qsort(arr, n, sizeof(record), compare);

    // 정렬된 데이터를 이용하여 현재 사무실에 있는 사람 출력
    for (int i = 0; i < n; i++) {
        // 같은 이름이 연속으로 등장하면 한 번 건너뜀 (출입 기록이 enter -> leave일 경우)
        if (!strcmp(arr[i].name, arr[i + 1].name)) i++; // 중복된 경우 스킵
        else puts(arr[i].name);  // 사무실에 남아 있는 사람 출력
    }

    return 0;
}

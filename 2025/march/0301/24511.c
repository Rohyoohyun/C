#include <stdio.h>
#define MAX_N 100000  
#define QUEUE 0

int main() {
    int N; // 자료구조 개수
    scanf("%d", &N);

    int type[MAX_N];  // 자료구조 타입 (0: 큐, 1: 스택)
    int data[MAX_N];  // 각 자료구조에 저장된 원소

    // 자료구조 타입 및 초기 원소 입력
    for (int i = 0; i < N; i++) scanf("%d", &type[i]);
    for (int i = 0; i < N; i++) scanf("%d", &data[i]);

    int M; // 삽입할 원소 개수
    scanf("%d", &M);

    // 뒤에서부터 큐(0)인 원소를 출력 (최대 M개)
    for (int i = N - 1; M > 0 && i >= 0; i--) {
        if (type[i] == QUEUE) {
            printf("%d ", data[i]);
            M--;
        }
    }

    // 추가 입력을 받아 그대로 출력
    for (; M > 0; M--) {
        int x;
        scanf("%d", &x);
        printf("%d ", x);
    }

    return 0;
}

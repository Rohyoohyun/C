// 실패... 

#include <stdio.h>
#include <stdlib.h>

int n, m, *a, *b, *c;
int *queue, front = 0, rear = 0; // 동적 할당 큐
int *stack, top = -1;            // 동적 할당 스택

// 큐
void push_q(int x) { queue[rear++] = x; } // 삽입
int pop_q() { return (front < rear) ? queue[front++] : -1; } // 삭제

// 스택
void push_s(int x) { stack[++top] = x; } // 삽입
int pop_s() { return (top >= 0) ? stack[top--] : -1; } // 삭제(언더플로 방지)

int main() {
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    
    for (int i=0; i<n; i++) 
        scanf("%d", &a[i]);
    for (int i=0; i<n; i++) 
        scanf("%d", &b[i]);

    scanf("%d", &m);
    c = (int *)malloc(m * sizeof(int));

    for (int i=0; i<m; i++) 
        scanf("%d", &c[i]);
    
    queue = (int *)malloc((n + m) * sizeof(int));
    stack = (int *)malloc((n + m) * sizeof(int));

    // 초기 데이터 삽입
    for (int i = 0; i < n; i++) {
        if (a[i]) push_s(b[i]); // 스택
        else push_q(b[i]);      // 큐
    }

    // c 배열 처리
    for (int i = 0; i < m; i++) {
        int cur = c[i];
        for (int j = 0; j < n; j++) {
            if (a[j]) { // 스택
                push_s(cur);
                cur = pop_s();
            } else { // 큐
                push_q(cur);
                cur = pop_q();
            }
        }
        printf("%d ", cur);
    }

    // 메모리 해제
    free(a);
    free(b);
    free(c);
    free(queue);
    free(stack);

    return 0;
}

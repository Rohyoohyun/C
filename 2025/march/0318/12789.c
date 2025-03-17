// 와이파이 이슈로 백준 채점 결과를 보지못함..

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) { s->top = -1;} // 스택 초기화
int is_empty(Stack *s) {return s->top == -1;} // 스택이 비어있는지 확인
void push(Stack *s, int value) {s->data[++(s->top)] = value;} // 스택에 데이터 추가
int pop(Stack *s) {return s->data[(s->top)--];} // 스택에서 데이터 제거
int peek(Stack *s) { return s->data[s->top];} // 스택의 최상단 데이터 확인

int main() {
    int n;
    scanf("%d", &n);
    
    int queue[MAX];
    for (int i=0; i<n; i++) {
        scanf("%d", &queue[i]); // 대기열 입력
    }
    
    Stack s;
    init(&s); // 스택 초기화
    int current = 1; // 현재 간식을 받을 번호
    for (int i=0; i<n; i++) {
        push(&s, queue[i]); // 대기열의 학생을 스택에 추가
        
        // 스택의 최상단이 현재 받을 번호이면 꺼내기
        while (!is_empty(&s) && peek(&s) == current) {
            pop(&s);
            current++;
        }
    }
    
    // 스택이 비어있으면 성공, 아니면 실패
    if (is_empty(&s)) printf("Nice");
    else printf("Sad");
    
    return 0;
}

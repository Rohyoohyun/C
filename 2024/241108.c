// 스택이용 후위수식표현
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

typedef struct {
    char stack[MAX];
    int top;
} Stack;
Stack s;

// 스택 초기화 함수
void initStack(Stack *s){s->top = -1;} // 스택 초기화
int isEmpty(Stack *s){return s->top == -1;} // top이 -1이면 스택이 비어있다는 의미
int isFull(Stack *s){return s->top == MAX - 1;} // 스택이 다찼는지 확인

void push(Stack *s, int value) { 
    if (isFull(s)) return;  // 스택이 가득 차면 값을 푸시하지 않음
    s->stack[++(s->top)] = value;  // 스택의 top을 하나 증가시킨 후 해당 위치에 값 저장
}
int pop(Stack *s) { 
    if (isEmpty(s)) return -1;  // 스택이 비어있으면 -1을 반환
    return s->stack[(s->top)--];  // top 위치의 값을 반환하고 top을 하나 감소시킴
}

int main() {
    char expr[100];
    gets(expr);

    initStack(&s);  // 스택 초기화
    for (int i = 0; i < strlen(expr); i++) {  // 수식의 각 문자를 순차적으로 처리
        if (isdigit(expr[i]))  // 문자가 숫자라면
            push(&s, expr[i] - '0');  // 해당 문자를 정수로 변환하여 스택에 푸시
        else if (expr[i] == ' '){  // 공백 문자는 넘어감
            i++; 
            continue;
        } else {  // 연산자 (+, -, *, /)인 경우
            int o2 = pop(&s);
            int o1 = pop(&s);
            int res;

            switch (expr[i]) {
                case '+': res = o1 + o2; break;
                case '-': res = o1 - o2; break;
                case '*': res = o1 * o2; break;
                case '/': res = o1 / o2; break;
                default:
                    exit(1);  // 예기치 않은 연산자가 나오면 프로그램 종료
            }
            push(&s, res);  // 연산 결과를 스택에 푸시
        }
        i++;  // 다음 문자로 이동
    }
    printf("%d", pop(&s));

    return 0;
}


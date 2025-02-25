#include <stdio.h>

int queue[1000002];
int front = 0;
int rear = -1;

void push(int x) { queue[++rear] = x; }
int pop() {
    if (rear - front + 1 == 0) return -1;
    return queue[front++];
}

int size() { return (rear - front + 1); }
int empty() { return size() == 0 ? 1 : 0; }

int main() {
    int n;
    scanf("%d", &n);

    // 1부터 N까지 큐에 추가
    for (int i=1; i<=n; i++) {
        push(i);
    }

    // 카드 한 장 남을 때까지 반복
    while (size() > 1) {
        pop();          // 맨 앞의 카드 버리기
        push(pop());    // 맨 앞의 카드를 뒤로 옮기기
    }

    // 마지막으로 남은 카드 출력
    printf("%d", pop());

    return 0;
}

#include <stdio.h>
#define MAX 1000000  // 문제에서 주어진 최대 명령 개수
int deque[MAX * 2];  // 넉넉한 크기의 덱 배열
int front = MAX, rear = MAX;  // 중앙에서 시작 (양쪽 확장 가능)

void push_front(int x) { deque[--front] = x; }
void push_back(int x) { deque[rear++] = x; }
int pop_front() { return (front == rear) ? -1 : deque[front++]; }
int pop_back() { return (front == rear) ? -1 : deque[--rear]; }
int size() { return rear - front; }
int empty() { return (front == rear) ? 1 : 0; }
int front_value() { return (front == rear) ? -1 : deque[front]; }
int back_value() { return (front == rear) ? -1 : deque[rear - 1]; }

int main() {
    int n, cmd, x;
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &cmd);
        if (cmd == 1) { scanf("%d", &x); push_front(x); }
        else if (cmd == 2) { scanf("%d", &x); push_back(x); }
        else if (cmd == 3) printf("%d\n", pop_front());
        else if (cmd == 4) printf("%d\n", pop_back());
        else if (cmd == 5) printf("%d\n", size());
        else if (cmd == 6) printf("%d\n", empty());
        else if (cmd == 7) printf("%d\n", front_value());
        else if (cmd == 8) printf("%d\n", back_value());
    }

    return 0;
}

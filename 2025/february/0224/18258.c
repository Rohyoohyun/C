#include <stdio.h>
#include <string.h>
#define MAX_SIZE 2000000

int queue[MAX_SIZE];  // 큐 배열
int front = 0, rear = 0;  // 큐의 front와 rear 인덱스

int is_empty() {return front == rear;} // 큐가 비었는지 확인하는 함수
void push(int x) {queue[rear++] = x;} // 큐의 값 추가
int size() {return rear - front;} // 큐 크기 반환

// 큐에서 값 제거하고 반환 (pop)
int pop() {
    if (is_empty()) return -1;
    return queue[front++];
}

// 큐의 front 값 반환
int front_value() {
    if (is_empty()) return -1;
    return queue[front];
}

// 큐의 rear 값 반환
int back_value() {
    if (is_empty()) return -1;
    return queue[rear - 1];
}

int main() {
    int n;
    char command[10];

    scanf("%d", &n);
    while (n--) {
        scanf("%s", command);  // 명령어 입력

        if (strcmp(command, "push") == 0) {
            int x;
            scanf("%d", &x);
            push(x);
        }else if (strcmp(command, "pop") == 0) printf("%d\n", pop());
        else if (strcmp(command, "size") == 0) printf("%d\n", size());
        else if (strcmp(command, "empty") == 0) printf("%d\n", is_empty());
        else if (strcmp(command, "front") == 0) printf("%d\n", front_value());
        else if (strcmp(command, "back") == 0) printf("%d\n", back_value());
    }

    return 0;
}

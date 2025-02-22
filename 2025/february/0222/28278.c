#include <stdio.h>
#define MAX 1000000  // 최대 명령 개수

int stack[MAX];  // 스택 배열
int top = -1;    // 스택의 맨 위를 가리키는 변수
int main() {
    int n, cmd, x;
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &cmd);
        if (cmd == 1) {  // push
            scanf("%d", &x);
            stack[++top] = x;
        }else if (cmd == 2) {  // pop
            if (top == -1) printf("-1\n");
            else printf("%d\n", stack[top--]);
        }else if (cmd == 3) {  // size
            printf("%d\n", top + 1);
        }else if (cmd == 4) {  // empty
            printf("%d\n", (top == -1) ? 1 : 0);
        }else if (cmd == 5) {  // top
            if (top == -1) printf("-1\n");
            else printf("%d\n", stack[top]);
        }
    }
    return 0;
}

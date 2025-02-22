// 틀림... 이유 모르겟음.. 뭐지?

#include <stdio.h>
#include <string.h>

int main() {
    char str[101];

    while (1) {
        fgets(str, sizeof(str), stdin);
        if (str[0] == '.') break;  // "."만 들어오면 종료

        // 스택을 이용한 괄호 검사
        char stack[51]; 
        int top = -1;  // 스택의 top을 -1로 초기화

        int chk = 1;  // 균형 여부 판단 (1이면 균형, 0이면 불균형)
        for (int i = 0; str[i] != '.' && str[i] != '\0'; i++) { // '.'가 아닌 문자까지 처리
            if (str[i] == '(' || str[i] == '[') {
                stack[++top] = str[i]; // 열린 괄호 스택에 삽입
            }else if (str[i] == ')' || str[i] == ']') {
                if (top == -1) {  // 스택이 비어있으면 불균형
                    chk = 0;
                    break;
                }

                char last = stack[top--];  // 스택에서 맨 위의 값을 꺼냄
                if ((str[i] == ')' && last != '(') || (str[i] == ']' && last != '[')) {
                    // 짝이 맞지 않으면 불균형
                    chk = 0;
                    break;
                }
            }
        }

        if (top != -1) chk = 0; // 스택에 남은 열린 괄호가 있다면 불균형
        if (chk) puts("yes");
        else puts("no");
    }

    return 0;
}

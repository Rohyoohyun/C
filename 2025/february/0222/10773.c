#include <stdio.h>
#define MAX 100000  // 최대 입력 개수

int stack[MAX];  // 스택 배열
int top = -1;    // 스택의 맨 위를 가리키는 변수
int main() {
    int k, num, sum = 0;
    scanf("%d", &k);

    for (int i=0; i<k; i++) {
        scanf("%d", &num);
        if (num == 0) {  // 0이 입력되면 가장 최근 숫자를 제거
            if (top >= 0) top--;
        }else { // 숫자 입력되면 스택에 추가
            stack[++top] = num;
        }
    }

    // 스택에 남아 있는 숫자들의 합 계산
    for (int i=0; i<=top; i++) {
        sum += stack[i];
    }
    printf("%d", sum);  // 최종 결과 출력
    return 0;
}

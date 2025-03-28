#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

int main() {
    char exp[51];  // expression -> exp
    scanf("%s", exp);

    int res = 0, num = 0, sub = 0;  // result -> res, temp -> num, isMinus -> sub

    for (int i = 0; i <= strlen(exp); i++) {
        // 숫자인 경우 num에 누적
        if (isdigit(exp[i])) num = num * 10 + (exp[i] - '0');
        
        // 연산자이거나 문자열 끝이면 연산 수행
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '\0') {
            if (sub) res -= num;
            else res += num;
            num = 0;  // 다음 숫자를 위해 초기화
            if (exp[i] == '-') sub = 1;  // 이후 숫자부터는 빼기 연산 적용
        }
    }

    printf("%d", res);
    return 0;
}

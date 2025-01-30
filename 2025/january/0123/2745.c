#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>  // pow 함수 사용

int main() {
    char n[10001];
    int B;
    scanf("%s %d", n, &B); // 입력받기: 문자열 n과 진법 B

    int digit = strlen(n);
    int res = 0; 

    for (int i = 0; i < digit; i++) {
        char chk = n[i];
        int value;
        if (isupper(chk)) value = chk - 'A' + 10;
        else value = chk - '0';

        // 결과 계산: 현재 자리의 값 * B^(자리수)
        res += value * pow(B, digit - i - 1);
    }
    
    printf("%d", res);
    return 0;
}

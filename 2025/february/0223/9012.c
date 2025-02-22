#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);  // 테스트 케이스 개수

    while (T--) {
        char str[51];  // 최대 길이가 50인 괄호 문자열
        scanf("%s", str);

        int isVPS = 1;  // VPS 여부를 확인하는 변수 (1이면 YES, 0이면 NO)
        int count = 0;   // 열린 괄호 '(' 의 개수를 추적하는 변수

        for (int i=0; str[i]!='\0'; i++) {
            if (str[i] == '(') count++;
            else if (str[i] == ')') {
                count--;  // 닫힌 괄호일 경우 count 감소
                if (count < 0) {  // count가 음수이면 불일치
                    isVPS = 0;  // 불일치 발생 시 isVPS를 NO로 설정
                    break;
                }
            }
        }

        // 모든 괄호를 처리한 후, count가 0이 아니라면 불일치
        if (count != 0) isVPS = 0;

        // 결과 출력
        if (isVPS) puts("YES");
        else puts("NO");
    }

    return 0;
}

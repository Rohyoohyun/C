#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int a, b;
        scanf("%d %d", &a, &b);

        int last = a % 10;  // a의 마지막 자릿수
        int cycle[4], len = 0;

        // 마지막 자릿수의 주기 찾기
        int num = last;
        for (int i = 0; i < 4; i++) {
            cycle[i] = num % 10;
            num = (num * last) % 10;
            if (i > 0 && cycle[i] == cycle[0]) {  // 주기가 반복되면 종료
                len = i;
                break;
            }
        }
        if (len == 0) len = 4;  // 주기가 4보다 짧으면 len을 4로 설정

        // b에 대한 결과 찾기 (1부터 시작하므로 b-1을 사용)
        int res = cycle[(b - 1) % len];

        // 컴퓨터 번호 출력 (0이면 10번)
        printf("%d\n", res == 0 ? 10 : res);
    }

    return 0;
}


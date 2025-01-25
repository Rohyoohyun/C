#include <stdio.h>

char* func(int n, char* res) {
    int cnt = 1;
    while (n > cnt) { // n번째 분수가 어떤 대각선에 있는지 계산
        n -= cnt;
        cnt++;
    }

    int num, de;

    // 대각선의 번호가 짝수인지 홀수인지에 따라 분자와 분모 계산
    if (cnt%2 == 0) {  // 짝수 대각선: 분자가 감소, 분모가 증가
        num = n;
        de = cnt - n + 1;
    } else {  // 홀수 대각선: 분자가 증가, 분모가 감소
        num = cnt - n + 1;
        de = n;
    }
    sprintf(res, "%d/%d", num, de);
    return res;
}

int main() {
    int n;
    char res[20];
    scanf("%d", &n);
    printf("%s", func(n, res));
    return 0;
}

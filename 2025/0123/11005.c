#include <stdio.h>
#include <string.h>

void convert(int num, int base) {
    char res[10001];
    int index = 0; 

    // 숫자를 주어진 진법으로 변환
    while (num > 0) {
        int remainder = num % base; // 나머지 계산
        if (remainder < 10) res[index++] = '0' + remainder;
        else res[index++] = 'A' + (remainder - 10);
        num /= base; // 숫자를 나누어 다음 자리 계산
    }

    // 결과가 역순으로 저장되었으므로 뒤집어서 출력
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", res[i]);
    }
}

int main() {
    int num, B;
    scanf("%d %d", &num, &B);
    convert(num, B);
    return 0;
}

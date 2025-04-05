#include <stdio.h>

int main() {
    unsigned int S; // 부호없는 정수 생성
    scanf("%u", &S);

    unsigned int left = 1, right = 100000, answer = 0;

    while (left <= right) {
        unsigned int mid = (left + right) / 2;
        unsigned long long sum = (unsigned long long)mid * (mid + 1) / 2;

        if (sum <= S) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%u", answer);
    return 0;
}


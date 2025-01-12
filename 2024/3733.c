/*
// 시도1 -> 실패
#include <stdio.h>
#include <limits.h>
#define MAX 10000000

int memo[MAX+1]; // 길이를 저장할 배열
int collatz(int n) {
    if (n <= 0 || n > MAX) return 0; // 범위 벗어나면 0 반환
    if (memo[n] != 0) return memo[n]; // 이미 계산된 값이 있으면 반환

    if (n == 1) return 1;
    else if (n % 2 == 0) return memo[n] = 1 + collatz(n/2);
    else return memo[n] = 1 + collatz(3*n+1);
}

int main() {
    int a, b, len = 0, num = 0;
    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; i++) {
        int le = collatz(i);
        if (le > len) {
            len = le;
            num = i;
        }
    }
    printf("%d %d", num, len);

    return 0;
} 
*/

/*
// 시도2 -> 실패
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset 함수를 사용하기 위해(지정된 메모리 영역을 특정 값으로 채우는 함수)

int *memo;
int collatz(int n) {
    if (n <= 0) return 0;
    
    // 메모이제이션 배열의 크기 확인
    if (n <= 10000000 && memo[n-1] != 0) return memo[n-1];

    int steps = 1;
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
        
        steps++;
        // 메모이제이션 배열에서 이미 계산된 값 확인
        if (n <= 10000000 && memo[n-1] != 0) {
            steps += memo[n-1] - 1;
            break;
        }
    }

    // 메모이제이션 배열에 결과 저장
    if (n <= 10000000) memo[n-1] = steps;
    return steps;
}

int main() {
    int a, b, max_len = 0, max_num = 0;
    scanf("%d %d", &a, &b);

    // 메모이제이션 배열 동적 할당 및 초기화
    memo = (int*)calloc(b+1, sizeof(int));
    memset(memo, 0, sizeof(int) * (b+1));

    for (int i = a; i <= b; i++) {
        int len = collatz(i);
        if (len > max_len) {
            max_len = len;
            max_num = i;
        }
    }
    printf("%d %d", max_len, max_num);
    free(memo);
    return 0;
}
*/
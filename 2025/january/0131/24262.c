#include <stdio.h>

int MenOfPassion(int A[], int n) {
    int i = n / 2;
    return A[i]; // 코드1
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Men Of Passion 알고리즘
    printf("1\n"); // 코드1의 수행 횟수
    printf("0"); // 다항식의 최고차항 차수
    
    return 0;
}
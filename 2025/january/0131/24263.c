#include <stdio.h>

int MenOfPassion(int A[], int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i]; // 코드1
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    
    printf("%d\n", n); // 코드1의 수행 횟수
    printf("1"); // 다항식의 최고차항 차수
    
    return 0;
}

#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int cnt = 0; // 약수의 순서를 세기 위한 변수
    for (int i=1; i<=n; i++) {
        if (n%i == 0) {
            cnt++; // 약수 발견 시 순서 증가
            if (cnt == k) { // K번째 약수에 도달하면 출력 후 종료
                printf("%d", i);
                return 0;
            }
        }
    }
    printf("0"); // 약수의 개수가 K보다 적을 경우
    
    return 0;
}

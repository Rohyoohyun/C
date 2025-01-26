#include <stdio.h>

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == -1) break; // 입력이 -1인 경우 루프 종료

        int div[10001]; // 입력된 수의 약수를 저장할 배열
        int cnt=0, sum=0; // 약수의 개수를 저장할 변수(cnt), 약수의 합을 저장할 변수(sum)

        // 약수를 찾는 과정
        for (int i=1; i<n; i++) { // 1부터 n-1까지 반복
            if (!(n%i)) { // i가 n의 약수라면 (나머지가 0이면)
                div[cnt++] = i; // 약수를 div 배열에 저장하고, 약수 개수(cnt) 증가
                sum += i; // 약수의 값을 sum에 더함
            }
        }

        // 완전수 여부 판단 및 결과 출력
        if (sum == n) { // 약수의 합이 입력된 수와 같으면 완전수임
            printf("%d =", n); 
            for (int i = 0; i < cnt; i++) { // 저장된 약수를 돌며 출력
                if (i > 0) printf(" +"); // 첫 번째 약수 이후에는 "+" 기호를 출력
                printf(" %d", div[i]); // 약수를 출력
            }
            puts("");
        } else {
            // 약수의 합이 입력된 수와 다르면 완전수가 아님
            printf("%d is NOT perfect.\n", n);
        }
    }

    return 0;
}
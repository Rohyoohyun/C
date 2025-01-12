// 1856 : [기초-재귀함수] 계단 뛰어 오르기
/*
// ① 이전 코드
#include <stdio.h>

int func(int n){ // f(n) = f(n - 1) + f(n - 2) + f(n - 3) 규칙 적용
    if(n == 1) return 1;
    else if(n == 2) return 1 + func(1);
    else if(n == 3) return 1 + func(1) + func(2);
    else return func(n - 3) + func(n - 2) + func(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", func(n));
}*/

// ② 메모이제이션 활용
#include <stdio.h>

int memo[1001] = {0, 1, 2, 4, }; 
int func(int n){
    if (memo[n] ) return memo[n]; // 이미 계산된 값이 있으면 반환
    return memo[n] = func(n - 3) + func(n - 2) + func(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", func(n));
}

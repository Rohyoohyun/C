// 1861 : [기초-재귀함수] 파스칼의 삼각형 출력하기 2

#include <stdio.h>

int func_pos(int i, int j){ // 파스칼 삼각형 특정 위치값 계산 재귀 함수
    if (j == 0 || i == 0 || i == 1) return 1;
    if (i == j) return 1;
    return func_pos(i-1, j-1) + func_pos(i-1, j);  // 재귀 호출 (두 요소의 합)
}

void func_print(int row, int col){ // 특정 행 요소 출력 재귀함수
    if (col > row) {  // 모든 열 전체 출력
        puts("");
        return;
    }
    
    printf("%d ", func_pos(row, col));  // 현위치의 파스칼 삼각형 값 출력
    func_print(row, col+1);  // 다음 열 이동
}

void func(int n, int cur){ // 모든 행 출력 재귀함수
    if (cur >= n) return;  // 모든 행 전체 출력 후 종료
    func_print(cur, 0);  // 현재 행의 열 출력
    func(n, cur+1);  // 다음 행 이동
}

int main() {
    int n;
    scanf("%d", &n);
    func(n, 0);
    return 0;
}
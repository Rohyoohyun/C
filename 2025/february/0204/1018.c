#include <stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

char board[50][50];

// 8x8 크기의 체스판을 만들기 위해 다시 칠해야 하는 최소 개수를 계산하는 함수
int func(int x, int y) {
    char chess1[2] = {'W', 'B'}; // W부터 시작하는 체스판 패턴
    int count1 = 0, count2 = 0;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // W부터 시작하는 패턴과 비교하여 다시 칠해야 하는 개수 계산
            if (board[x + i][y + j] != chess1[(i + j) % 2]) count1++;
            // B부터 시작하는 패턴과 비교하여 다시 칠해야 하는 개수 계산
            if (board[x + i][y + j] != chess1[(i + j + 1) % 2]) count2++;
        }
    }
    return MIN(count1, count2); // 두 경우 중 최소값 반환
}

int main() {
    int n, m, res=64;
    scanf("%d %d", &n, &m);
    
    for (int i=0; i<n; i++) {
        scanf("%s", board[i]); // 보드 상태 입력
    }
    
    // 가능한 모든 8x8 영역에 대해 최소 다시 칠해야 하는 개수 계산
    for (int i=0; i<=n-8; i++)
        for (int j=0; j<=m-8; j++)
            res = MIN(res, func(i, j));
    printf("%d", res);
    
    return 0;
}

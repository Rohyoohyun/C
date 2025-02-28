#include <stdio.h>
#define SIZE 100   // 도화지 크기
#define PAPER 10   // 색종이 크기

int main() {
    int n;  // 색종이 개수
    scanf("%d", &n);

    int paper[SIZE][SIZE] = {0};
    for (int i=0; i<n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        // (x, y) 위치에서 10x10 크기만큼 1로 채움
        for (int dx = 0; dx < PAPER; dx++) {
            for (int dy = 0; dy < PAPER; dy++) {
                paper[x + dx][y + dy] = 1;
            }
        }
    }

    // 검은색 영역(1인 부분) 카운트
    int area = 0;
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            if (paper[i][j] == 1) {
                area++;
            }
        }
    }
    printf("%d", area);
    
    return 0;
}

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // x, y 좌표의 최솟값과 최댓값 초기화
    int minX = 10000, maxX = -10000;
    int minY = 10000, maxY = -10000;

    // 점의 좌표를 입력받으면서 최솟값과 최댓값 갱신
    for (int i=0; i<n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        // x 좌표의 최솟값 및 최댓값 갱신
        if (x < minX) minX = x;
        if (x > maxX) maxX = x;

        // y 좌표의 최솟값 및 최댓값 갱신
        if (y < minY) minY = y;
        if (y > maxY) maxY = y;
    }

    // 직사각형의 가로 길이와 세로 길이 계산
    long long width = maxX - minX; 
    long long height = maxY - minY;
    long long area = width * height;

    printf("%lld", area);

    return 0;
}

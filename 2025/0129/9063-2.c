#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int minX = INT_MAX, maxX = INT_MIN;
    int minY = INT_MAX, maxY = INT_MIN;

    for (int i=0; i<n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        // 최솟값과 최댓값 갱신
        if (x < minX) minX = x;
        if (x > maxX) maxX = x;
        if (y < minY) minY = y;
        if (y > maxY) maxY = y;
    }

    // 직사각형의 넓이 계산
    long long width = maxX - minX;
    long long height = maxY - minY;
    long long area = width * height;
    printf("%lld", area);

    return 0;
}

#include <stdio.h>

int main() {
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    // 각 경계선까지의 거리 계산
    int left = x;
    int right = w - x;
    int bottom = y;
    int top = h - y;

    // 최소 거리 찾기
    int min = left;
    if (right < min) min = right;
    if (bottom < min) min = bottom;
    if (top < min) min = top;

    printf("%d", min);

    return 0;
}

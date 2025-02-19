#include <stdio.h>

// 최대공약수(GCD) 계산 (유클리드 알고리즘)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n;
    scanf("%d", &n);

    int trees[n]; // 가로수 위치 배열
    for (int i=0; i<n; i++) {
        scanf("%d", &trees[i]);
    }

    // 첫 번째 간격 계산
    int g = trees[1] - trees[0];

    // 모든 간격의 최대공약수 구하기
    for (int i=2; i<n; i++) {
        g = gcd(g, trees[i] - trees[i-1]);
    }

    // 추가해야 하는 가로수 개수 계산
    int total = 0;
    for (int i=1; i<n; i++) {
        total += (trees[i] - trees[i-1]) / g - 1;
    }
    printf("%d", total);
    return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);

    // 계산: (V - A) / (A - B)를 올림 처리 후 +1
    int days = (int)ceil((double)(v-a)/(a-b)) + 1;
    
    printf("%d", days);
    return 0;
}
#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

int main() {
    int R;
    scanf("%d", &R);

    printf("%.6f\n", M_PI * R * R);
    printf("%.6f", 2.0 * R * R);

    return 0;
}

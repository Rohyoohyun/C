#include <stdio.h>

int main() {
    int angle1, angle2, angle3;
    scanf("%d %d %d", &angle1 , &angle2, &angle3);

    // 세 각의 합 계산
    int sum = angle1 + angle2 + angle3;
    if (sum != 180) printf("Error"); // 세 각의 합이 180이 아니면 Error
    else if (angle1 == 60 && angle2 == 60 && angle3 == 60) 
        printf("Equilateral"); // 세 각이 모두 60이면 Equilateral
    else if (angle1 == angle2 || angle2 == angle3 || angle1 == angle3)
        printf("Isosceles"); // 두 각이 같은 경우 Isosceles
    else printf("Scalene");

    return 0;
}

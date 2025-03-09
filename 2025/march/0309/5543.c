#include <stdio.h>

int main() {
    int burger[3], drink[2];
    for (int i = 0; i < 3; i++) scanf("%d", &burger[i]);
    for (int i = 0; i < 2; i++) scanf("%d", &drink[i]);

    // 가장 싼 햄버거와 음료 찾기
    int min_burger = (burger[0] < burger[1]) ? ((burger[0] < burger[2]) ? burger[0] : burger[2]) 
                                             : ((burger[1] < burger[2]) ? burger[1] : burger[2]);
    int min_drink = (drink[0] < drink[1]) ? drink[0] : drink[1];

    // 세트 가격 계산 및 출력
    printf("%d", min_burger + min_drink - 50);

    return 0;
}


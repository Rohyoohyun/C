#include <stdio.h>

int main() {
    int H, M;
    scanf("%d %d", &H, &M);

    M -= 45;  // 분에서 45분을 뺀다.
    if (M<0) {  // 만약 분이 음수가 되면
        M += 60;  // 60분을 더해서 양수로 만들고
        H -= 1;   // 시간을 1시간 줄인다.
        if (H < 0) H = 23;   // 하루 전날의 23시로 변경
    }
    printf("%d %d", H, M);
    return 0;
}

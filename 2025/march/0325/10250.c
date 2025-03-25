#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--){
        int H, W, N;
        scanf("%d %d %d", &H, &W, &N);
        
        int floor = (N % H == 0) ? H : N % H; // 층 번호
        int room = (N % H == 0) ? N / H : (N / H) + 1; // 방 번호
        
        printf("%d%02d\n", floor, room); // YYXX 형태 출력
    }
    
    return 0;
}

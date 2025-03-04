// 시간초과 

#include <stdio.h>
#include <string.h>
#define MAX_N 100000
#define MAX_LEN 21

char users[MAX_N][MAX_LEN];  // 닉네임 저장
int count[MAX_N];  // 사용 여부 체크
int main() {
    int n, cnt = 0, idx = 0;
    char input[MAX_LEN];

    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%s", input);

        if (strcmp(input, "ENTER") == 0) idx = 0;  // 새 그룹 시작
        else {
            int seen = 0;
            for (int j=0; j<idx; j++) {
                if (strcmp(users[j], input) == 0) {
                    seen = 1;
                    break;
                }
            }
            if (!seen) {  
                strcpy(users[idx++], input);
                cnt++;
            }
        }
    }
    printf("%d", cnt);
    
    return 0;
}

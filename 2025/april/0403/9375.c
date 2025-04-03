#include <stdio.h>
#include <string.h>

#define MAX 31

typedef struct {
    char n[21], t[21];
} C;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);
        
        if (n == 0) {
            printf("0\n");
            continue;
        }

        C c[MAX];
        char ty[MAX][21];
        int cnt[MAX] = {0}, tc = 0;

        for (int i = 0; i < n; i++) {
            scanf("%s %s", c[i].n, c[i].t);
            
            int f = 0;
            for (int j = 0; j < tc; j++) {
                if (strcmp(ty[j], c[i].t) == 0) {
                    cnt[j]++;
                    f = 1;
                    break;
                }
            }
            if (!f) {
                strcpy(ty[tc], c[i].t);
                cnt[tc++] = 1;
            }
        }

        int res = 1;
        for (int i = 0; i < tc; i++) {
            res *= (cnt[i] + 1);
        }
        printf("%d\n", res - 1);
    }

    return 0;
}


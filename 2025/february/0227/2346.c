#include <stdio.h>
#define Q_SIZE 1024
#define Q_MASK 1023
#define MAX_B 1000

int q[Q_SIZE], h = 0, t = 0, p[MAX_B];
int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) 
        q[i] = i + 1;
    t = n;
    
    for (int i = 0; i < n; i++) 
        scanf("%d", &p[i]);

    while (1) {
        // 풍선 터뜨리기
        printf("%d ", q[h]);
        int move = p[q[h] - 1];
        h = (h + 1) & Q_MASK;
        if (--n == 0) break;

        move = (move > 0) ? (move - 1) % n : n + (move % n);
        while (move--) {
            q[t] = q[h];
            h = (h + 1) & Q_MASK;
            t = (t + 1) & Q_MASK;
        }
    }
}

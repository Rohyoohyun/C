#include <stdio.h>
#define MAX 50

int memo[MAX][MAX];
int pascal(int n, int m){
    if(memo[n][m]) return memo[n][m];
    if(n==1 || m==1) return memo[n][m] = memo[m][n] = 1;
    return memo[n][m] = memo[m][n] = pascal(n-1, m)+pascal(n, m-1)%100000000;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d ", pascal(n, m));
    return 0;
}

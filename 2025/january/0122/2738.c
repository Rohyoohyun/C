#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d ", &arr[i][j]);

    int a;
    for(int i=0; i<n; i++, puts("")){
        for(int j=0; j<m; j++){
            scanf("%d ", &a);
            printf("%d ", a+arr[i][j]);
        }
    }

  return 0;
}

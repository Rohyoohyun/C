#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for(int i=1; i<=n; i++)
        arr[i] = 0;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int start, end, ball;
            scanf("%d %d %d", &start, &end, &ball);
            for(int k=start; k<=end; k++){
                arr[k] = ball;
            }
        }
    }

    for(int i=1; i<=n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}

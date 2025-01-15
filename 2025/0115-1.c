#include <stdio.h>

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for(int i=0; i<n; i++)
        arr[i] = i+1;

    int a, b;
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        for(int j=a-1; j<b; j++){
            int tmp = arr[j];
            arr[j] = arr[b-1];
            arr[b-1] = tmp;
            b--;
        }
    }

    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);

    return 0;
}

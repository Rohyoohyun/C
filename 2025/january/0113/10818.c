#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], max=-1000000, min=1000000;
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    for(int i=0; i<n; i++){
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }
    
    printf("%d %d", min, max);
    
    return 0;
}

#include <stdio.h>

int main() {
    int n;
    int arr[] = {1, 1, 2, 2, 2, 8};
    for(int i=0 ;i<6; i++){
        scanf("%1d ", &n);
        printf("%d ", arr[i] - n);
    }
    
    return 0;
}

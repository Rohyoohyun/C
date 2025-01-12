#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &n);

    int cnt=0;
    for(int i=0; i<sizeof(arr); i++){
        if(n == arr[i]) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
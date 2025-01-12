#include <stdio.h>

int main(){
    int n, v;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
        
    scanf("%d", &v);

    int cnt=0;
    for(int i=0; i<n; i++)
        if(v == arr[i]) cnt++;
    printf("%d", cnt);
    
    return 0;
}
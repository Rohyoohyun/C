#include <stdio.h>

int main() {
    int arr[10]={0};
    int max=0, idx=0;

    for(int i=0; i<10; i++)
        scanf("%d", &arr[i]);

    for(int i=0; i<10; i++)
        if(max < arr[i]){
            max = arr[i];
            idx = i;
        }

    printf("%d\n%d", max, idx);
    
    return 0;
}

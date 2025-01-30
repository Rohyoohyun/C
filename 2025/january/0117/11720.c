#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char str[n];
    scanf("%s", str);

    int sum=0;
    for(int i=0; i<n; i++){
        sum += (48 - str[i]);
    }
    printf("%d", -sum);
    
    return 0;
}

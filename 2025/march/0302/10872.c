#include <stdio.h>

int func(int n){
    return n ? n * func(n-1) : 1; 
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", func(n));
}

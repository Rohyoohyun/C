#include <stdio.h>

int main(){
    int n, result=0;
    int remain[10];
    
    for(int i=0; i<10; i++) {
        scanf("%d", &n);
        remain[i] = (n%42);
    }
    
    for(int i=0; i<10; i++) {
        int count=0;
        for(int j=i+1; j<10; j++)
            if(remain[i] == remain[j]) count++;
        if (!count) result++; // 같은 수가 없을 경우 개수를 세준다
    }
    
   printf("%d", result);
   return 0;
}

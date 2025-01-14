#include <stdio.h>

int main() {
    int stu[31] = {0};

    int n;
    for(int i=1; i<=28; i++){
        scanf("%d", &n);
        stu[n] = 1;
    }

    for(int i=1; i<=30; i++){
        if(stu[i] != 1) 
            printf("%d\n", i);
    }
    
    return 0;
}

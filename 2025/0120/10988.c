#include <stdio.h>
#include <string.h>

int main() {
    char str[101]={0};
    scanf("%s", str);

    int f=1, len = strlen(str);
    for(int i=0; i<len/2; i++){
        if(str[i] != str[len-i- 1]) f=0;
    }
    printf("%d", f);
    return 0;
}

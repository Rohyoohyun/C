#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int cnt;
    char str[21];
    for(int i=0; i<n; i++, puts("")){
        scanf("%d %s", &cnt, str);
        for(int j=0; j<strlen(str); j++){
            for(int k=0; k<cnt; k++)
                printf("%c", str[j]);
        }
    }
    return 0;
}

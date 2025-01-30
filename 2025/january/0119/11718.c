#include <stdio.h>

int main() {
    char str[101];
    while(scanf("%[^\n]", str) != EOF) {
        printf("%s\n", str);
        getchar();
    }
    return 0;
}

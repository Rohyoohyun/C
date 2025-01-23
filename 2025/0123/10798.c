#include <stdio.h>
#include <string.h>

int main() {
    char str[5][15];
    int arr[5] = {0};
    int max = 0, a;
    for (int i = 0; i < 5; i++) {
        scanf("%s", str[i]);
        arr[i] = strlen(str[i]);
        if (arr[i] > max) max = arr[i];
    }
    
    for (int j = 0; j < max; j++)
        for (int i = 0; i < 5; i++)
            if (arr[i] > j) printf("%c", str[i][j]);
    
    return 0;
}

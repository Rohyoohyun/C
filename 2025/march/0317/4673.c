#include <stdio.h>
#define MAX 10000 

int arr[MAX];
int func(int n) {
    int ret = n;
    while (n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main() {
    for (int i = 0; i < MAX; ++i) {
        int ret = func(i);
        if (ret < MAX) arr[ret] = 1;
    }

    for (int i = 0; i < MAX; ++i) {
        if (!arr[i]) printf("%d\n", i);
    }
    return 0;
}

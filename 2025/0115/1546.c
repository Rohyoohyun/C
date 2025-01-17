#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    int score[n], max=0;
    for (int i=0; i<n; i++) {
        scanf("%d", &score[i]);
        if (max < score[i]) max = score[i];
    }

    float avg = 0;
    for (int i=0; i<n; i++)
        avg += (float)score[i] / max * 100;

    printf("%f", avg/n);

    return 0;
}

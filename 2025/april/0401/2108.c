#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 4000

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int N;
    scanf("%d", &N);

    int num[N], freq[8001] = {0};  
    int sum = 0, m_freq = 0, mode, m_cnt = 0;
    int min = 4001, max = -4001;

    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
        sum += num[i];

        int idx = num[i] + MAX;
        freq[idx]++;
        if (freq[idx] > m_freq) m_freq = freq[idx];

        if (num[i] < min) min = num[i];
        if (num[i] > max) max = num[i];
    }

    qsort(num, N, sizeof(int), cmp);

    for (int i = -MAX; i <= MAX; i++) {
        if (freq[i + MAX] == m_freq) {
            if (m_cnt == 0) mode = i;
            else if (m_cnt == 1) {
                mode = i;
                break;
            }
            m_cnt++;
        }
    }

    printf("%d\n", (int)round((double)sum / N));
    printf("%d\n", num[N / 2]);
    printf("%d\n", mode);
    printf("%d\n", max - min);

    return 0;
}

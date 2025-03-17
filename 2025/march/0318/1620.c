#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100000
#define LEN 21

typedef struct {
    char nm[LEN];
    int no;
} Pkm;

Pkm pkm[MAX + 1];           // 포켓몬 정보 저장
char nam[MAX + 1][LEN];    // 번호로 포켓몬 이름 찾기

// 문자열 비교 함수 (퀵 정렬용)
int cmp(const void *a, const void *b) {
    Pkm *p1 = (Pkm *)a;
    Pkm *p2 = (Pkm *)b;
    return strcmp(p1->nm, p2->nm);
}

// 이진 탐색 함수
int bns(int l, int r, char *key) {
    while (l <= r) {
        int m = (l + r) / 2;
        int c = strcmp(pkm[m].nm, key);
        if (c == 0)
            return pkm[m].no;
        else if (c < 0)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1; // 찾지 못했을 때
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i=1; i<=n; i++) {
        scanf("%s", nam[i]);             // 번호로 이름 저장
        strcpy(pkm[i-1].nm, nam[i]);   // 이름 저장
        pkm[i-1].no = i;              // 번호 저장
    }

    qsort(pkm, n, sizeof(Pkm), cmp); // 이름 기준 정렬

    char qry[LEN];
    for (int i=0; i<m; i++) {
        scanf("%s", qry);
        
        if (qry[0] >= '0' && qry[0] <= '9') {  // 번호 입력 시
            int idx = atoi(qry);
            printf("%s\n", nam[idx]);
        }else {     // 이름 입력 시
            int res = bns(0, n-1, qry);
            printf("%d\n", res);
        }
    }

    return 0;
}

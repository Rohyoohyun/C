#include <stdio.h>

int arr[65];
int binary(int low, int high, int k, int ascending, int *count) { // 재귀사용 이진탐색
    (*count)++;  // 탐색 횟수 증가

    if (low > high) return -1; // 탐색 범위 유효X 실패 반환
    
    int mid = (low + high) / 2;
    if (arr[mid] == k) return *count;  // 키를 찾은 경우
    if (ascending) {  // 오름차순 이진 탐색
        if (arr[mid] > k) return binary(low, mid - 1, k, ascending, count);
        else return binary(mid + 1, high, k, ascending, count);
    }else{  // 내림차순 이진 탐색
        if (arr[mid] < k) return binary(low, mid - 1, k, ascending, count);
        else return binary(mid + 1, high, k, ascending, count);
    }
}

// 배열이 정렬 확인
int sorted(int n) {
    int resUP = 1, resD = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1]) resD = 0;  // 내림차순이 아님
        else if (arr[i] < arr[i-1]) resUP = 0;  // 오름차순이 아님
    }
    if (resUP) return 1;  // 오름차순
    else if (resD) return -1; // 내림차순
    else return 0;
}

int main() {
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &k);

    int res = sorted(n);
    if (res == 0)  printf("불가능");
    else {
        int count = 0;
        int result = binary(0, n - 1, k, res == 1, &count);
        if (result == -1) printf("실패");
        else printf("%d", result);  // 탐색에 성공한 경우 탐색 횟수 출력
    }

    return 0;
}
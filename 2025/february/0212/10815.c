#include <stdio.h>
#include <stdlib.h>

// 비교 함수 (오름차순 정렬)
int compare(const void *a, const void *b) {
    // void 포인터를 int 포인터로 변환한 후, 값을 가져옴
    int num1 = *(int*)a; 
    int num2 = *(int*)b; 
    
    // 두 값을 비교하여 정렬 순서 결정
    return num1 - num2; // (num1 < num2) → 음수 반환 → num1이 num2보다 앞에 위치 (오름차순)
                        // (num1 > num2) → 양수 반환 → num2가 num1보다 앞에 위치
                        // (num1 == num2) → 0 반환 → 위치 변경 없음
}

// 이분 탐색 함수
int func(int arr[], int size, int target) {
    int left = 0, right = size-1, mid;
    while (left <= right) {
        mid = (left+right) / 2;
        if (arr[mid] == target) return 1;  // 숫자를 찾으면 1 반환
        else if (arr[mid] < target) left = mid+1; // 오른쪽 범위 탐색
        else right = mid-1; // 왼쪽 범위 탐색
    }
    return 0;  // 숫자를 찾지 못하면 0 반환
}

int main() {
    int n, m;
    scanf("%d", &n);
    
    int *cards = (int*)malloc(n * sizeof(int)); // 동적 배열 할당 (상근이의 숫자 카드 저장)
    for (int i=0; i<n; i++) {
        scanf("%d", &cards[i]); // 숫자 카드 입력 받기
    }

    // 숫자 카드 정렬 (이분 탐색을 위해 오름차순 정렬)
    qsort(cards, n, sizeof(int), compare);

    scanf("%d", &m);
    
    // M개의 숫자 검사 및 출력
    for (int i=0; i<m; i++) {
        int num;
        scanf("%d", &num); // 검사할 숫자 입력 받기
        printf("%d ", func(cards, n, num)); // 존재 여부 출력
    }
    free(cards); // 동적 메모리 해제
    
    return 0;
}


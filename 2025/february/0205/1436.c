int is_end_number(int num) {
    int temp = num;
    while (temp >= 666) {  // 숫자가 666 이상일 때만 검사
        if (temp % 1000 == 666) {  // 끝 세 자리가 666이면
            return 1;  // 종말의 수임을 반환
        }
        temp /= 10;  // 한 자리씩 줄여가며 666이 포함되어 있는지 확인
    }
    return 0;  // 666이 포함되지 않으면 0 반환
}

int main() {
    int N, count = 0, num = 666;
    scanf("%d", &N);  // 사용자로부터 N 입력 받기
    
    while (count < N) {  // N번째 종말의 수를 찾을 때까지 반복
        if (is_end_number(num)) {  // 현재 숫자가 종말의 수인지 확인
            count++;  // 종말의 수이면 count 증가
        }
        num++;  // 다음 숫자로 이동
    }
    
    printf("%d", num - 1);  // N번째 종말의 수 출력
    return 0;
}

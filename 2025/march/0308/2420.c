#include <stdio.h>
#include <stdlib.h>  // abs 함수 사용

int main() {
    long long N, M;
    scanf("%lld %lld", &N, &M);
    printf("%lld", llabs(N - M));  // llabs()를 사용하여 절댓값 계산
    return 0;
}

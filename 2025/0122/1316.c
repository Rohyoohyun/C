#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n); 

  char s[101]; 
  int flag, ans = 0; // flag: 그룹 단어 여부 판단, ans: 그룹 단어 개수
  while(n--) {
    scanf("%s", s); // 단어를 입력받음

    int isUsed[26] = { 0, }; // 알파벳 사용 여부를 체크 배열
    isUsed[s[0] - 'a'] = 1; // 첫 번째 문자의 알파벳을 사용했다고 표시
    flag = 1; // 기본적으로 그룹 단어라고 가정

    for(int i = 1; i < strlen(s); i++) { // 단어의 두 번째 문자부터 끝까지 순회
      if(s[i] == s[i - 1]) continue; // 이전 문자와 동일하면 건너뜀 (연속된 경우 허용)
      if(isUsed[s[i] - 'a']) flag = 0; // 이전에 등장했던 알파벳이 다시 나오면 그룹 단어 아님
      isUsed[s[i] - 'a'] = 1; // 현재 문자를 사용했다고 표시
    }
    if(flag) ans++; // 그룹 단어이면 ans 값 증가
  }
  printf("%d", ans); // 그룹 단어의 총 개수를 출력

  return 0;
}


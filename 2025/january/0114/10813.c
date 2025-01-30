#include <stdio.h>

int arr[101];
void swap(int a, int b) {
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  for(int i=1; i<=n; i++)
      arr[i] = i;

  int a, b;
  for(int i=0; i<m; i++) {
    scanf("%d %d", &a, &b);
    swap(a, b);
  }

  for(int i=1; i<=n; i++)
      printf("%d ", arr[i]);

  return 0;
}

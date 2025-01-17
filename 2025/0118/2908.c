#include <stdio.h>
#include <stdbool.h>

int main() {
	char a[3], b[3];
	scanf("%s %s", a, b);
	bool flag;

	for (int i=2; i>=0; i--) {
		if (a[i] > b[i]) {
			flag = true;
			break;
		}else if (a[i] < b[i]) {
			flag = false;
			break;
		}
	}

	for (int i=2; i>=0; i--) {
		if (flag) printf("%c", a[i]);
		else printf("%c", b[i]);
	}
	return 0;
}

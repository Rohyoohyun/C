#include <stdio.h>
#include <string.h>

int main() {
	char s[101];
	int ans = 0, i = 0;
	scanf("%s", s);


	while (i < strlen(s)) {
		if (s[i] == 'c') {
			if (s[i + 1] == '=')
				i++;
			else if (s[i + 1] == '-')
				i++;
		}else if (s[i] == 'd') {
			if (s[i + 1] == '-')
				i++;
			else if (s[i + 1] == 'z' && s[i + 2] == '=')
				i += 2;
		}else if (s[i] == 'l') {
			if (s[i + 1] == 'j')
				i++;
		}else if (s[i] == 'n') {
			if (s[i + 1] == 'j')
				i++;
		}else if (s[i] == 's') {
			if (s[i + 1] == '=')
				i++;
		}else if (s[i] == 'z') {
			if (s[i + 1] == '=')
				i++;
		}
        ans++;
		i++;
	}
	printf("%d", ans);
    return 0;
}

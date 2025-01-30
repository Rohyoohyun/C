#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	int cnt[26] = {0}, max=-1;
	char res;

	char s[1000001];
	scanf("%s", s);

    int t = strlen(s);
	for (int i = 0; i < t; i++) {
         s[i] = toupper(s[i]);
		if (++cnt[s[i]-65] > max) { 
			max = cnt[s[i]-65];
			res = s[i];
		}
	}

	int check = 0;
	for (int i = 0; i < 26; i++)
        if (max == cnt[i]) check++;

	if (check == 1) printf("%c", res);
	else printf("?");

	return 0;
}

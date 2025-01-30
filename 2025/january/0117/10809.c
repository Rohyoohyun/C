#include <stdio.h>
#include <string.h>

int main() {
	char s[101];
	scanf("%s", s);

    int alpa[26];
    for(int i=0; i<26; i++)
        alpa[i] = -1;

    for(int i=0; i<26; i++){
        for(int j=0; j<strlen(s); j++){
            if(alpa[i] == -1 && i == (s[j] - 97))
                alpa[i] = j;
        }
    }

	for (int i=0; i<26; i++) {
		printf("%d ", alpa[i]);
	}

	return 0;
}
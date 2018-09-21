#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char yeob[256];

int main(void)
{
	int i, h = 0, s = 0;
	scanf("%[^\n]", &yeob);
	
	for (i = 2; yeob[i]; i++) {
		if (yeob[i] == ')') {
			if (yeob[i - 1] == '-' && yeob[i - 2] == ':') ++h;
		}
		else if (yeob[i] == '(') {
			if (yeob[i - 1] == '-' && yeob[i - 2] == ':') ++s;
		}
	}

	if (h == 0 && s == 0) {
		printf("none\n");
		return 0;
	}

	if (h > s) printf("happy\n");
	else if (h == s) printf("unsure\n");
	else printf("sad\n");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char input[1000001];
char answer[1000001];

int main(void)
{
	int T, a, b, i;
	scanf("%d", &T);
	
	while (T--)
	{
		scanf(" %d %d", &a, &b);
		scanf(" %s", &input);
		for (i = 0; input[i]; i++) answer[i] = (char)((((input[i] - 'A') * a + b) % 26) + 'A');
		printf("%s\n", answer); 
		for (i = 0; input[i]; i++) {
			input[i] = 0;
			answer[i] = 0;
		}
	}

	return 0;
}

// https://www.acmicpc.net/problem/11575

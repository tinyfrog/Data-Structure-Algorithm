#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, T, N, t2;
	char m, t1;

	scanf("%d", &T);

	while (T--)
	{
		scanf(" %d %c", &N, &m);
		if (m == 'C') {
			for (i = 1; i <= N; i++) {
				scanf(" %c", &t1);
				printf("%d ", t1 - 'A' + 1);
			}
		}
		else if (m == 'N') {
			for (i = 1; i <= N; i++) {
				scanf(" %d", &t2);
				printf("%c ", t2 + 'A' - 1);
			}
		}
		printf("\n");
	}
	return 0;
}
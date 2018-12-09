#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, Asize[5], Bsize[5];
char winner;

void check()
{
	if (Bsize[4] > Asize[4]) winner = 'B';
	else if (Bsize[4] == Asize[4]) {
		if (Bsize[3] > Asize[3]) winner = 'B';
		else if (Bsize[3] == Asize[3]) {
			if (Bsize[2] > Asize[2]) winner = 'B';
			else if (Bsize[2] == Asize[2]) {
				if (Bsize[1] > Asize[1]) winner = 'B';
				else if (Bsize[1] == Asize[1]) winner = 'D';
				else winner = 'A';
			}
			else winner = 'A';
		}
		else winner = 'A';
	}
	else winner = 'A';
}

int main(void)
{
	int i, j, a, b, t;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < 5; j++) {
			Asize[j] = 0, Bsize[j] = 0;
		}

		scanf("%d", &a);
		for (j = 0; j < a; j++) {
			scanf("%d", &t);
			++Asize[t];
		}
		scanf("%d", &b);
		for (j = 0; j < b; j++) {
			scanf("%d", &t);
			++Bsize[t];
		}
		
		check();
		printf("%c\n", winner);
	}

	return 0;
}
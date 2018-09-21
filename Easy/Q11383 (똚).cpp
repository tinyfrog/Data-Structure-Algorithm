#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char input[21];
char ans[11][21];

int main(void)
{
	int i, j, N, M;
	bool flag;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%s", &input);
		for (j = 0; j < M; j++) {
			ans[i][2 * j] = input[j];
			ans[i][2 * j + 1] = input[j];
		}
	}

	flag = true;
	for (i = 0; i < N; i++) {
		scanf("%s", &input);
		for (j = 0; j < 2 * M; j++) {
			if (ans[i][j] != input[j]) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}
	if (flag) printf("Eyfa\n");
	else printf("Not Eyfa\n");
	return 0;
}

// https://www.acmicpc.net/problem/11383

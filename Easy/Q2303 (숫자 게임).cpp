#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ar[1001][5];
int ans[1001];

int max(int x, int y)
{
	return (x >= y) ? x : y;
}

int main(void)
{
	int i, j, k, l, N, t, winner;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		for (j = 0; j < 5; j++) scanf("%d", &ar[i][j]);
	}

	for (l = 1; l <= N; l++) {
		for (i = 0; i < 5; i++) {
			for (j = i + 1; j < 5; j++) {
				for (k = j + 1; k < 5; k++) {
					ans[l] = max(ans[l], (ar[l][i] + ar[l][j] + ar[l][k]) % 10);
				}
			}
		}
	}

	t = 0, winner;
	for (i = 1; i <= N; i++) {
		if (ans[i] >= t) {
			t = ans[i];
			winner = i;
		}
	}

	printf("%d\n", winner);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2303
// 구현
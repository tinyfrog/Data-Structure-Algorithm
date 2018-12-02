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
	int i, j, l, N, t, winner;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		for (j = 0; j < 5; j++) scanf("%d", &ar[i][j]);
	}

	for (l = 1; l <= N; l++) {
		for (i = l + 1; i <= N; i++) {
			for (j = 0; j < 5; j++) {
				if (ar[l][j] == ar[i][j]) {
					++ans[l];
					++ans[i];
					break;
				}
			}
		}
	}

	t = -1, winner; // 모두가 0명일수도 있음
	for (i = 1; i <= N; i++) {
		if (ans[i] > t) {
			t = ans[i];
			winner = i;
		}
	}

	printf("%d\n", winner);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/1268
// 구현
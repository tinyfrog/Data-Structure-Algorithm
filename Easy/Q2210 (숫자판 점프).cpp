#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int ar[6][6];
int save[25601];
int idx;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

void go(int x, int y, int c, int num)
{
	int i;
	if (num == 6) {
		for (i = 0; i < idx; i++) {
			if (c == save[i]) return;
		}
		save[idx++] = c;
		return;
	}

	for (i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || x + dx[i] >= 5 || y + dy[i] < 0 || y + dy[i] >= 5) continue;

		if (num == 0) go(x + dx[i], y + dy[i], c + 100000 * ar[x][y], 1);
		else if (num == 1) go(x + dx[i], y + dy[i], c + 10000 * ar[x][y], 2);
		else if (num == 2) go(x + dx[i], y + dy[i], c + 1000 * ar[x][y], 3);
		else if (num == 3) go(x + dx[i], y + dy[i], c + 100 * ar[x][y], 4);
		else if (num == 4) go(x + dx[i], y + dy[i], c + 10 * ar[x][y], 5);
		else if (num == 5) go(x + dx[i], y + dy[i], c + ar[x][y], 6);
	}
}

int main(void)
{
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) scanf("%d", &ar[i][j]);
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) go(i, j, 0, 0);
	}

	printf("%d\n", idx);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2210
// 2210 숫자판 점프
// 백트래킹
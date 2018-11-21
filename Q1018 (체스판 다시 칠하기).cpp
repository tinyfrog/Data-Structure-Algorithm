#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INF 2501

char map[51][51], c1[8][8], c2[8][8];
int ans, M, N;

int min(int a, int b)
{
	return (a <= b) ? a : b;
}

int check(int a, int b)
{
	int i, j, temp, t1 = 0, t2 = 0, x = 0, y = 0;

	for (i = a; i < a + 8; i++) {
		for (j = b; j < b + 8; j++) {
			if (map[i][j] != c1[x][y]) ++t1;
			if (t1 >= ans) {
				t1 = INF;
				break;
			}
			++y;
		}
		y = 0;
		++x;
		if (t1 >= ans) break;
	}

	x = 0, y = 0;
	for (i = a; i < a + 8; i++) {
		for (j = b; j < b + 8; j++) {
			if (map[i][j] != c2[x][y]) ++t2;
			if (t2 >= ans) {
				t2 = INF;
				break;
			}
			++y;
		}
		y = 0;
		++x;
		if (t2 >= ans) break;
	}
	
	temp = min(t1, t2);
	return temp;
}

int main(void)
{
	int i, j, t;
	ans = INF;
	for (i = 0; i < 51; i++) { // 초기화
		for (j = 0; j < 51; j++) map[i][j] = 0;
	}

	for (i = 0; i < 8; i++) { // 초기화
		for (j = 0; j < 8; j++) {
			c1[i][j] = 0, c2[i][j] = 0;
		}
	}

	scanf("%d %d", &M, &N);
	for (i = 0; i < M; i++) scanf("%s", &map[i]); // 입력 줄단위로 받기

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) c1[i][j] = 'W';
			else c1[i][j] = 'B';
		}
	}

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) c2[i][j] = 'B';
			else c2[i][j] = 'W';
		}
	}

	for (i = 0; i <= M-8; i++) {
		for (j = 0; j <= N-8; j++) {
			t = check(i, j);
			if (t == INF) continue;
			ans = min(ans, t);
		}
	}
	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/1018
// 구현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

char candy[51][51];
int N, ans;

void change(int x, int y, int mode) 
{
	char t, start;
	int i, check = 1;
	if (mode) { // 가로 바꿈
		t = candy[x][y];
		candy[x][y] = candy[x][y + 1];
		candy[x][y + 1] = t;

		start = candy[x][0];
		for (i = 1; i < N; i++) {
			if (candy[x][i] != start) {
				check = 1;
				start = candy[x][i];
			}
			else check++;
			ans = max(ans, check);
		}
		

		start = candy[0][y];
		check = 1;
		for (i = 1; i < N; i++) {
			if (candy[i][y] != start) {
				check = 1;
				start = candy[i][y];
			}
			else check++;
			ans = max(ans, check);
		}

		start = candy[0][y+1];
		check = 1;
		for (i = 1; i < N; i++) {
			if (candy[i][y+1] != start) {
				check = 1;
				start = candy[i][y+1];
			}
			else check++;
			ans = max(ans, check);
		}

		t = candy[x][y]; // 원래대로
		candy[x][y] = candy[x][y + 1];
		candy[x][y + 1] = t;
	}
	else { // 세로 바꿈
		t = candy[x][y];
		candy[x][y] = candy[x + 1][y];
		candy[x + 1][y] = t;

		start = candy[0][y];
		check = 1;
		for (i = 1; i < N; i++) {
			if (candy[i][y] != start) {
				check = 1;
				start = candy[i][y];
			}
			else check++;
			ans = max(ans, check);
		}

		start = candy[x][0];
		check = 1;
		for (i = 1; i < N; i++) {
			if (candy[x][i] != start) {
				check = 1;
				start = candy[x][i];
			}
			else check++;
			ans = max(ans, check);
		}

		start = candy[x+1][0];
		check = 1;
		for (i = 1; i < N; i++) {
			if (candy[x+1][i] != start) {
				check = 1;
				start = candy[x+1][i];
			}
			else check++;
			ans = max(ans, check);
		}

		t = candy[x][y]; // 원래대로
		candy[x][y] = candy[x + 1][y];
		candy[x + 1][y] = t;
	}
}

int main(void)
{
	int i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) scanf(" %c", &candy[i][j]);
	}

	ans = 1;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - 1; j++) change(i, j, 1);
	}

	for (j = 0; j < N; j++) {
		for (i = 0; i < N - 1; i++) change(i, j, 0);
	}

	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/3085
// 3085 사탕게임 
// 브루트 포스
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct point {
	int x, y;
};

point house[101];
point chicken[14];
point candidate[14];
bool check[14];

int N, M;
int idx1, idx2, idx3, ans;

int abs(int x, int y)
{
	return (x - y < 0) ? (-x + y) : (x - y);
}

int min(int x, int y)
{
	return (x <= y) ? x : y;
}

void cal(void)
{
	int i, j, t, sum = 0;
	for (i = 0; i < idx1; i++) {
		t = 987654321;
		for (j = 0; j < idx3; j++) {
			t = min(t, abs(candidate[j].x, house[i].x) + abs(candidate[j].y, house[i].y));
		}
		sum += t;
		if (sum >= ans) return;
	}
	ans = sum;
}

void select(int idx, int num)
{
	if (num == M) {
		cal();
		return;
	}

	int i;
	for (i = idx; i < idx2; i++) {
		if (!check[i]) {
			check[i] = true;
			candidate[idx3++] = chicken[i];
			select(i + 1, num + 1);
			--idx3;
			check[i] = false;
		}
	}
}

int main(void)
{
	int i, j, t;
	idx1 = 0, idx2 = 0, idx3 = 0, ans = 987654321;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &t);
			if (t == 1) house[idx1++] = { i, j };
			else if (t == 2) chicken[idx2++] = { i, j };
		}
	}

	select(0, 0);
	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/15686
// 브루트 포스 
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int N, ans;
int dice[10001][6];

void cal(int idx, int num, int sum)
{
	if (idx == N) {
		ans = max(ans, sum);
		return;
	}

	int i, j, next, t = 0;
	bool check[6];
	for (i = 0; i < 6; i++) check[i] = true;

	for (i = 0; i < 6; i++) {
		if (dice[idx][i] == num) {
			check[i] = false;
			switch (i)
			{
			case 0:
				next = dice[idx][5];
				check[5] = false;
				break;
			case 1:
				next = dice[idx][3];
				check[3] = false;
				break;
			case 2:
				next = dice[idx][4];
				check[4] = false;
				break;
			case 3:
				next = dice[idx][1];
				check[1] = false;
				break;
			case 4: 
				next = dice[idx][2];
				check[2] = false;
				break;
			case 5:
				next = dice[idx][0];
				check[0] = false;
				break;
			}

			for (j = 0; j < 6; j++) {
				if (check[j]) t = max(t, dice[idx][j]);
			}

			cal(idx + 1, next, sum + t);
			break;
		}
	}

	return;
}

int main(void)
{
	int i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < 6; j++) scanf("%d", &dice[i][j]);
	}

	ans = 0;
	for (i = 0; i < 6; i++) cal(0, dice[0][i], 0);
	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2116
// 03 KOI 초등부 2번
// 구현
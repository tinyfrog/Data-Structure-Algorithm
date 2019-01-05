#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int lim[101][2], drive[101][2];

int main(void)
{
	int i, t, N, M, idx1 = 0, idx2 = 0, ans = 0;
	scanf("%d %d", &N, &M);

	scanf("%d %d", &lim[0][0], &lim[0][1]);
	for (i = 1; i < N; i++) {
		scanf("%d %d", &t, &lim[i][1]);
		lim[i][0] = t + lim[i - 1][0];
	}

	scanf("%d %d", &drive[0][0], &drive[0][1]);
	for (i = 1; i < M; i++) {
		scanf("%d %d", &t, &drive[i][1]);
		drive[i][0] = t + drive[i - 1][0];
	}
	
	for (i = 1; i <= 100; i++) {
		if (i <= lim[idx1][0]) {
			if (i <= drive[idx2][0]) {
				if (drive[idx2][1] - lim[idx1][1] > ans) ans = drive[idx2][1] - lim[idx1][1];
			}
			else {
				++idx2;
				if (drive[idx2][1] - lim[idx1][1] > ans) ans = drive[idx2][1] - lim[idx1][1];
			}
		}
		else {
			++idx1;
			if (i <= drive[idx2][0]) {
				if (drive[idx2][1] - lim[idx1][1] > ans) ans = drive[idx2][1] - lim[idx1][1];
			}
			else {
				++idx2;
				if (drive[idx2][1] - lim[idx1][1] > ans) ans = drive[idx2][1] - lim[idx1][1];
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11971
// USACO 15/12 Bronze 2번
// 구현
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

long long dp[11][65];

int main(void)
{
	int i, j, k, T, N, cal = 1;
	for (i = 0; i <= 9; i++) dp[i][1] = 1;
	dp[10][1] = 10;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		if (cal >= N) {
			printf("%lld\n", dp[10][N]);
			continue;
		}
		for (i = cal + 1; i <= N; i++) {
			for (j = 9; j >= 0; j--) {
				for (k = j; k <= 9; k++) dp[j][i] += dp[k][i-1];
			}
			for (j = 9; j >= 0; j--) dp[10][i] += dp[j][i];
		}
		cal = N;
		printf("%lld\n", dp[10][N]);
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2688
// 2688 줄어들지 않아
// DP
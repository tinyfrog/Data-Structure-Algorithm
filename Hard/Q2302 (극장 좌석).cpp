#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool check[41];
int dp[41];

int main(void)
{
	int i, N, M, t, ans = 1, idx = 0;
	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++) {
		scanf("%d", &t);
		check[t] = true;
	}

	dp[0] = 1, dp[1] = 1;
	for (i = 2; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];

	for (i = 1; i <= N; i++) {
		if (check[i]) {
			ans *= dp[i - idx - 1];
			idx = i;
		}
	}

	printf("%d\n", ans * dp[N - idx]);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2302
// 05 초등부 3번
// DP, 수학(곱의 법칙)
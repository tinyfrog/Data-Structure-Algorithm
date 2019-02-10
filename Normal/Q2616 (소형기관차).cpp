#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int N, psum[50001];
int dp[3][50001]; 

int main(void)
{
	int i, j, v, ans = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &psum[i]);
		psum[i] += psum[i - 1];
	}
	scanf("%d", &v);

	for (i = 0; i < 3; i++) {
		for (j = (i + 1) * v; j <= N; j++) {
			if (i == 0) dp[i][j] = max(dp[i][j - 1], psum[j] - psum[j - v]);
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - v] + psum[j] - psum[j - v]);
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2616
// 03 KOI 초등부 3번
// 부분합, DP
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, ans;
int ar[101];
bool dp[101][1000];

void cal(int idx, int sum)
{
	if (idx == N) {
		if (sum > ans) ans = sum;
		return;
	}

	if (sum + ar[idx] <= M && !dp[idx + 1][sum + ar[idx]]) {
		dp[idx + 1][sum + ar[idx]] = true;
		cal(idx + 1, sum + ar[idx]);
	}
	if (sum - ar[idx] >= 0 && !dp[idx + 1][sum - ar[idx]]) {
		dp[idx + 1][sum + ar[idx]] = true;
		cal(idx + 1, sum - ar[idx]);
	}
	return;
}

int main(void)
{
	int i, S;
	ans = -1;

	scanf("%d %d %d", &N, &S, &M);
	for (i = 0; i < N; i++) scanf("%d", &ar[i]);
	cal(0, S);

	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/1495
// 1495 기타리스트
// DP

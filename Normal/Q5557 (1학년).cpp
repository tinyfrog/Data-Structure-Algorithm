#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int N;
long long ar[101], dp[101][21];

long long cal(int idx, long long sum)
{
	if (idx == N - 2) {
		if(sum == ar[idx + 1]) dp[idx][sum] = 1;
		return dp[idx][sum];
	}

	if (dp[idx][sum] != 0) return dp[idx][sum];

	if (sum + ar[idx + 1] <= 20) dp[idx][sum] += cal(idx + 1, sum + ar[idx + 1]);
	if (sum - ar[idx + 1] >= 0) dp[idx][sum] += cal(idx + 1, sum - ar[idx + 1]);
	return dp[idx][sum];
}

int main(void)
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%lld", &ar[i]);

	printf("%lld\n", cal(0, ar[0]));
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/5557
// 11 JOI 예선 4번
// 완전 탐색
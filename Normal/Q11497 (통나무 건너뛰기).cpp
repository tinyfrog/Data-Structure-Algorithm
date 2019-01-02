#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int ar[10001], temp[10001];

int main(void)
{
	int i, T, N, ans;
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d", &N);
		for (i = 0; i < N; i++) scanf("%d", &ar[i]);
		sort(&ar[0], &ar[N]);
		for (i = 2; i < N; i += 2) ans = max(ans, ar[i] - ar[i - 2]);
		for (i = 3; i < N; i += 2) ans = max(ans, ar[i] - ar[i - 2]);
		ans = max(ans, ar[N - 1] - ar[N - 2]);
		ans = max(ans, ar[N - 1] - ar[N - 3]);
		printf("%d\n", ans);
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11497
// 15 대전 E번
// 수학
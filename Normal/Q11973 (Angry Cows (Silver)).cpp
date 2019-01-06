#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int N, K, ar[50002];

int cal(int n)
{
	int i, num = 1, lim = ar[0] + 2 * n;
	for (i = 1; i < N; i++) {
		if (lim < ar[i]) {
			num++;
			lim = ar[i] + 2 * n;
		}
	}
	return num;
}

int main(void)
{
	int i, l, r, mid, n, ans = 1;
	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++) scanf("%d", &ar[i]);
	sort(&ar[0], &ar[N]);

	l = 1, r = ar[N - 1] - ar[0];
	while (l <= r)
	{
		mid = (l + r) / 2;
		n = cal(mid);
		if (n <= K) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11973
// USACO 16/01 Silver 1번
// 이진탐색
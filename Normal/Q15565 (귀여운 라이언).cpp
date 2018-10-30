#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Ryan[1000001];
int N, K;

bool can(int num)
{
	int i, t = 0;
	for (i = 0; i < num; i++) {
		if (Ryan[i] == 1) ++t;
	}
	if (t >= K) return true;
	bool flag = false;
	for (i = num; i < N; i++) {
		if (Ryan[i] == 1) ++t;
		if (Ryan[i - num] == 1) --t;
		if (t >= K) {
			flag = true;
			break;
		}
	}
	return flag;
}

int main(void)
{
	int i, ans;
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++) scanf("%d", &Ryan[i]);

	if (!can(N)) printf("-1\n"); // 불가능
	else {
		int start = 1, end = N, mid;
		while (start <= end) {
			mid = (start + end) / 2;
			if (can(mid)) {
				ans = mid;
				end = mid - 1;
			}
			else start = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}

// 문제 : https://www.acmicpc.net/problem/15565
// 슬라이딩 윈도우 + 이진탐색
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

#define big 987654321

using namespace std;

int N, ans, ar[1001], visit[1001];

void jump(int idx, int cnt)
{
	if (idx >= N - 1) {
		ans = min(ans, cnt);
		return;
	}

	int i;
	for (i = 1; i <= ar[idx]; i++) {
		if (idx + i >= N - 1) {
			jump(idx + i, cnt + 1);
			break;
		}
		if (cnt + 1 < visit[idx + i]) {
			visit[idx + i] = cnt + 1;
			jump(idx + i, cnt + 1);
		}
	}
	return;
}


int main(void)
{
	int i;
	ans = big;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", ar + i);
		visit[i] = big;
	}

	visit[i] = 0;
	jump(0, 0);

	printf("%d\n", (ans == big) ? -1 : ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11060
// 11060 점프 점프
// DP
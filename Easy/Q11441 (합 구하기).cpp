#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int ans[100001];

int main(void)
{
	int i, N, M, a, b;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d", &ans[i]);
		ans[i] += ans[i - 1];
	}

	scanf("%d", &M);

	for (i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", ans[b] - ans[a - 1]);
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11441
// 11441 합 구하기
// 구간 합
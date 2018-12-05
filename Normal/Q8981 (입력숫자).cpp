#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, ans[31];

int main(void)
{
	int i, t, idx;
	bool flag = true;

	scanf("%d", &N);

	idx = 0;
	for (i = 0; i < N; i++) {
		scanf("%d", &t);
		if (t == 0) {
			flag = false;
			continue;
		}

		while (ans[idx] != 0) idx = (idx + 1) % N;
		ans[idx] = t;
		idx = (idx + t) % N;
	}

	if (!flag) {
		printf("-1\n");
		return 0;
	}

	printf("%d\n", N);

	for (i = 0; i < N; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/8981
// 13 중등부 2번
// 코드분석
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, j, t, N;
	long long sum = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &t);
			sum += t;
		}
	}
	printf("%lld\n", sum);
}

// 출처 : https://www.acmicpc.net/problem/16504
// 수학
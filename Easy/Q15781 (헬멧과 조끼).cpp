#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, N, M;
	scanf("%d %d", &N, &M);

	long long a1 = 0, a2 = 0;
	long long t;

	for (i = 0; i < N; i++) {
		scanf("%lld", &t);
		if (t > a1) a1 = t;
	}
	for (i = 0; i < M; i++) {
		scanf("%lld", &t);
		if (t > a2) a2 = t;
	}

	printf("%lld\n", a1 + a2);
	return 0;
}

// 문제: https://www.acmicpc.net/problem/15781

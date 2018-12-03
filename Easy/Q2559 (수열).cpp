#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ar[100001];

int max(int a, int b)
{
	return (a >= b) ? a : b;
}

int main(void)
{
	int i, N, K, t, sum = 0;
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++) scanf("%d", &ar[i]);

	for (i = 0; i < K; i++) sum += ar[i];
	t = sum;
	for (i = 1; i <= N - K; i++) {
		t -= ar[i - 1];
		t += ar[i + K - 1];
		sum = max(t, sum);
	}
	printf("%d\n", sum);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2559
// 11 초등부 1번 수열
// 구현 (슬라이딩 윈도우)
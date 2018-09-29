#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ar[1001], dp[1001];

inline int m_max(int a, int b)
{
	return (a > b) ? a : b;
}

int main(void) {
	int i, j, N, answer = 0;
	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		scanf("%d", &ar[i]);
		dp[i] = ar[i];
	}

	for (i = 1; i < N; i++) {
		for (j = 0; j < i; j++) {
			if (ar[i] > ar[j]) dp[i] = m_max(dp[i], dp[j] + ar[i]);
		}
	}

	for (i = 0; i < N; i++) {
		if (dp[i] > answer) answer = dp[i];
	}
	printf("%d\n", answer);
	return 0;
}

// ¹®Á¦ : https://www.acmicpc.net/problem/11055
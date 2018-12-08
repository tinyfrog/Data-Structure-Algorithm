#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ar[2001];
int dp[2001][2001]; // x�� y������ �Ӹ��������

int main(void)
{
	int i, N, M, a, b, count;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &ar[i]);
		dp[i][i] = 1; // �Ӹ�����̴�.
		if (i > 0 && ar[i - 1] == ar[i]) dp[i - 1][i] = 1; // �Ӹ�����̴�. 
	}

	count = 2;
	while (count < N)
	{
		for (i = 0; i < N - 1; i++) {
			if (i + count >= N) break;
			if (ar[i] == ar[i + count] && dp[i + 1][i + count - 1] == 1) dp[i][i + count] = 1;
		}
		count++;
	}

	scanf("%d", &M); 
	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a-1][b-1]);
	}

	return 0;
}

// ��ó : https://www.acmicpc.net/problem/10942
// 10942 �Ӹ����
// DP
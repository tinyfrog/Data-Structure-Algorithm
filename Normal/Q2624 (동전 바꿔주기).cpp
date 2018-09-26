#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int coin[101][2], dp[10001];

int main(void)
{
	int i, j, k, num, sum, T, s, temp; 
	scanf("%d %d", &T, &s);

	for (i = 0; i < s; i++) scanf("%d %d", &coin[i][0], &coin[i][1]);

	dp[0] = 1; // 지불 X는 한가지 방법
	for (i = 0; i < s; i++) {
		num = coin[i][1];
		for (j = T - coin[i][0]; j >= 0; j--) {
			if (!dp[j]) continue;

			for (k = 1, sum = coin[i][0]; k <= num; k++, sum += coin[i][0]) {
				temp = j + sum;
				if (temp > T) break;
				dp[temp] += dp[j];
			}
		}
	}

	printf("%d\n", dp[T]);
	return 0;
}

// 문제 : https://www.acmicpc.net/problem/2624
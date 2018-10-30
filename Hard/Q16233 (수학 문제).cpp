#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cal(int N)
{
	int sum = 0;
	while (N != 0) {
		sum += N % 10;
		N /= 10;
	}
	return sum;
}

int dp[100001];
int ans[1000001];

int main(void)
{
	int i, T, N, X, Xsum, timer;
	bool flag;

	for (i = 1; i < 100000; i++) dp[i] = cal(i);
	dp[100000] = 1;

	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d", &N);
		X = N;
		flag = true;
		timer = 1;
		while (true)
		{
			if (timer >= 100) break;
			Xsum = dp[X/100000] + dp[X%100000];
			if (X > Xsum + N) {
				flag = false;
				break;
			}
			else if (X == Xsum + N) break;
			else {
				++X;
				++timer;
			}
		}
		if (flag) ans[i] = X;
		else ans[i] = -1;
	}
	for (i = 0; i < T; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

// ¹®Á¦ : https://www.acmicpc.net/problem/16233
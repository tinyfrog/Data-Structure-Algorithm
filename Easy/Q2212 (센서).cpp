#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int N, K;
int ar[10001], bt[10001];

int main(void)
{
	int i, lim, sum = 0;
	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++) scanf("%d", &ar[i]);
	sort(&ar[0], &ar[N]);

	for (i = 1; i < N; i++) bt[i-1] = ar[i] - ar[i-1];
	sort(&bt[0], &bt[N - 1]);

	for (i = 0; i < N - K; i++) sum += bt[i];

	printf("%d\n", sum);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2212
// 2212 센서
// 그리디
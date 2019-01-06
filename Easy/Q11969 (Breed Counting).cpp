#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int N, Q;
int hsum[100001], gsum[100001], jsum[100001];

int main(void)
{
	int i, t, v;
	scanf("%d %d", &N, &Q);

	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		switch (t)
		{
		case 1:
			hsum[i]++;
			break;
		case 2:
			gsum[i]++;
			break;
		case 3:
			jsum[i]++;
			break;
		}
		hsum[i] += hsum[i - 1];
		gsum[i] += gsum[i - 1];
		jsum[i] += jsum[i - 1];
	}

	for (i = 0; i < Q; i++) {
		scanf("%d %d", &t, &v);
		printf("%d %d %d\n", hsum[v] - hsum[t - 1], gsum[v] - gsum[t - 1], jsum[v] - jsum[t - 1]);
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11969
// USACO 15/12 Silver 3번
// 구현
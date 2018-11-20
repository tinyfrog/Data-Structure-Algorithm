#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int acr[101], ver[101];

int max(int a, int b)
{
	return (a >= b) ? a : b;
}

int main(void)
{
	int i, a, b, N, t1, t2, max1, max2, tlen;
	scanf("%d %d", &a, &b);
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &t1, &t2);
		if (t1 == 0) acr[t2] = 1;
		else if (t1 == 1) ver[t2] = 1;
	}

	max1 = 0, max2 = 0, tlen = 0;
	for (i = 1; i <= b; i++) {
		tlen++;
		if (acr[i] == 1) {
			max1 = max(max1, tlen);
			tlen = 0;
		}
	}
	max1 = max(max1, tlen);

	tlen = 0;
	for (i = 1; i <= a; i++) {
		tlen++;
		if (ver[i] == 1) {
			max2 = max(max2, tlen);
			tlen = 0;
		}
	}
	max2 = max(max2, tlen);

	printf("%d\n", max1 * max2);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2628
// 구현
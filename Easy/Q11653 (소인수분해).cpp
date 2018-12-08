#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	int i, N;
	scanf("%d", &N);

	for (i = 2; i <= sqrt(N); i++) {
		while (!(N % i)) {
			printf("%d\n", i);
			N /= i;
		}
	}

	if (N > 1) printf("%d\n", N);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11653
// 11653 소인수분해
// 수학
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int main(void)
{
	int i, a, b, N, sum = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		sum += a * b;
	}

	printf("%d\n", sum);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/14730
// 14730 미분(Small)
// 수학
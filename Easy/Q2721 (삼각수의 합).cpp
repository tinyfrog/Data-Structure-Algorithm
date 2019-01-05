#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int main(void)
{
	int T;
	long long N;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld", &N);
		printf("%lld\n", (((N * N * (N + 1) * (N + 1)) / 4) + ((N * (N + 1) * (2 * N + 1)) / 2) + N * (N + 1)) / 2);
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2721
// 2721 삼각수의 합
// 수학
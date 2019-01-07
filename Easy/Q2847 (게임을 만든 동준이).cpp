#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int ar[101];

int main(void)
{
	int i, N, ans = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &ar[i]);

	for (i = N - 2; i >= 0; i--) {
		if (ar[i] >= ar[i + 1]) {
			ans += (ar[i] - ar[i + 1]) + 1;
			ar[i] -= (ar[i] - ar[i + 1]) + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2847
// 10 COCI #6 3번
// 구현
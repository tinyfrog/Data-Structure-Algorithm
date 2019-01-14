#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int ar[1001];

int main(void)
{
	int i, N;
	scanf("%d", &N);

	for (i = 0; i < N; i++) scanf("%d", &ar[i]);

	int start = ar[0], t = ar[0], len = 0;
	for (i = 1; i < N; i++) {
		if (t >= ar[i]) {
			len = max(t - start, len);
			start = ar[i], t = ar[i];
		}
		else t = ar[i];
	}
	len = max(t - start, len);
	printf("%d\n", len);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2846
// 10 COCI #6 2번
// 구현
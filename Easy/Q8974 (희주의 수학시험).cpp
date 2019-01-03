#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int ar[1002], sum[1002];

int main(void)
{
	int i = 1, a, l, k, t = 1;

	while (i <= 1000) {
		a = 0;
		while (a < t) {
			ar[i++] = t, ++a;
			if (i > 1000) break;
		}
		t++;
	}

	for (i = 1; i <= 1000; i++) sum[i] = sum[i - 1] + ar[i];

	scanf("%d %d", &l, &k);
	printf("%d\n", sum[k] - sum[l - 1]);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/8974
// 8974 희주의 수학시험
// 반복문
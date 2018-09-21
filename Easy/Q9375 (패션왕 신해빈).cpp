#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int ar[8], pw[4096];

int main(void)
{
	int idx, T, N, i, j, temp;
	scanf("%d", &T);

	while (T--)
	{
		for (i = 0; i < 31; i++) ar[i] = 0;
		for (i = 0; i < 4096; i++) pw[i] = -1;
		idx = 0;

		scanf(" %d", &N);
		for (i = 0; i < N; i++) {
			char t1[21], t2[21];
			scanf(" %s %s", &t1, &t2);

			unsigned long sum = 5381;
			for (j = 0; t2[j]; j++) sum = (((sum << 5) + sum) + (t2[j] - 'a')) % 4096;
			temp = sum % 4096;

			if (pw[temp] == -1) {
				pw[temp] = idx;
				++ar[idx];
				++idx;
			}
			else ++ar[pw[temp]];
		}

		unsigned long ans = 1;
		for (i = 0; i < idx; i++) ans *= (ar[i] + 1);
		printf("%ld\n", ans - 1);
	}
	return 0;
}

// 문제: https://www.acmicpc.net/problem/9375

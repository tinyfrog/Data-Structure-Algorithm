#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>

using namespace std;

int N, L;
int ar[1001];

int main(void)
{
	int i, j, val, idx = 0, ans = 0;
	scanf("%d %d", &N, &L);
	for (i = 0; i < N; i++) scanf("%d", &ar[i]);
	sort(&ar[0], &ar[N]);

	for (i = 0; i < N; i++) {
		val = ar[idx] + L - 1;
		for (j = idx + 1; j < N; j++) {
			if (ar[j] <= val) idx = j;
			else break;
		}
		i = idx;
		idx++, ans++;
	}
	printf("%d\n", ans);
}

// 출처 : https://www.acmicpc.net/problem/1449
// 1449 수리공 항승
// 그리디
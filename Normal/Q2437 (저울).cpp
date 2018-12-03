#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ar[1001], temp[1001];

void sort(int s, int e)
{
	if (s >= e) return;
	int i, j, tidx, mid = (s + e) / 2;

	sort(s, mid);
	sort(mid + 1, e);

	i = s, j = mid + 1, tidx = s;
	while (i <= mid && j <= e) temp[tidx++] = (ar[i] < ar[j]) ? ar[i++] : ar[j++];
	while (i <= mid) temp[tidx++] = ar[i++];
	while (j <= e) temp[tidx++] = ar[j++];

	for (i = s; i <= e; i++) ar[i] = temp[i];
	return;
}

int main(void)
{
	int i, N, ans, sum = 1;
	scanf("%d", &N);

	for (i = 0; i < N; i++) scanf("%d", &ar[i]);
	sort(0, N - 1);

	for (i = 0; i < N; i++) {
		if (sum < ar[i]) {
			ans = sum;
			break;
		}
		sum += ar[i];
	}

	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2437
// 11 초등부 3번 저울
// 수학(그리디)
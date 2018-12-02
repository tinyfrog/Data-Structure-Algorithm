#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long ar[100001];
long ans[2];
int N;

long dit(long a)
{
	return (a >= 0) ? a : -a;
}

long biSearch(long find)
{
	int mid, left = 0, right = N;
	while (left + 1 <= right) {
		mid = (left + right) / 2;
		if (ar[mid] == find) return mid;
		else if (ar[mid] < find) left = mid + 1;
		else right = mid;
	}
	return mid;
}

int main(void)
{
	int i, idx;
	long t, val, cmp = 2000000001;

	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%ld", &ar[i]);

	for (i = 0; i < N; i++) {
		idx = biSearch(-ar[i]); // ���� 0�� ����� �� �� �ִ� �ε��� ã��
		if (i == idx) continue; // ���� �� �ΰ��� �ȵ�

		val = dit(ar[i] + ar[idx]);
		if (val < cmp) {
			cmp = val;
			if (ar[i] < ar[idx]) {
				ans[0] = ar[i], ans[1] = ar[idx];
			}
			else {
				ans[0] = ar[idx], ans[1] = ar[i];
			}
		}
	}

	printf("%ld %ld\n", ans[0], ans[1]);
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/2467
// 2010 �ʵ�� 1��
// ���� Ž��
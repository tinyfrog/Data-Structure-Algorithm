#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ar[10001];

int main(void)
{
	int i, j, N, t;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &t);
		++ar[t];
	}

	for (i = 1; i <= 10000; i++) {
		for (j = 0; j < ar[i]; j++) printf("%d\n", i);
	}
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/10989
// 10989 �� �����ϱ� 3
// ���� (Count sort)
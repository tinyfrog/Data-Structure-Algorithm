#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char a[2000001];

int main(void)
{
	int i, k;
	scanf("%d", &k);

	for (i = 0; i < k; i++) a[i] = '1';
	for (i = k; i < 2*k-1; i++) a[i] = '0';
	printf("%s\n", a);
	return 0;
}

// 문제: https://www.acmicpc.net/problem/8741

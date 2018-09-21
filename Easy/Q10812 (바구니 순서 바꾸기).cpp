#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int answer[101];
int temp[101];

int main(void)
{
	int i, j, N, M;
	int a, b, c, d;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++) answer[i] = i;
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		d = a;
		for (j = c; j <= b; j++) temp[d++] = answer[j];
		for (j = a; j < c; j++) temp[d++] = answer[j];
		for (j = a; j <= b; j++) answer[j] = temp[j];
	}
	for (i = 1; i <= N; i++) printf("%d ", answer[i]);
	printf("\n");
	return 0;
}

// https://www.acmicpc.net/problem/10812

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char str[31];

int main(void)
{
	int i, N;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf(" %[^\n]s", str);
		if(str[0] >= 'a' && str[0] <= 'z') str[0] = (str[0] + 'A' - 'a');
		printf("%s\n", str);
	}
	return 0;
}

// ���� : https://www.acmicpc.net/problem/4458
// ���� ���� �Է� �ޱ� + ���ڿ� ó��
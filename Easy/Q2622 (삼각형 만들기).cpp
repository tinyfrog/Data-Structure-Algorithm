#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, j, N, ans = 0;
	scanf("%d", &N);

	for (i = N/3; i >= 1; i--) {
		for (j = (N-i)/2; j >= i; j--) { // ���� �� ��
			if (i + j > N - i - j) ++ans;
			else break;
		}
	}

	printf("%d\n", ans);
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/2622
// ���� (N^2, N ����)
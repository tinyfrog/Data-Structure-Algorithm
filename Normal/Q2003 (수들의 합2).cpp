#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ar[10001];

int main(void)
{
	int i, N, M, idx1, idx2, sum, answer = 0; 
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) scanf("%d", &ar[i]);

	idx1 = 0, idx2 = 0, sum = 0;
	while (true) {
		if (sum == M) answer++;

		if (sum >= M) sum -= ar[idx1++];
		else if (idx2 == N) break; // �������Ͱ� ������ ���� �� (M���� �������� �������� ����)
		else sum += ar[idx2++];
	}
	printf("%d\n", answer);
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/2003
// 2003 ������ �� 2
// �����̵� ������
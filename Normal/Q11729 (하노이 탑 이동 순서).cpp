#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void Hanoi(int n, int a, int b, int c) { // 1 ~ n ���̸� a���� b�� �ű�
	if (n == 1) {
		printf("%d %d\n", a, b);
		return;
	}
	Hanoi(n - 1, a, c, b);
	Hanoi(1, a, b, c); // ���� �Ʒ��� �ִ� ���� a -> b�� �ű�
	Hanoi(n - 1, c, b, a);
}

int main(void)
{
	int N;
	scanf("%d", &N);
	printf("%d\n", (int)pow(2, N) - 1);

	Hanoi(N, 1, 3, 2);
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/11729
// 11729 �ϳ��� ž �̵� ����
// ��������(���)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max(int x, int y) {
	return (x >= y) ? x : y;
}

int main(void)
{
	char S;
	int N, D, M, ans = 0, mario[2] = { 0 }, front = 0;
	scanf("%d %d", &N, &D);
	while (N--) {
		scanf(" %c-%d", &S, &M);
		ans = max(ans, M - mario[front]); // �ռ� ���� �������� M ������ �Ÿ�
		mario[front] = M; // �ռ� ���� �������� M���� �̵�
		front = 1 - front; // �� �������� �ٲ�
		if (S == 'W') mario[front] = M; // �����丷�̸� �տ� �ִ� �������� M���� �̵�
	}
	ans = max(ans, D - mario[front]); // ������
	printf("%d\n", ans);
}

// �Դ� ���ƿ��� ���̽��� �̷��� Ǫ�� ����� �����غ���
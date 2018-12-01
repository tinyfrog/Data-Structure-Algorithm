#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int digits(int x) {
	int d = 1, power = 10;
	while (power <= x) {
		d++;
		power *= 10;
	}
	return d;
}

int main() {
	int i, n, count, a[10001];
	int polly = 1;

	scanf("%d", &n);
	for (i = 0; i <= n; i++) scanf("%d", &a[i]);
	
	count = 1; // X �ѹ� ��������
	for (i = 1; i < n; i++) {
		if (a[i] == 0) count += 2; // x, X �������� (�������� ����)
		else count += (3 + digits(a[i])); // x, X, +, ���� ��������
	}
	
	if (a[n] == 0) ++count; // = ��������
	else count += (2 + digits(a[n])); // +, ������ ����, = ��������

	printf("%d\n", count);
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/2200
// greedy + ����
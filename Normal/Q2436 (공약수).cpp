#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main(void)
{
	long long a, b, t, i, a1, a2, t1, t2, g;
	scanf("%lld %lld", &a, &b);

	t = a * b;
	for (i = 2; i * i <= t; i++) { // �� ���� �ٸ��ٴ� ���� ����
		if (t % i == 0) {
			t1 = i, t2 = t / i;
			g = gcd(t1, t2);
			if (g == a && (t1 * t2) / g == b) { // �ִ������� �Է¹��� ���� �������� üũ
				a1 = t1, a2 = t2;
			}
		}
	}
	
	printf("%lld %lld\n", a1, a2);
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/2436
// 11 ���� 1�� �����
// ���� (+ �ڷ��� ����)
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include <cstdio>

int main(void)
{
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	printf("%.6f\n", (float(a - e) * float(c - d) * float(b)) / (d * e + (a - e) * (c - d)));
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/16482
// 16482 �������� ������!
// ü���� ����
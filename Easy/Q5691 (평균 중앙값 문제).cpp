#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int main(void)
{
	long a, b;

	while (true)
	{
		scanf("%ld %ld", &a, &b);
		if (a == 0 && b == 0) break;
		printf("%ld\n", 2 * a - b);
	}
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/5691
// 5691 ��� �߾Ӱ� ����
// ����
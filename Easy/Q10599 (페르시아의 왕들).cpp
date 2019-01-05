#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int a, b, c, d;
	while (true)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a == 0 && b == 0 && c == 0 && d == 0) break;
		printf("%d %d\n", min(c, d) - max(a, b), max(c, d) - min(a, b));
	}
	return 0;
}

// 출처: https://www.acmicpc.net/problem/10599
// 10599 페르시아의 왕들
// 수학
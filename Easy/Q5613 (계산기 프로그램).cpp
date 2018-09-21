#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	long long a, ans;
	scanf("%lld", &ans);
	while (true)
	{
		char t[2];
		scanf(" %s", &t);
		if (t[0] == '=') break;

		scanf(" %lld", &a);
		if (t[0] == '+') ans += a;
		else if (t[0] == '-') ans -= a;
		else if (t[0] == '*') ans *= a;
		else if (t[0] == '/') ans /= a;
	}
	printf("%lld\n", ans);
	return 0;
}

// 문제: https://www.acmicpc.net/problem/5613

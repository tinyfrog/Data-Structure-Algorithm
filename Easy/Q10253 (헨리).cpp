#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main(void)
{
	int T;
	int a, b, div;
	int t1, t2;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &a, &b);
		t1 = 1;
		while (a != 1)
		{
			++t1;
			if (b / t1 < a) {
				t2 = b;
				a *= t1;
				b *= t1;
				a -= t2;
				div = gcd(a, b);
				a /= div;
				b /= div;
			} 
		}
		printf("%d\n", b);
	}
}

문제: https://www.acmicpc.net/problem/10253

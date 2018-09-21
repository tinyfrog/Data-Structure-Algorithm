#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	int n, m, div;
	scanf("%d:%d", &n, &m);

	div = gcd(n, m);
	printf("%d:%d\n", n / div, m / div);
	return 0;
}
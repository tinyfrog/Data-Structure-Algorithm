#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int com(int n, int k)
{
	if (n == k || k == 0) return 1;
	if (k == 1) return n;
	if (n - k < k) k = n - k;
	
	long long int a = n, b = 1, ans = 1;
	while (k--)
	{
		ans *= a;
		ans /= b;
		--a, ++b;
	}
	return ans;
}

int main(void)
{
	int n, k;
	while (true)
	{
		scanf("%d %d", &n, &k);
		if (n == 0 && k == 0) break;
		printf("%d\n", com(n, k));
	}

	return 0;
}